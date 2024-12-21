#include <iostream>
#include "Registro.h"
using namespace std;

int main(){

    string nomeArquivo = "Nomes_Idades_1.csv";
    lerArquivo(nomeArquivo);
    printf("------------------------------\n"); 
    
    nomeArquivo = "Nomes_Idades_2.csv";
    lerArquivo(nomeArquivo);  
    printf("------------------------------\n");  
    
    nomeArquivo = "Nomes_Idades_3.csv";
    lerArquivo(nomeArquivo); 
    printf("------------------------------\n"); 
    
    nomeArquivo = "Nomes_Idades_4.csv";
    lerArquivo(nomeArquivo); 
    printf("------------------------------\n"); 
    
    nomeArquivo = "Nomes_Idades_5.csv";
    lerArquivo(nomeArquivo);   

    return 0;
}
