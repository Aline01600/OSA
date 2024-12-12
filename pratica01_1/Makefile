##############################################################################
# Exemplo de makefile para um projeto bem simples em linguagem C++
# Para simplificar, todos os arquivos estão em um mesmo diretório
##############################################################################
##############################################################################
# Arquivo principal: main.cpp
##############################################################################
# Arquivos auxiliares: funcoes.cpp funcoes.h
##############################################################################
# Dependencias: 
# main.cpp => funcoes.cpp e funcoes.h
# funcoes.cpp ==> funcoes.h
##############################################################################

# definição de variáveis auxiliares do makefile
MAIN = main
OBJECTS	= $(MAIN).o funcoes.o
FLAGS = -Wall -Wextra -std=c++23 -pedantic-errors
MATH = -lm# Nome do executável final
EXEC := programa

# Compilador e flags
CC := g++
CFLAGS := -Wall -Wextra -std=c++17 -pedantic-errors

# Arquivos fonte e de cabeçalho
SRCS := main.cpp funcoes.cpp
HEADERS := funcoes.h
OBJS := $(SRCS:.cpp=.o)

# Alvo padrão que compila o programa
all: $(EXEC)

# Regra para compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Regra para compilar arquivos .cpp em .o
%.o: %.cpp $(HEADERS) Arquivo_Nomes.txt
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa os arquivos de objeto e o executável
clean:
	rm -f $(OBJS) $(EXEC)

# Alvo para rodar o programa após compilação
run: $(EXEC)
	./$(EXEC)

DEBUG = -g
CC = g++

# ajustando alguns parâmetros/comandos ao sistema operacional
# ajuste às necessidades do seu projeto
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# regra de compilação do projeto completo
all: $(OUTPUTMAIN)

# regra para geração do arquivo executavel
$(OUTPUTMAIN): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(OUTPUTMAIN) $(FLAGS)

# regra de compilação do objeto $(MAIN).o
$(MAIN).o: $(MAIN).cpp funcoes.h
	$(CC) -c $(MAIN).cpp -o $(MAIN).o $(FLAGS)

# regra de compilação do objeto funcoes.o
funcoes.o: funcoes.cpp funcoes.h
	$(CC) -c funcoes.cpp -o funcoes.o $(FLAGS)

# regra para limpeza do projeto (excluir arquivos .o e o executável). 
clean:
	rm -rf *.o
	rm -rf $(OUTPUTMAIN)

# regra para compilar todo o projeto (se necessário) e, posteriormente, executar
run: all
	./$(OUTPUTMAIN)