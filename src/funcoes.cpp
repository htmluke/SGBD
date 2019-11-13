#include <iostream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>

using namespace std;

void menu(){
    cout << "Escolha uma opção: " << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Criar Tabela " << endl;
    cout << "2 - Listar Tabelas Existentes" << endl;
    cout << "3 - Adicionar Nova Linha na Tabela" << endl;
    cout << "4 - Listar Todos os Dados da Tabela" << endl;
    cout << "5 - Pesquisar Valor na Tabela" << endl;
    cout << "6 - Apagar Valor na Tabela" << endl;
    cout << "7 - Excluir Tabela" << endl;
   
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