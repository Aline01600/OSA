#include <cstring>
#include <string>
#include <sstream>
#include "registro.hpp"

std::string Registro::packFixed() {
    constexpr size_t TAMANHO_NOME = 100;

    std::string buffer(TAMANHO_NOME + sizeof(int), '\0');

    std::strncpy(&buffer[0], nome.c_str(), TAMANHO_NOME);
    buffer[TAMANHO_NOME - 1] = '\0';

    std::memcpy(&buffer[TAMANHO_NOME], &idade, sizeof(int));

    return buffer;
}


void Registro::unpackFixed(std::string& buffer) {
    // Extrai o nome
    nome = buffer.substr(0, 100);
    nome.erase(nome.find_last_not_of('\0') + 1);  // Remove os '\0'
    // Extrai a idade (próximos 4 bytes)
    const char* idadePtr = &buffer[100];
    idade = *reinterpret_cast<const int*>(idadePtr);
}