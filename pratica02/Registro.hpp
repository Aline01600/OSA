#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include <vector>

using namespace std;

struct Registro {

    string nome;
    int idade;
    string packFixed();
    void unpackFixed(string& buffer);
    
};

#endif