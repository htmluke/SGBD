# Makefile 

.PHONY: all, build, clean, folders

all: build


build: folders exe

clean:
	rm -rf objects
	rm -rf tabelas
	rm -f exe

folders:
	mkdir -p objects
	mkdir -p tabelas

objects/classes.o: src/classes.cpp
	g++ src/classes.cpp -Iinclude -c -o objects/classes.o -std=c++11

objects/funcoes.o: src/funcoes.cpp
	g++ src/funcoes.cpp -Iinclude -c -o objects/funcoes.o -std=c++11


exe: src/main.cpp objects/classes.o objects/funcoes.o 
	g++ src/main.cpp objects/classes.o objects/funcoes.o -Iinclude -o exe -std=c++11
