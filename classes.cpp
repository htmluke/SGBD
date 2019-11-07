#include <iostream>
#include <string>
#include "classes.hpp"
using namespace std;

Tabela::Tabela(){};

Tabela::Tabela(int chavePrimaria, int chaveEstrangeira, int n){
    this->chavePrimaria = chavePrimaria;
    this->chaveEstrangeira = chaveEstrangeira;
    this->n = n;
}

Tabela::~Tabela(){
}