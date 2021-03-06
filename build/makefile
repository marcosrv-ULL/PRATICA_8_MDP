# *****************************************************
# Variables to control Makefile operation and env variables
CC = g++
CFLAGS = -std=c++11 -Wall -g -O2
BIN = ../bin
SRC = ../src
INC = ../include
PROGRAM = $(BIN)/mdp 
# ****************************************************
# Targets needed to bring the executable up to date

all: main

execution:
	$(PROGRAM)

compile_and_exec: main
	$(PROGRAM)

main: main.o instanceparser.o IOController.o mdpinstance.o mdpsolution.o greedy.o benchmark.o localsearch.o localsearch_II.o grasp.o algoritmo.o mdpfactory.o tabu.o ramificacion.o
	$(CC) $(CFLAGS) -o $(PROGRAM) $(BIN)/*.o  

main.o: $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(BIN)/main.o

benchmark.o: $(SRC)/benchmark/benchmark.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/benchmark/benchmark.cpp -o $(BIN)/benchmark.o

IOController.o: $(SRC)/IOController/IOController.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/IOController/IOController.cpp -o $(BIN)/IOController.o

instanceparser.o: $(SRC)/instance/instanceparser.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/instance/instanceparser.cpp -o $(BIN)/instanceparser.o

mdpinstance.o: $(SRC)/instance/mdpinstance.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/instance/mdpinstance.cpp -o $(BIN)/mdpinstance.o

mdpsolution.o: $(SRC)/solution/mdpsolution.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/solution/mdpsolution.cpp -o $(BIN)/mdpsolution.o

greedy.o: $(SRC)/algoritmo/greedy.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/greedy.cpp -o $(BIN)/greedy.o

benchmark.o: $(SRC)/benchmark/benchmark.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/benchmark/benchmark.cpp -o $(BIN)/benchmark.o

localsearch.o: $(SRC)/algoritmo/localsearch.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/localsearch.cpp -o $(BIN)/localsearch.o

localsearch_II.o: $(SRC)/algoritmo/localsearch_II.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/localsearch_II.cpp -o $(BIN)/localsearch_II.o

grasp.o: $(SRC)/algoritmo/grasp.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/grasp.cpp -o $(BIN)/grasp.o

tabu.o: $(SRC)/algoritmo/tabu.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/tabu.cpp -o $(BIN)/tabu.o

algoritmo.o: $(SRC)/algoritmo/algoritmo.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/algoritmo.cpp -o $(BIN)/algoritmo.o

mdpfactory.o: $(SRC)/factory/mdpfactory.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/factory/mdpfactory.cpp -o $(BIN)/mdpfactory.o

ramificacion.o: $(SRC)/algoritmo/ramificacion.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/algoritmo/ramificacion.cpp -o $(BIN)/ramificacion.o