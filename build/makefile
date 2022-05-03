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

main: main.o instanceparser.o IOController.o mdpinstance.o
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