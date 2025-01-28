#ifndef FUNCOES_H
#define FUNCOES_H

#include<string>
#include<vector>
using namespace std;

class Pessoa{
public:
    char nome[30];
    int idade;
    void ler_arquivo(const string& nomeArquivo, vector<Pessoa>& pessoas);
    void exibir(vector<Pessoa> pessosas);
};



#endif