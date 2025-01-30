#include<iostream>
#include<vector>
#include<fstream>
#include "buffer.hpp"
int main(){
    
    vector<Registro>pessoas;
    Buffer buffer;
    buffer.nomeArquivo = "Dados.txt";
    pessoas = buffer.lerDadostxt();
    
    buffer.nomeArquivoBin = "registros.bin";
    for(const auto& reg : pessoas){
        buffer.escreverRegistroVariavel(reg);
    }

    vector<Registro> registros;
    registros = buffer.lerRegistroVariavel();
    
    for(const auto& reg : registros){
        cout << reg.nome << " " << reg.sobrenome << " " <<
        reg.telefone << " " << reg.data_N << endl;
    }
    return 0;
}