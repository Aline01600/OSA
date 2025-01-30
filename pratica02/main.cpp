#include<iostream>
#include "arquivo.hpp"
#include<vector>
#include<fstream>
int main(){

    vector<Registro>pessoas;
    Arquivo arquivo;
    
        arquivo.nomeArquivo = "Nomes_Idades_1.csv";
        pessoas = arquivo.lerRegistrosCSV();
    
        for(const auto& reg : pessoas){
            arquivo.adicionarRegistroFixo(reg);
        }

        vector<Registro> registros;
        registros = arquivo.lerRegistrosFixo();

        for(const Registro& reg : registros){
            cout << reg.nome << " " << reg.idade << endl;
        }
        
    return 0;
}