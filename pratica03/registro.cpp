#include<cstring>
#include<string>
#include<sstream>
#include "registro.hpp"

using namespace std;

string Registro::pack(){
    stringstream linhaStream;
    linhaStream << nome << "|" << sobrenome << "|" << telefone << "|" << data_N << "|";

    string dados = linhaStream.str();
    int tamanho = dados.size();  

    string buffer(sizeof(int) + tamanho, '\0'); 

    memcpy(&buffer[0], &tamanho, sizeof(int));   
    memcpy(&buffer[sizeof(int)], dados.c_str(), tamanho); 

    return buffer; 
}


void Registro::unpack(std::string& buffer) {
    int tamanho;
    std::memcpy(&tamanho, buffer.data(), sizeof(int));  // Lê o tamanho do registro

    if (buffer.size() < static_cast<size_t>(sizeof(int) + tamanho));  

    std::string dados(buffer.begin() + sizeof(int), buffer.begin() + sizeof(int) + tamanho);
    std::stringstream ss(dados);

    getline(ss, nome, '|');
    getline(ss, sobrenome, '|');
    getline(ss, telefone, '|');
    getline(ss, data_N, '|');
}