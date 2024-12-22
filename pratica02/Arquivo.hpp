#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include <vector>
#include "Registro.hpp"

using namespace std;

class Arquivo{
    public:
        string nomeDoArquivo;

        vector<Registro> lerRegistrosCSV();
        void adicionarRegistroFixo(Registro reg);
        vector<Registro> lerRegistrosFixo();
};

#endif