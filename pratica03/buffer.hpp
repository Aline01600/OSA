#ifndef BUFFER_HPP
#define BUFFER_HPP
#include "registro.hpp"

using namespace std;

class Buffer{
public:
    string nomeArquivo;

    vector<Registro> lerDadostxt();
    void adicionarRegistroFixo(Registro reg);
    vector<Registro> lerRegistrosFixo();

    void escreverRegistroFixo(Registro reg, ofstream& out);
    Registro lerRegistroFixo(ifstream& in);
};

#endif