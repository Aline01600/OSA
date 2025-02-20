#include<iostream>
#include<cstring>
#include "indice.hpp"

using namespace std;

string Indice::packfixed(){
    string buffer(sizeof(int) + sizeof(long long), '\0');

    memcpy(&buffer[0], &ID_livro, sizeof(int));
    memcpy(&buffer[sizeof(int)], &endereco, sizeof(long long));

    return buffer;

}

void Indice::unpackfixed(string &buffer){
    if (buffer.size() < sizeof(int) + sizeof(long long)) {
        cerr << "Erro: tamanho do buffer inválido." << endl;
        return;
    }
    memcpy(&ID_livro, buffer.data(), sizeof(int));
    memcpy(&endereco, buffer.data() + sizeof(int), sizeof(long long));
}