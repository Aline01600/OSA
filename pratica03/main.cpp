#include<iostream>
#include<vector>
#include<fstream>
#include "buffer.hpp"
int main(){
    
    vector<Registro>pessoas;
    Buffer buffer;
    buffer.nomeArquivo = "Dados.txt";
    pessoas = buffer.lerDadostxt();
    
    return 0;
}