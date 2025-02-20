#ifndef INDICE_HPP
#define INDICE_HPP

using namespace std;

class Indice{
    public:
    int ID_livro;
    long long endereco; 
    string buffer;
    
    string packfixed();
    void unpackfixed(string &buffer); 
};

#endif