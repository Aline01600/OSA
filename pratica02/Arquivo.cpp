#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Arquivo.hpp"
#include "Buffer.hpp"

using namespace std;

vector<Registro> Arquivo::lerRegistrosCSV() {
    vector<Registro> registros;  
    ifstream arquivo(nomeDoArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeDoArquivo << endl;
        return registros;
    }

    string linha;
    getline(arquivo, linha); // Ignora a primeira linha do CSV
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string nome, idadeStr;

        if (getline(ss, nome, ',') && getline(ss, idadeStr, ',')) {
            try {
                int idade = stoi(idadeStr);  // Converte a idade para inteiro
                Registro reg;
                reg.nome = nome;  
                reg.idade = idade;
                registros.push_back(reg); 
            } catch (const invalid_argument&) {
                cerr << "Erro: idade inválida no registro " << nome << endl;
            }
        }
    }
    arquivo.close();
    return registros;
}

void Arquivo::adicionarRegistroFixo(Registro reg) {
    
    ofstream arquivo(nomeDoArquivo, ios::binary | ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo para escrita: " << nomeDoArquivo << endl;
        return;
    }

    Buffer buffer;
    buffer.escreverRegistroFixo(reg, arquivo);

    arquivo.close();
}

vector<Registro> Arquivo::lerRegistrosFixo() {
    vector<Registro> registros;

    ifstream in(nomeDoArquivo, ios::binary);
    if (!in.is_open()) {
        cerr << "Erro ao abrir o arquivo binário: " << nomeDoArquivo << endl;
        return registros;
    }

    Buffer buffer;
    try {
        while (in.peek() != EOF) {  // Verifica se não chegou ao final do arquivo
            Registro reg = buffer.lerRegistroFixo(in);
            registros.push_back(reg);
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    in.close();
    return registros;
}

