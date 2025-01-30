#ifndef BUFFER_HPP
#define BUFFER_HPP
#include "registro.hpp"

using namespace std;

class Buffer{
public:
    string nomeArquivo;
    string nomeArquivoBin;
    string buffer;
    vector<Registro> lerDadostxt();
    void escreverRegistroVariavel(Registro reg);
    Registro lerRegistroVariavel(ifstream& in);
};

#endif