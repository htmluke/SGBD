#include <iostream>
using namespace std;

struct Colunas
{
    string nome;
    int tipo;
} typedef Colunas;

class Tabela
{
private:
    int chavePrimaria, chaveEstrangeira, n;
    Colunas v[];
public:
    Tabela();
    Tabela(int, int, int);
    ~Tabela();
};
Tabela::Tabela(){};

Tabela::Tabela(int chavePrimaria, int chaveEstrangeira, int n)
{
    this->chavePrimaria = chavePrimaria;
    this->chaveEstrangeira = chaveEstrangeira;
    this->n = n;
}

Tabela::~Tabela()
{
}


int main(int argc, const char * argv[])
{
    Tabela T;
    int cP = 1, cE = 2, n = 3;
    Tabela f(cP, cE, n);
    return 0;
}