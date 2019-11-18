#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
#include "funcoes.hpp"
using namespace std;

struct Colunas{
    string nome;
    int tipo;
} typedef Colunas;

class Tabela{
private:
    int chavePrimaria, chaveEstrangeira;
    unsigned int tam;
    Colunas* v;
public:
    Tabela();
    ~Tabela();
};

#endif