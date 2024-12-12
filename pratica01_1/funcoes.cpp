#include <iostream>
#include <fstream>
#include <sstream>
#include "funcoes.h"
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
        if (getline(ss, nome)) {
                cout << nome << endl;
        }
    }
    arquivo.close();
}
