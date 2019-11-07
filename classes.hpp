#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>
using namespace std;

struct Colunas{
    string nome;
    int tipo;
} typedef Colunas;

class Tabela{
private:
    int chavePrimaria, chaveEstrangeira, n;
    Colunas v[];
public:
    Tabela();
    Tabela(int, int, int);
    ~Tabela();
};

#endif