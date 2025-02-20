#include <iostream>
#include <vector>
#include "buffer.hpp"
#include "indice.hpp"
#include "registro.hpp"

using namespace std;

int main(){

    Buffer buffer;
    buffer.nomeArquivo = "booksDataset.csv";
    buffer.nomeArquivoBin = "livros.bin";
    
    vector<Registro> livros = buffer.lerDadosCSV();
   
    for(const auto& reg: livros){
        buffer.escreverRegistroVariavel(reg);
    }

    vector<Registro> registros;
    registros = buffer.lerRegistroVariavel();

    /*for(const auto& reg : registros){
        
        cout << reg.ID << " " << reg.titulo << " " <<
        reg.autor << " " << reg.anoPublicacao << " " <<
        reg.categoria << endl;
    }*/

    vector<Indice> indices;
    indices = buffer.lerRegistroFixo();
    for(const auto& reg : indices){
        cout << reg.ID_livro <<" | "<< reg.endereco << endl;
    }

    return 0;
}