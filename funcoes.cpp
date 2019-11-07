#include <iostream>
#include <string>
#include "classes.hpp"
#include "funcoes.hpp"

using namespace std;

void menu(){
    cout << "Escolha uma opção: " << endl;
    cout << "1 - Criar Tabela " << endl;
    cout << "2 - Listar Tabelas Existentes" << endl;
    cout << "3 - Adicionar Nova Linha na Tabela" << endl;
    cout << "4 - Listar Todos os Dados da Tabela" << endl;
    cout << "5 - Pesquisar Valor na Tabela" << endl;
    cout << "6 - Apagar Valor na Tabela" << endl;
    cout << "7 - Excluir Tabela" << endl;
    cout << "0 - Sair" << endl;
}

typedef enum Opcoes{
	SAIR,
	CRIARTABELA,
	LISTARTABELA,
	ADICIONARLINHA,
	LISTARDADOS,
	PESQUISARVALOR,
	APAGARVALOR,
	EXCLUIRTABELA
} Opcoes;

void opcaoMenu()
{
    int aux = 1, opcao;
    Opcoes op;
    cin >> opcao;

    switch (op){
        case SAIR:
            aux = 0;
            cout << "Saindo..." << endl;
            break;
        case CRIARTABELA:

            break;
        case LISTARTABELA:

            break;
        case ADICIONARLINHA:

            break;
        case LISTARDADOS:

            break;
        case PESQUISARVALOR:

            break;
        case APAGARVALOR:

            break;
        case EXCLUIRTABELA:

            break;
        default:
            cout << "Opção inválida, digite novamente :)" << endl;
            break;
    }
    if(aux == 1) opcaoMenu();
}