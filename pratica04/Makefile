# Nome do arquivo principal (sem extensão)
MAIN := main

# Arquivos objeto
OBJECTS := $(MAIN).o registro.o buffer.o

# Flags de compilação
FLAGS := -Wall -Wextra -std=c++17 -pedantic-errors

# Habilitar depuração (opcional)
DEBUG := -g

# Necessário apenas quando usar <math.h>
MATH := -lm

# Compilador
CC := g++

# Extensão do executável dependendo do sistema operacional
ifeq ($(OS), Windows_NT)
    OUTPUT := $(MAIN).exe
    RM := del /f /q
    RUN := $(MAIN).exe
else
    OUTPUT := $(MAIN).out
    RM := rm -f
    RUN := ./$(MAIN).out
endif

# Ponto de compilação principal
all: $(OUTPUT)
	@echo "Compilação concluída!"

# Gera o arquivo executável
$(OUTPUT): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(OUTPUT) $(MATH)

# Compilação do arquivo principal
main.o: $(MAIN).cpp registro.hpp buffer.hpp indice.hpp Fila.hpp Pilha.hpp 
	$(CC) $(FLAGS) -c $(MAIN).cpp

# Compilação de Registro.o
Registro.o: registro.cpp registro.hpp
	$(CC) $(FLAGS) -c registro.cpp

# Compilação de Buffer.o
Buffer.o: Buffer.cpp buffer.hpp registro.hpp arvore.hpp
	$(CC) $(FLAGS) -c buffer.cpp

# Compilação de Indice.o
Buffer.o: indice.cpp indice.hpp 
	$(CC) $(FLAGS) -c indice.cpp


# Limpeza de arquivos gerados
clean:
	@echo "Limpando arquivos temporários..."
	rm -rf $(OBJECTS)
	rm -rf $(OUTPUTMAIN)
	rm -rf *.bin
	rm -rf *.dat
	@echo "Limpeza concluída!"

# Executar o programa
run: all
	@echo "Executando o programa..."
	$(RUN)
	@echo "Execução concluída!"
