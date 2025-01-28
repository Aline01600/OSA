#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "arquivo.hpp"

using namespace std;

vector<Registro> Arquivo::lerRegistrosCSV(){
    ifstream arquivo(Arquivo::nomeArquivo);
    if(!arquivo.is_open()){
       cerr << "Erro ao abrir aquivo: " << nomeArquivo;
       return{};
     }

    vector<Registro> pessoas;
    string linha;
    Registro pessoa;
    getline(arquivo, linha);
    while(getline(arquivo,linha)){
        stringstream linhaStream(linha); //fluxo apartir da linha lida, ajuda dividir e extrair informações
        string campo;
        Arquivo arquivo;

        if(getline(linhaStream, campo, ',')){ //lê cada palavra até encontrar ','
            pessoa.nome = campo;
        }
        if(getline(linhaStream, campo)){
            pessoa.idade = stoi(campo);  // convertendo para inteiro
        }
        pessoas.push_back(pessoa);
    }
    arquivo.close();
    return pessoas;
}

void Arquivo::adicionarRegistroFixo(Registro reg){
    Buffer buffer;

    ofstream arquivo2("registros.bin", ios::binary | ios::app);
    if (!arquivo2.is_open()) {
    cerr << "Erro: Erro abrir o arquivo para escrita!" << endl;
    return;
    }

    buffer.escreverRegistroFixo(reg, arquivo2);  

    arquivo2.close();
}                     

vector<Registro> Arquivo::lerRegistrosFixo(){
    Buffer buffer;
    vector<Registro> registros;
    
    ifstream arquivo2("registros.bin");
    if(!arquivo2.is_open()){
        cerr << "Erro ao abrir o arquivo para leitura!" << endl;
    }

    while (arquivo2.peek() != EOF){
        Registro reg = buffer.lerRegistroFixo(arquivo2);
        registros.push_back(reg);
    }

    arquivo2.close();
    return registros;
}
