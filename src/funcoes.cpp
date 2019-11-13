#include <iostream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>

using namespace std;

void menu(){
    cout << "\tEscolha uma opção: " << endl;
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
     bool aux = false;

     do{
     cout<<"Insira o nome da tabela a ser excluída:\t";
     
     cin >> tabelaRm;

     auxiliar = "tabelas/"+tabelaRm+".csv";
     
     if (remove(auxiliar.c_str( )) != 0){
        cout << "Não foi possível excluir a tabela. Verifique se o nome está correto.\n" << endl;
     }
     else{
        cout << "\nA tabela " << tabelaRm <<" foi excluída com sucesso!\n" << endl;
        aux = true;
     }
 }while(aux == false);


     
 }
/*void inserirLista(string nome, list<string> lista){
    if(lista.empty() == true){
        lista.push_front(nome);
    }
    else{
        lista.push_back(nome);
    }
}
void listarTabela(list<string> lista){
    if(lista.empty() == true){
        cout << "A lista se encontra vazia, insira uma tabela para poder listá-la." << endl;
    }
    else{
        int tamanho = lista.size();
        for (int i = 0; i < tamanho; i++)
        {
            cout << lista.front() << endl;
        }
    }
}
void excluirNomeTabela(list<string> lista){
    string nome;
    cout << "Digite o nome da tabela que deseja retirar da lista:" << endl;
    cin >> nome;
    if(lista.empty() == true){
        cout << "Não existem tabelas para a ação, crie uma tabela." << endl;
    }
    else{
        int tamanho = lista.size();
        for (int i = 0; i < tamanho; i++){
            if(nome == lista.front()){
                lista.pop_front();
                cout << "Nome excluído" << endl;
                break;
            }
        }
    }
}*/