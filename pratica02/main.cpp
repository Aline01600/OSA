#include<iostream>
#include "arquivo.hpp"
#include<vector>
#include<fstream>
int main(){

    vector<Registro>pessoas;
    Arquivo arquivo;
    for(int i = 1; i<=5; ++ i){
        arquivo.nomeArquivo = "Nomes_Idades_" + to_string(i) + ".csv";
        pessoas = arquivo.lerRegistrosCSV();
    
        for(const auto& reg : pessoas){
            arquivo.adicionarRegistroFixo(reg);
        }

        vector<Registro> registros;
        registros = arquivo.lerRegistrosFixo();

        for(const Registro& reg : registros){
            cout << reg.nome << " " << reg.idade << endl;
        }
        
        //os codigos abaixo são para testar leitura e escrita dos arquivos
        //separador entre os testes
        cout <<"-----------------------------------------\n";
        //limpa os vetores e remove o arquivo após cada teste
        pessoas.clear();
        registros.clear();
        remove("registros.bin");
    }
    
    return 0;
}