#ifndef REGISTRO_H
#define REGISTRO_H
#include <cstring>  // Para usar strncpy
using namespace std;

struct Registro {
    char nome[51];
    int idade;

    Registro(const char* n, int i) : idade(i) {
        strncpy(nome, n, 50);
        nome[50] = '\0';  // Garantir que a string seja terminada com '\0'
    }
};

void lerArquivo(const string& nomeArquivo);

#endif
