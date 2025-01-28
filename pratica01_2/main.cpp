#include<iostream>
#include<string>
#include<vector>
#include "Funcoes.hpp"

using namespace std;

int main(){

    vector<Pessoa> pessoas;
    Pessoa p;
    
    string nomeArquivo = "Nomes_Idades_1.csv";
    p.ler_arquivo(nomeArquivo, pessoas);
    p.exibir(pessoas);
    cout << "-------------------------------------------------------" << endl;

    pessoas.clear();
    nomeArquivo = "Nomes_Idades_2.csv";
    p.ler_arquivo(nomeArquivo, pessoas);
    p.exibir(pessoas);
    cout << "-------------------------------------------------------" << endl;

    pessoas.clear();
    nomeArquivo = "Nomes_Idades_3.csv";
    p.ler_arquivo(nomeArquivo, pessoas);
    p.exibir(pessoas);
    cout << "-------------------------------------------------------" << endl;

    pessoas.clear();
    nomeArquivo = "Nomes_Idades_4.csv";
    p.ler_arquivo(nomeArquivo, pessoas);
    p.exibir(pessoas);
    cout << "-------------------------------------------------------" << endl;
    
    pessoas.clear();
    nomeArquivo = "Nomes_Idades_5.csv";
    p.ler_arquivo(nomeArquivo, pessoas);
    p.exibir(pessoas);
    
    return 0;
}