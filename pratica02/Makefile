# Arquivo principal: main.cpp

# Definindo as variáveis do projeto (MAIN é o nome do arquivo principal, que contém a função main, sem a extensão)
MAIN := main

# Objetos a serem gerados na compilação
OBJECTS := $(MAIN).o Registro.o Buffer.o Arquivo.o

# Flags de compilação
FLAGS := -Wall -Wextra -std=c++17 -pedantic-errors

# Habilitar depuração
DEBUG := -g

# Necessário apenas quando se incluir a biblioteca <math.h> em algum arquivo fonte
MATH := -lm

# Definição do compilador
CC := g++

# Ajustando parâmetros/comandos ao sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# Ponto de compilação principal
all: $(OUTPUTMAIN)
	@echo "Compiling 'all' complete!"

# Gerando o arquivo executável
$(OUTPUTMAIN): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUTMAIN) $(MATH)

# Gerando o arquivo objeto da função principal
main.o: $(MAIN).cpp Arquivo.hpp Registro.hpp Buffer.hpp
	$(CC) $(FLAGS) -c $(MAIN).cpp

# Gerando o arquivo objeto Registro.o
Registro.o: Registro.cpp Registro.hpp
	$(CC) $(FLAGS) -c Registro.cpp

# Gerando o arquivo objeto Buffer.o
Buffer.o: Buffer.cpp Buffer.hpp Registro.hpp Arquivo.hpp
	$(CC) $(FLAGS) -c Buffer.cpp

# Gerando o arquivo objeto Arquivo.o
Arquivo.o: Arquivo.cpp Arquivo.hpp Registro.hpp Buffer.hpp
	$(CC) $(FLAGS) -c Arquivo.cpp

# Comando para limpar arquivos gerados
clean:
	@echo "Cleaning up..."
	$(RM) $(OBJECTS) $(OUTPUTMAIN)
	@echo "Cleanup complete!"

# Comando para rodar o programa
run: all
	@echo "Running the executable..."
	./$(OUTPUTMAIN)  # ou apenas "$(OUTPUTMAIN)" para Windows
	@echo "Execution complete!"
