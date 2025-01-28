# definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contem a função main, sem a extensao)
MAIN 	:= main
# objetos a serem gerados na compilação
OBJECTS := $(MAIN).o registro.o buffer.o arquivo.o
# (para C, pode-se usar o padrão ISO 2011 (c11) ou 2018 (c18), dependendo do seu compilador...
# usar -std=c98 no lugar do c++11, c++17, c++20, etc.. 

FLAGS 	:= -Wall -Wextra -std=c++17 -pedantic-errors


# habilitar a depuração
DEBUG :=  -g

# necessário apenas quando se incluir  a biblioteca <math.h> em algum arquivo fonte no projeto
MATH 	:= -lm

# definição do compilador: para C usar o gcc, por exemplo
CC		:= g++

# ajustando alguns parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# ponto de compilação principal
all: main.exe
	@echo Compiling 'all' complete!

# gerando o arquivo executavel
main.exe: $(OBJECTS)  
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)
	
# gerando o arquivo objeto da função principal... adicionar as dependencias (se houverem)
main.o: $(MAIN).cpp registro.hpp buffer.hpp arquivo.hpp
	$(CC) $(FLAGS) -c $(MAIN).cpp
	
registro.o: registro.cpp registro.hpp
	$(CC) $(FLAGS) -c registro.cpp

buffer.o: buffer.cpp registro.hpp buffer.hpp
	$(CC) $(FLAGS) -c buffer.cpp

arquivo.o: arquivo.cpp buffer.hpp arquivo.hpp  #se precisar coleoque aqui registo.hpp
	$(CC) $(FLAGS) -c arquivo.cpp

clean:
	rm -rf $(OBJECTS)
	rm -rf $(OUTPUTMAIN)
	@echo Cleanup complete!!!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'all' complete!!!