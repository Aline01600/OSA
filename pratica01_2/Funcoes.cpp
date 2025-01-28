#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<sstream>
#include"Funcoes.hpp"

using namespace std;
void Pessoa::ler_arquivo(const string& nomeArquivo, vector<Pessoa>& pessoas){
    ifstream arquivo(nomeArquivo);
    if(!arquivo.is_open()){
        cerr << "Erro ao abrir arquivo: " << nomeArquivo << endl;
        return;
    }
    
    string linha;
    getline(arquivo, linha);
    while (getline(arquivo, linha)){
        stringstream linhaStream(linha);
        string campo;
        Pessoa pessoa;
        //ler e converter nome tamanho fixo
        if (getline(linhaStream, campo, ',')){
            strncpy(pessoa.nome, campo.c_str(), sizeof(pessoa.nome) -1);
            pessoa.nome[sizeof(pessoa.nome)-1] = '\0';
        }
        //ler e converter idade tamanho fixo
        if(getline(linhaStream, campo, ',')){
            pessoa.idade = stoi(campo);
        }
        pessoas.push_back(pessoa);

    }
    arquivo.close();

}

void Pessoa::exibir(vector<Pessoa> pessoas){
     for(const Pessoa& p : pessoas){
        cout << "Nome: " << p.nome << ", Idade: " << p.idade << endl;
     }
}