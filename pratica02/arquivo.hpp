#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP
#include<string>
#include<vector>
#include "buffer.hpp"

using namespace std;

class Arquivo{
public:
    string nomeArquivo;
    vector<Registro> lerRegistrosCSV();
    void adicionarRegistroFixo(Registro reg);
    vector<Registro> lerRegistrosFixo();
};

#endif