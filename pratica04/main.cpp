#include <iostream>
#include <vector>
#include "buffer.hpp"
#include "indice.hpp"
#include "registro.hpp"

using namespace std;

int main(){

    Buffer buffer;
    buffer.nomeArquivo = "arquivotest.csv";
    buffer.nomeArquivoBin = "livros.bin";
    buffer.nomeIndiceBin = "indice.bin";
    
    vector<Registro> livros = buffer.lerDadosCSV();
   
    for(const auto& reg: livros){
        buffer.escreverRegistroVariavel(reg);
    }

    vector<Registro> registros = buffer.lerRegistroVariavel();
    for(const auto& reg : registros){
        
        cout << reg.ID << " " << reg.titulo << " " <<
        reg.autor << " " << reg.anoPublicacao << " " <<
        reg.categoria << endl;
    }

    vector<Indice> indices = buffer.lerRegistroFixo();
    for(const auto& reg : indices){
        cout << reg.ID_livro <<" | "<< reg.endereco << endl;
    }

   
    buffer.inserirIndicesArvore(indices);
   
    cout <<  buffer.arvore.Travessia_InOrder() << endl << endl;
    cout <<  buffer.arvore.Travessia_Largura() << endl << endl;
    cout <<  buffer.arvore.Travessia_PosOrder() << endl << endl;
    cout <<  buffer.arvore.Travessia_PreOrder() << endl << endl;
    cout <<  buffer.arvore.Travessia_Profundidade() << endl << endl;

    Registro resultado;
    resultado = buffer.buscarRegisro(41739);

    cout << resultado.ID << " " << resultado.titulo << " " << resultado.autor 
         << resultado .anoPublicacao << " " << resultado.categoria << endl;
    return 0;
}