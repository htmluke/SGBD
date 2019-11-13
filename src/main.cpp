#include <iostream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>

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
    Tabela T;
    Opcoes op;
    int cP = 1, cE = 2, n = 3;
    int aux = 1, opcao;
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
                Tabela T(cP, cE, n, lista);
            }
                break;

           case LISTARTABELA:{
                listarTabela("tabelas");           	
           	}
         		break;

            case ADICIONARLINHA:{

            }
                break;

            case LISTARDADOS:{

            }
                break;

            case PESQUISARVALOR:{

            }
                break;

            case APAGARVALOR:{

            }
                break;

            case EXCLUIRTABELA:{
            	
            }
                break;

            default:
                cout << "Opção inválida, digite novamente :)" << endl;

        }
    }
    
    return 0;
}