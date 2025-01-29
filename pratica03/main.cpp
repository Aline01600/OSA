#include<iostream>
#include<vector>
#include<fstream>
#include "registro.hpp"
int main(){
    
    vector<Registro>pessoas;
    Registro reg;
     reg.nomeArquivo = "Dados.txt";
     pessoas = reg.lerDadostxt();
    // temos um vetor pessoas

    return 0;
}