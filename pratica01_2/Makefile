# Nome do executável
EXEC = programa

# Compilador e flags de compilação
CXX = g++##############################################################################
# Exemplo de makefile para um projeto bem simples em linguagem C++
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
# Arquivos auxiliares: Registro.cpp Registro.h
##############################################################################
# Dependencias: 
# main.cpp => Registro.cpp e Registro.h
# Registro.cpp ==> Registro.h
##############################################################################

# definição de variáveis auxiliares do makefile
MAIN = main
OBJECTS	= $(MAIN).o Registro.o
FLAGS = -Wall -Wextra -std=c++23 -pedantic-errors
MATH = -lm
DEBUG = -g
CC = g++
# Nome do arquivo de saída (sem .exe no Ubuntu)
OUTPUTMAIN := $(MAIN).out

# regra de compilação do projeto completo
all: $(OUTPUTMAIN)

# regra para geração do arquivo executavel
$(OUTPUTMAIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUTMAIN) $(FLAGS)

# regra de compilação do objeto $(MAIN).o
$(MAIN).o: $(MAIN).cpp Registro.h
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

# regra de compilação do objeto Registro.o
Registro.o: Registro.cpp Registro.h
	$(CC) -c Registro.cpp -o Registro.o $(FLAGS)

# regra para limpeza do projeto (excluir arquivos .o e o executável). 
clean:
	rm -rf *.o
	rm -rf $(OUTPUTMAIN)

# regra para compilar todo o projeto (se necessário) e, posteriormente, executar
run: all
	./$(OUTPUTMAIN)
CXXFLAGS = -Wall -std=c++11

# Arquivos de origem e objetos
SRCS = main.cpp Registro.cpp
OBJS = $(SRCS:.cpp=.o)

# Regra principal (target padrão)
all: $(EXEC)

# Gera o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compila os arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos de objeto e executável
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets para evitar conflitos com arquivos de mesmo nome
.PHONY: all clean
