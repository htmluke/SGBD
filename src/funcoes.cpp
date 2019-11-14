#include <iostream>
#include <string>
#include "classes.hpp"
#include "funcoes.hpp"
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <queue>

using namespace std;

//feito
template <typename T>
T inserir_campo(int tipo, T pKey){
    T aux;   
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
            cin.clear();
            string badToken;
            cin >> badToken;
                            
            
            cout <<"\tDigite um valor: \n";            
        }
    }
    return pKey;
}

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

//feito
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
//feito
bool isCleanString(string a){
for(int i = 0; i < a.size(); i++){
        if((a[i] =='0') || (a[i] =='1') || (a[i] =='2') || (a[i] =='3') || (a[i] =='4') || (a[i] =='5') || (a[i] =='6') || (a[i] =='7') || (a[i] =='8') || (a[i] =='9')){      
            return false;
        }
        else{
            
        }
    }
    return true;
}
//feito
string verifica_Coluna(string a){
    while(!isCleanString(a)){
        if(isCleanString(a)){
            return a;
        }
        else {
            cout << "Digite uma string sem números!\n";
            cin.clear();
            cin.ignore();
            cin >> a;
        }
    }
    return a;
}
//feito
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
//em construção
void inserirLinha(){
    string tabela;
    cout << "Diga o nome da tabela onde deseja inserir uma linha(sem o .csv): ";
    cin >> tabela;

    ifstream aux;

    aux.open("tabelas/"+tabela+".csv", std::ofstream::in);

    string linha;
    getline(aux, linha);
    cout << linha << endl;
    aux.close();
    queue <int> tiposC;
    for(int i = 0; i < linha.size(); i++){
        if(isdigit(linha[i])){
            //cout << linha[i] << endl;
            tiposC.push(linha[i]-'0');
        }
    }

    ofstream tab;

    tab.open("tabelas/"+tabela+".csv", std::ofstream::app);
    int cont = 1;

    while(!tiposC.empty()){
        cout << "Digite o conteudo da coluna " << cont <<": \n";
            cout << tiposC.front() << endl;
            switch(tiposC.front()){
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
                    break;
                default:
                    cout << "Deu merda.\n";
                    break;
            }
            tiposC.pop();
            cont ++;
    }
    tab.close();
    

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
