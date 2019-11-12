#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "classes.hpp"
#include "funcoes.hpp"
using namespace std;

Tabela::Tabela(){}

bool compareString_Number(char a){

	if((a =='0') || (a =='1') || (a =='2') || (a =='3') || (a =='4') || (a =='5') || (a =='6') || (a =='7') || (a =='8') || (a =='9')){
		return true;
	}
	else{
		return false;
	}
}

bool verficar_numString(string a){
	for(int i = 0; i < a.size(); i++){
		if(a[0] == '-'){
		}
		else if((a[i] =='0') || (a[i] =='1') || (a[i] =='2') || (a[i] =='3') || (a[i] =='4') || (a[i] =='5') || (a[i] =='6') || (a[i] =='7') || (a[i] =='8') || (a[i] =='9')){		
		}
		else{
			return false;
		}
	}
	return true;
}

Tabela::Tabela(int chavePrimaria, int chaveEstrangeira, int tam, list<string> lista){
	cout <<"Qual será o nome da tabela ?\n";
	cout << "\t";
	string nome;
	cin >> nome;

	//Acessa a função da lista que armazena o nome da tabela
	inserirLista(nome, lista);

	ofstream tab;
    /*Abre um arquivo externo que será a tabela criada*/ 
    tab.open("tabelas/"+nome+".csv", std::ofstream::out );

    this->chavePrimaria = chavePrimaria;
    this->chaveEstrangeira = chaveEstrangeira;
    this->tam = tam;
    this->v = new Colunas[tam];
  
    for(int i = 0; i < tam; i++){
    	if(i == 0){

    		cout << "Qual será o nome da coluna da chave primária ?\n";
    		cout << "\t";
    		cin >> this->v[0].nome;
    		this->v[0].tipo = 1;
    		tab << this->v[0].nome+",";
    	}
    	else {
    		cout <<"Qual será o nome da coluna de número " << i+1 << " ?\n";
    		cout << "\t";
	    	cin >> this->v[i].nome;
	    	tab << this->v[i].nome+",";
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
	    	
	    		cin >> t;
	    	}
	    	this->v[i].tipo = t;
	    }	    
    }
    tab << endl;
	string pKey;
	bool control = false;
	    
	while(!control){
	  	control = true;
	  	cout << "Qual será o valor da chave primária ?\n";
	  	cout << "\t";
	  	cin >> pKey;
	   	try{
	   		if(!verficar_numString(pKey)){
	   			throw (1);
	   		}
	   		tab << pKey+",";
	   		control = true;	   		
	   	} catch(int erro){
	   		if(erro == 1){
	   			cout << "Valor digitado invalido! Digite um valor válido.\n";
	   		}	   		
	   		cin.clear();
	   		cin.ignore();
	   		control = false;
	   	}
	   	
	   	
	}
}

Tabela::~Tabela(){
}