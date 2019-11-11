#include <iostream>
#include <string>
#include "classes.hpp"
#include "funcoes.hpp"

using namespace std;

int main(int argc, const char * argv[]){
    Tabela T;
    int cP = 1, cE = 2, n = 3;
    Tabela f(cP, cE, n);
    menu();
    return 0;
}