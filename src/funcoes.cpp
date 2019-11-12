#include <iostream>
#include <string>
#include <list>
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
    cout << "8 - Sair" << endl;
}

void inserirLista(string nome, list<string> lista){
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
}