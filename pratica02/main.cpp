#include <iostream>
#include "Arquivo.hpp"

using namespace std;

int main(){
    
    Arquivo arquivo;
    arquivo.nomeDoArquivo = "Nomes_Idades_1.csv";
    vector<Registro>  registros = arquivo.lerRegistrosCSV();
    
    arquivo.nomeDoArquivo = "dados.bin";
    for(const Registro &reg: registros){
        arquivo.adicionarRegistroFixo(reg);
    }

    vector<Registro> registros_fixo = arquivo.lerRegistrosFixo();
    for (const Registro& reg : registros_fixo) {
        cout << "Nome: " << reg.nome << " | Idade: " << reg.idade << endl;
    }

    return 0;
}
