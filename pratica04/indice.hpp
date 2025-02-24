#ifndef INDICE_HPP
#define INDICE_HPP

#include <string>
#include<iostream>
using namespace std;

class Indice{
    public:
    int ID_livro;
    long long endereco; 
    string buffer;
    
    string packfixed();
    void unpackfixed(string &buffer); 

    bool operator<(const Indice &outro) const {
        return this->ID_livro < outro.ID_livro;
    }
    
    bool operator>(const Indice &outro) const {
        return this->ID_livro > outro.ID_livro;
    }
    
    bool operator==(const Indice &outro) const {
        return this->ID_livro == outro.ID_livro;
    }
    
};
ostream& operator<<(ostream& os, const Indice& indice);

#endif