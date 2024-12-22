#ifndef BUFFER_H
#define BUFFER_H

#include "Registro.hpp"
#include <fstream> 

using namespace std;

class Buffer{
    public:
        void escreverRegistroFixo(Registro reg, std::ofstream& out);
        Registro lerRegistroFixo(ifstream& in);  
};

#endif
