#ifndef REGISTRO_HPP
#define REGISTRO_HPP
#include<string>
#include<vector>

using namespace std;

class Registro{
    public:
    int ID;
    string titulo;
    string autor;
    string anoPublicacao;
    string categoria;
    string genero;

    string pack();
    void unpack(string& buffer);
};

#endif