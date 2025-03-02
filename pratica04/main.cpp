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
    buffer.nomeIndiceBin = "indice.bin";
    
    vector<Registro> livros = buffer.lerDadosCSV();
   
    for(const auto& reg: livros){
        buffer.escreverRegistroVariavel(reg);
    }

    vector<Indice> indices = buffer.lerRegistroFixo();
    
    buffer.inserirIndicesArvore(indices);
   
    Registro resultado;
    resultado = buffer.buscarRegisro(91040);

    cout << resultado.ID << " " << resultado.titulo << " " << resultado.autor 
         << resultado .anoPublicacao << " " << resultado.categoria << endl;
    return 0;
}