#ifndef INDICE_HPP
#define INDICE_HPP
#include<string>

using namespace std;

class Indice{
    public:
    int ID_livro;
    int endereco;   
    string nomeIndicesBin; 
    int bufferIndices;
    int packfixed();
    void unpackfixed(int valor);
};

#endif