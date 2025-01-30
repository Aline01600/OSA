#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include"buffer.hpp"
#include"registro.hpp"

using namespace std;

vector<Registro> Buffer::lerDadostxt(){
    ifstream arquivo(Buffer::nomeArquivo); 
    if(!arquivo.is_open()){
       cerr << "Erro ao abrir aquivo: " << nomeArquivo;
       return{};
    }

    vector<Registro> pessoas;
    string linha;
    Registro pessoa;

    getline(arquivo, linha);
    while(getline(arquivo, linha)){
        stringstream linhaStream(linha);
        string campo;
        Registro pessoa;
        if (getline(linhaStream, campo, '|')) pessoa.nome = campo;
        if (getline(linhaStream, campo, '|')) pessoa.sobrenome = campo;
        if (getline(linhaStream, campo, '|')) pessoa.telefone = campo;
        if (getline(linhaStream, campo, '|')) pessoa.data_N = campo;
        pessoas.push_back(pessoa);
    }
    arquivo.close();
    return pessoas;   
}

void Buffer::escreverRegistroVariavel(Registro reg){
    ofstream arquivo2(nomeArquivoBin, ios::binary | ios::app);
    if(!arquivo2.is_open()){
        cerr << "Erro: Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    buffer.clear();
    buffer = reg.pack();
    arquivo2.write(buffer.c_str(), buffer.size());

    arquivo2.close();
}

vector<Registro> Buffer::lerRegistroVariavel() {
    vector<Registro> registros;
    ifstream arquivo2(nomeArquivoBin, ios::binary);

    if (!arquivo2.is_open()) {
        cerr << "Erro: erro ao abrir o arquivo para leitura" << endl;
        return registros;
    }

    while (arquivo2.peek() != EOF) {
        // Lê o tamanho do registro
        int tamanho;
        if (!arquivo2.read(reinterpret_cast<char*>(&tamanho), sizeof(int))) {
            cerr << "Erro: falha ao ler o tamanho do registro." << endl;
            break;
        }
        
        buffer.resize(tamanho + sizeof(int), '\0');  

        if (!arquivo2.read(&buffer[sizeof(int)], tamanho)) {
            cerr << "Erro: falha ao ler os dados do registro." << endl;
            break;
        }

        Registro reg;
        reg.unpack(buffer);
        registros.push_back(reg);
    }

    arquivo2.close();
    return registros;
 }