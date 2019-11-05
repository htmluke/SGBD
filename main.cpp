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
    int chavePrimaria, chaveEstrangeira;
    Colunas v[];
public:
    Tabela(/* args */);
    ~Tabela();
};

Tabela::Tabela(/* args */)
{
}

Tabela::~Tabela()
{
}


int main()
{

    return 0;
}