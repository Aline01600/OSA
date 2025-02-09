#include <iostream>
#include <vector>
#include "buffer.hpp"
#include "indice.hpp"

using namespace std;

int main(){

    vector<Registro> livros;
    Buffer buffer;

    buffer.nomeArquivo = "booksDataset.csv";
    livros = buffer.lerDadosCSV();

    
    buffer.nomeArquivoBin = "livros.bin";
    for(const auto& reg: livros){
        buffer.escreverRegistroVariavel(reg);
    }

    vector<Registro> registros;
    registros = buffer.lerRegistroVariavel();

    for(const auto& reg : registros){
        
        cout << reg.ID << " " << reg.titulo << " " <<
        reg.autor << " " << reg.anoPublicacao << " " <<
        reg.categoria << " " << reg.genero << endl;
    }
    return 0;
}