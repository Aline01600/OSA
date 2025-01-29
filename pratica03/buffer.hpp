#ifndef BUFFER_HPP
#define BUFFER_HPP
#include "registro.hpp"

using namespace std;

class Buffer{
public:
    void escreverRegistroFixo(Registro reg, ofstream& out);
    Registro lerRegistroFixo(ifstream& in);
};

#endif