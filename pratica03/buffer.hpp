#ifndef BUFFER_HPP
#define BUFFER_HPP
#include "registro.hpp"

using namespace std;

class Buffer{
public:
    string nomeArquivo;

    vector<Registro> lerDadostxt();
    void adicionarRegistroVariavel(Registro reg);
    vector<Registro> lerRegistrosVariavel();

    void escreverRegistroVariavel(Registro reg, ofstream& out);
    Registro lerRegistroVariavel(ifstream& in);
};

#endif