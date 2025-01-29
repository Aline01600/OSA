#ifndef REGISTRO_HPP
#define REGISTRO_HPP

#include <string>
#include <vector>

using namespace std;
class Registro{
    public:
    string nomeArquivo;
    string nome;
    string sobrenome;
    string telefone;
    string data_N;
    
    vector<Registro> lerDadostxt();
    void adicionarRegistroFixo(Registro reg);
    vector<Registro> lerRegistrosFixo();

    string packFixed();
    void unpackFixed(string& buffer);
    
};

#endif