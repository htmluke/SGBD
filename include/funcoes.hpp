#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <iostream>
#include <string>
#include <dirent.h>
#include <cstdlib>
using namespace std;

template <typename T>
T inserir_campo(int tipo, T pKey);
void menu();
void opcaoMenu();
//void inserirLista(string, list<string>);
void listarTabela(string);
void excluirTabela();
bool compareString_Number(char);
bool verificar_numString(string);
void inserirLinha(void);
string verifica_Coluna(string);

//void excluirNomeTabela(list<string>);

#endif