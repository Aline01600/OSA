#ifndef BUFFER_HPP
#define BUFFER_HPP
#include<vector>
#include"registro.hpp"
#include"indice.hpp"
#include "arvore.hpp"


using namespace std;

class Buffer{
    public:
    string nomeArquivo;
    string nomeArquivoBin;
    string buffer;
    string nomeIndiceBin;
    ArvoreBinaria<Indice> arvore;


    vector<Registro>lerDadosCSV();

    void escreverRegistroVariavel(Registro reg);
    vector<Registro> lerRegistroVariavel();
    
    void escreverRegistroFixo(int reg, long long endereco);
    vector<Indice> lerRegistroFixo();

    void inserirIndicesArvore(const vector<Indice>& indices);
    Registro buscarRegisro(int id);

};

#endif