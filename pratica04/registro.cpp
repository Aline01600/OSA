#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include "registro.hpp"

using namespace std;

string Registro::pack(){
    stringstream linhaStream;
    linhaStream << ID << "|" << titulo << "|" << autor << "|" <<
    anoPublicacao << "|" << categoria << "|";
    
    string dados = linhaStream.str();
    int tamanho = dados.size();

    string buffer(sizeof(int) + tamanho, '\0');
    memcpy(&buffer[0], &tamanho, sizeof(int));
    memcpy(&buffer[sizeof(int)], dados.c_str(), tamanho);
    return buffer;

}

void Registro::unpack(string& buffer) {
    int tamanho;
    memcpy(&tamanho, buffer.data(), sizeof(int));

    string dados(buffer.begin() + sizeof(int), buffer.end());
    stringstream ss(dados);

    string ID_str; 
    getline(ss, ID_str, '|');
    ID = stoi(ID_str);
    getline(ss, titulo, '|');
    getline(ss, autor, '|');
    getline(ss, anoPublicacao, '|');
    getline(ss, categoria, '|');
}
