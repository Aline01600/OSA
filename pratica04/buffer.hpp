#ifndef BUFFER_HPP
#define BUFFER_HPP
#include<vector>
#include"registro.hpp"
#include"indice.hpp"
#include "arvore.hpp"


using namespace std;

class Buffer{
    public:
    string nomeArquivo;
    string nomeArquivoBin;
    string buffer;

    vector<Registro>lerDadosCSV();

    void escreverRegistroVariavel(Registro reg);
    vector<Registro> lerRegistroVariavel();
    
    void escreverRegistroFixo(int reg, long long endereco);
    vector<Indice> lerRegistroFixo();

};

#endif