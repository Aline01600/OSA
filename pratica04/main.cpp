#include <iostream>
#include <vector>
#include "buffer.hpp"
#include "indice.hpp"

using namespace std;

int main(){

    Buffer buffer;
    buffer.nomeArquivo = "booksDataset.csv";
    buffer.nomeArquivoBin = "livros.bin";
    
    vector<Registro> livros;
    livros = buffer.lerDadosCSV();
    for(const auto& reg: livros){
        buffer.escreverRegistroVariavel(reg);
    }

    buffer.arvore.Travessia_InOrder();
   /* vector<Registro> registros;
    registros = buffer.lerRegistroVariavel();

    for(const auto& reg : registros){
        
        cout << reg.ID << " " << reg.titulo << " " <<
        reg.autor << " " << reg.anoPublicacao << " " <<
        reg.categoria << " " << reg.genero << endl;
    }*/
    return 0;
}