#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"buffer.hpp"

using namespace std;

vector<Registro> Buffer::lerDadosCSV(){
    ifstream arquivo(Buffer::nomeArquivo); 
    if(!arquivo.is_open()){
       cerr << "Erro ao abrir aquivo: " << nomeArquivo;
       return{};
    }

    vector<Registro> pessoas;
    string linha;
    Registro livro;

    getline(arquivo, linha);
    while(getline(arquivo, linha)){
        stringstream linhaStream(linha);
        string campo;
        Registro livro;
        if (getline(linhaStream, campo, ';')) livro.ID = stoi(campo);
        if(getline(linhaStream, campo, ';')) livro.titulo = (campo);
        if(getline(linhaStream, campo, ';')) livro.autor = (campo);
        if(getline(linhaStream, campo, ';')) livro.anoPublicacao = (campo); 
        if(getline(linhaStream, campo, ';')) livro.categoria = (campo);
        if(getline(linhaStream, campo, ';')) livro.genero = (campo);
        
       pessoas.push_back(livro);
    }
    arquivo.close();
    return pessoas;   
}

void Buffer::escreverRegistroFixo(int id, long long endereco){
    ofstream arquivo3("indice.bin", ios::binary | ios::app);
    if (!arquivo3.is_open()) {
        cerr << "Erro: Erro ao abrir o arquivo de indices para escrita!" << endl;
        return;
    }

    Indice indice;
    indice.ID_livro = id;
    indice.endereco = endereco;

    indice.buffer = indice.packfixed();
    arquivo3.write(indice.buffer.data(), indice.buffer.size());
    arquivo3.close();
}

vector<Indice> Buffer::lerRegistroFixo() {
    const size_t bufferSize = sizeof(int) + sizeof(long long);
    vector<Indice> indices;
    
    ifstream arquivo3("indice.bin", ios::binary);
    if (!arquivo3.is_open()) {
        cerr << "Erro: falha ao abrir o arquivo binário." << endl;
        return indices;
    }
  
   while (!arquivo3.eof()) {
        Indice indice;
        string buffer(bufferSize, '\0');
        if (arquivo3.read(&buffer[0], bufferSize)) {
            indice.unpackfixed(buffer);
            indices.push_back(indice);
        } 
    }

    arquivo3.close();
    return indices;
}

void Buffer::escreverRegistroVariavel(Registro reg){
   
    ofstream arquivo2(nomeArquivoBin, ios::binary | ios::app);
    if(!arquivo2.is_open()){
        cerr << "Erro: Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }
    long long posicao = arquivo2.tellp(); //captura posição onde o registro será salvo
   
    buffer.clear();
    buffer = reg.pack();
    int tamanho = buffer.size();
    arquivo2.write(reinterpret_cast<char*>(&tamanho), sizeof(int));
    arquivo2.write(buffer.c_str(), buffer.size());
    arquivo2.close();
    
    escreverRegistroFixo(reg.ID, posicao);

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
        
        buffer.resize(tamanho, '\0');  

        if (!arquivo2.read(&buffer[0], tamanho)) {
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

