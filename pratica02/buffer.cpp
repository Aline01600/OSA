#include "buffer.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void Buffer::escreverRegistroFixo(Registro reg, ofstream& out) {

    string buffer = reg.packFixed();
   
    out.write(buffer.data(), buffer.size());
    if (!out.good()) {
        cerr << "Erro ao escrever no arquivo!" << endl;
    }
}

Registro Buffer::lerRegistroFixo(ifstream& in) {
    const size_t bufferSize = 100 + sizeof(int);
    std::vector<char> buffer(bufferSize);  // Buffer fixo para leitura

    in.read(buffer.data(), bufferSize);
    if (!in) {
        throw std::runtime_error("Erro ao ler do arquivo binário.");
    }

    // Converte para string sem alterar os bytes
    std::string bufferStr(buffer.begin(), buffer.end());

    Registro reg;
    reg.unpackFixed(bufferStr);

    return reg;
}