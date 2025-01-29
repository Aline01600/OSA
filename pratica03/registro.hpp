#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>
#include <vector>

using namespace std;
class Registro{
    public:
    string nome;
    string sobrenome;
    string telefone;
    string data_N;
    
    string pack();
    void unpack(string& buffer);
    
};

#endif