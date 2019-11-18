#include <iostream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include<stdio.h>     //for remove( ) and rename( )


using namespace std;

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

int main(int argc, const char * argv[]){
    list<string> lista;
    int aux = 1; 
    int opcao;
    while(aux == 1){
        //Imprime o menu toda vez que o usuário for realizar uma nova atividade
        menu();
        cin >> opcao;
        switch (opcao){

            case SAIR:{
                aux = 0;
                cout << "Saindo..." << endl;
            }
                break;

            case CRIARTABELA:{
                Tabela tab;
            }
                break;

           case LISTARTABELA:{
                listarTabelas("tabelas");            
            }
                break;

            case ADICIONARLINHA:{
                inserirLinha();
            }
                break;

            case LISTARDADOS:{
                todosOsDados();
            }
                break; //a

            case PESQUISARVALOR:{
                pesquisarDado();
            }
                break;

            case APAGARVALOR:{

            }
                break;

            case EXCLUIRTABELA:{
                excluirTabela();
            }
                break;

            default:
                cout << "Opção inválida, digite novamente :)" << endl;

        }
    }

    
    return 0;
}