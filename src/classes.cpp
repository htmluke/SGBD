#include <iostream>
#include <fstream>
#include <string>
#include "classes.hpp"
#include "funcoes.hpp"
#include <ctype.h>
using namespace std;

//função responsável por garantir que a informação dada pelo usuário pode ser inseriada na tabela;
template <typename T>
T inserir_campo(int tipo, T pKey){
	bool control = true;
    while(control){
        try{
            cin >> pKey;
            if(cin.fail()){
                throw 1;
            } 
            else {
            	cout << "Valor aceito.\n";
                return pKey;
            }
        }catch(int n){
            cout << "Digite um valor válido para o tipo esperando.\n";
            cout << "Tipo esperado é " << tipo << endl;
            cout <<"\t1_____ int\n";
            cout <<"\t2_____ float\n";
            cout <<"\t3_____ double\n";
            cout <<"\t4_____ char\n";
            cout <<"\t5_____ string\n";
            //limpando o cin
            cin.clear();
            string badToken;
        	cin >> badToken;
                        	
            
            cout <<"\tDigite um valor: \n";            
        }
    }
    return pKey;
}

Tabela::Tabela(){

	cout <<"Qual será o nome da tabela ?\n";
	cout << "\t";
	string nome;
	cin >> nome;
	unsigned int tam;
	cout <<"Quantas colunas a tabela terá ?\n";
	tam = inserir_campo<int>(1,-1);

	//Acessa a função da lista que armazena o nome da tabela
	//inserirLista(nome, lista);

	ofstream tab;
    /*Abre um arquivo externo que será a tabela criada*/ 
    tab.open("tabelas/"+nome+".csv", std::ofstream::out );

    this->chavePrimaria = chavePrimaria;
    this->chaveEstrangeira = chaveEstrangeira;
    this->tam = tam;
    this->v = new Colunas[tam];

    string nColuna;
  
    for(int i = 0; i < tam; i++){
    	if(i == 0){

    		cout << "Qual será o nome da coluna da chave primária ?\n";
    		cout << "\t";
    		cin >> nColuna;
    		nColuna = verifica_Coluna(nColuna);
    		this->v[0].nome = nColuna;
    		this->v[0].tipo = 1;
    		if(i+1 == tam){
    			tab << this->v[0].nome;
    			tab << this->v[0].tipo;
    		}
    		else {
    			tab << this->v[0].nome;
    			tab << this->v[0].tipo;
    			tab << ",";
    		}
    	}
    	else {
    		cout <<"Qual será o nome da coluna de número " << i+1 << " ?\n";
    		cout << "\t";
	    	cin >> nColuna;
	    	nColuna = verifica_Coluna(nColuna);
    		this->v[i].nome = nColuna;
	    	
	    	int t;    	
	    	cout <<"Diga qual será o tipo de valor que coluna vai armazenar.\n";
	    	cout <<"\t1_____ int\n";
	    	cout <<"\t2_____ float\n";
	    	cout <<"\t3_____ double\n";
	    	cout <<"\t4_____ char\n";
	    	cout <<"\t5_____ string\n";
	    	
	    	cin >> t;
	    	while(t > 5 || t < 1){
	    		cout <<"Nenhuma opção válida selecionada.\n";
	    		cout <<"\nDiga qual será o tipo de valor que coluna vai armazenar.\n";
	    		cout <<"\t1_____ int\n";
	    		cout <<"\t2_____ float\n";
	    		cout <<"\t3_____ double\n";
	    		cout <<"\t4_____ char\n";
	    		cout <<"\t5_____ string\n";
	    		cin.clear();
	    		cin.ignore();
	    		cin >> t;
	    	}
	    	this->v[i].tipo = t;
	    	tab << this->v[i].nome;
	    	tab << this->v[i].tipo;
    		tab << ",";
	    }	    
    } //.
    tab << endl;
    //
    
	int cont = 1;
	int s = -1;
	cout << "Qual será o valor da chave primária ?\n";
	cout << "\t";
	tab <<  inserir_campo(1, -1);
	tab << ",";
	cout << "Deseja preencher os demais campos da linha ? Digite 1 para sim e qualquer coisa para não\n";
	cin >> s;
	while(cont < tam){		
		if(s != 1){
			cin.clear();
            string badToken;
        	cin >> badToken;
			break;
		}
		else {
			cout << "Digite o conteudo da coluna " << cont+1 <<": \n";
			switch(this->v[cont].tipo){
				case 1:
					tab << inserir_campo(1, -1);
					tab << ",";
					break;
				case 2:
					tab << inserir_campo<float>(2, -1.0);
					tab << ",";
					break;
				case 3:
					tab << inserir_campo<double>(3, -1.000);
					tab << ",";
					break;
				case 4:
					tab << inserir_campo<char>(4, '0');
					tab << ",";
					break;
				case 5:
					tab << inserir_campo<string>(5, "");
					tab << ",";
			}
			cont ++;
		}
	}
	tab << endl;	

	tab.close();
}

Tabela::~Tabela(){
}