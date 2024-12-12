#include <iostream>
#include <fstream>
#include <sstream>
#include "Registro.h"
using namespace std;

void lerArquivo(const string& nomeArquivo){
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()){
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    string linha;
    getline(arquivo, linha); // ler e descartar a primeira linha
    while(getline(arquivo, linha)){
        stringstream ss(linha);
        string nome, idadeStr;
        if (getline(ss, nome, ',') && getline(ss, idadeStr, ',')) {
            try {
                int idade = stoi(idadeStr);  // Converte idade para inteiro
                cout << nome << ", " << idade << endl; // Exibe o registro durante a leitura
            } catch (const invalid_argument&) {
                cerr << "Erro: idade inválida no registro " << nome << endl;
            }
        }
    }
    arquivo.close();
}
