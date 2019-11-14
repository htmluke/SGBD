#include <iostream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>

using namespace std;

void menu(){
    cout << "\n\tEscolha uma opção: " << endl;
    cout << "\t0 - Sair" << endl;
    cout << "\t1 - Criar Tabela " << endl;
    cout << "\t2 - Listar Tabelas Existentes" << endl;
    cout << "\t3 - Adicionar Nova Linha na Tabela" << endl;
    cout << "\t4 - Listar Todos os Dados da Tabela" << endl;
    cout << "\t5 - Pesquisar Valor na Tabela" << endl;
    cout << "\t6 - Apagar Valor na Tabela" << endl;
    cout << "\t7 - Excluir Tabela" << endl;
   
}

void listarTabela(string nomeDir){
    DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char isDir = 0x4;
    unsigned char isFile = 0x8;
 
    dir = opendir (nomeDir.c_str());
 
    if (dir == 0) {
        std::cerr << "Nao foi possivel abrir diretorio." << std::endl;
        exit (1);
    }
 
    //Iterar sobre o diretorio
    while (entrada = readdir (dir))
        if (entrada->d_type == isFile)
            std::cout << entrada->d_name << std::endl;
 
    closedir (dir);
}

 void excluirTabela(){

     string tabelaRm, auxiliar;
     int option;
     bool aux = false, aux1 = false;

     do{
	     cout<<"Insira o nome da tabela a ser excluída:\t";
	     
	     cin >> tabelaRm;

	     auxiliar = "tabelas/"+tabelaRm+".csv";
	     
	     cout << "Tem certeza que deseja excluir " << tabelaRm << ".csv?\t1 - Sim\t2 - Não\n\t";
	     cin >> option;

	     if(option == 1){
	     	if (remove(auxiliar.c_str( )) != 0){
	    		cout << "Não foi possível excluir a tabela. Verifique se o nome está correto e se a tabela existe.\n\t" << endl;
	     	}else{
		        cout << "\nA tabela " << tabelaRm <<" foi excluída com sucesso!\n" << endl;
		        aux = true;
	     	}
	     }else if(option == 2){
	     	cout << "Voltando ao menu..." << endl;
	     	aux = true;
	     }else{
	     	cout << "Opção inválida, tente novamente." << endl;
	     }
     
     }while(aux == false);

}
