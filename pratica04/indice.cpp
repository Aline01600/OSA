#include<iostream>
#include "indice.hpp"

using namespace std;

int Indice::packfixed(){
    return (ID_livro & 0xFFFF) | (endereco << 16); // Empacota como 16 bits cada
}

void Indice::unpackfixed(int valor){
    ID_livro = valor & 0xFFFF;              // Pega os 16 bits menos significativos
    endereco = (valor >> 16) & 0xFFFF;      // Pega os 16 bits mais significativos
}