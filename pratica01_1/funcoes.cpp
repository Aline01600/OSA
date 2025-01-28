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
    
    char ch;
    while (!arquivo.eof()){
        arquivo.get(ch);
        cout << ch;
    }
    arquivo.close();
}
