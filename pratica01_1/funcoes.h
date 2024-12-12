#ifndef FUNCOES_H
#define FUNCOES_H
#include <string>
#include <vector>
using namespace std;

struct Registro {
    string nome;
    Registro(const string& n) : nome(n) {}
};

void lerArquivo(const string& nomeArquivo);

#endif
