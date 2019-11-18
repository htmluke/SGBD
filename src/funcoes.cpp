#include <iostream>
#include <string>
#include <dirent.h>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <queue>
#include <vector>
#include "classes.hpp"
#include "funcoes.hpp"



using namespace std;

//feito
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
            cin.clear();
            string badToken;
            cin >> badToken;
                            
            
            cout <<"\tDigite um valor: \n";            
        }
    }
    return pKey;
}

//função para garantir que o campo
int inserir_pKey(){

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
void listarTabelas(string nomeDir){
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
    //cout << linha << endl;
    
    queue <int> tiposC;
    for(int i = 0; i < linha.size(); i++){
        if(isdigit(linha[i])){
            //cout << linha[i] << endl;
            tiposC.push(linha[i]-'0');
        }
    }

    string pkey;
    int chavesPrimarias[tiposC.size()];
    int indicePkey = 0;
    while(!aux.eof()){
        getline(aux, linha);
        for(int i = 0; i < linha.size(); i++){
            if(linha[i] != ','){
                pkey += linha[i];
            }
            else {
            	chavesPrimarias[indicePkey] = stoi(linha);
            	indicePkey ++;
            	linha = "";
            }
        }
    }

    aux.close();

    ofstream tab;

    tab.open("tabelas/"+tabela+".csv", std::ofstream::app);
    int cont = 1;
    int finalFila = tiposC.size();

    while(!tiposC.empty()){
        cout << "Digite o conteudo da coluna " << cont <<": \n";
            cout << "É esperado informação do tipo: " << tiposC.front() << endl;
            switch(tiposC.front()){
                case 1:
                    if(cont == 1){
                    	int pkeyTemp;
                    	bool control = true;
                    	while(control){
                    		//variavel para armazenar temporariamente o dado que o usuário dá para ser a chave primária.
                    		pkeyTemp = inserir_campo(1, -1);
                    		control = false;
                    		for(int i = 0; i < indicePkey+1; i++){
	                    		if(pkeyTemp == chavesPrimarias[i]){
	                    			cout << "Essa chave primária já existe na tabela.\n Digite uma chave primária diferente.\n";
	                    			control = true;
	                    			break;
	                    		}
                    		}
                    	}
                    	tab << pkeyTemp;
                    	tab << ",";                     	
                    }
                    else {
                    	tab << inserir_campo(1, -1);
                    	tab << ","; 
                    }
                    
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
                    cout << "Houve um problema :(" << endl;
                    break;
            }
            
            tiposC.pop();
            cont ++;
            
            
    }
    tab << endl;
    tab.close();
    

}

 void excluirTabela(){

     string tabelaRm, auxiliar;
     int option;
     bool aux = false;

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

void pesquisarDado(){

    ifstream leitura;

    string dado, nome, palavra, s;
    vector<string> strings;
    bool aux = false, control = true;
    int option, k = 0;
    double numeros[100];
    
    cout << "Digite o nome do arquivo: " << endl << "\t";
    cin >> nome;
    leitura.open("tabelas/"+nome+".csv");
    if(leitura.fail() == true)
    {
        cout << "Impossível ler o arquivo, tente novamente." << endl;
        return;
    }

    cout << "Digite o dado:" << endl << "\t";
    cin >> dado;    
    cout << "O que você deseja?\n" << endl;
    cout << "\t1. Valores maiores que o informado" << endl << "\t2. Valores maiores ou iguais ao informado" << endl << "\t3. Valores iguais ao informado" << endl;
    cout << "\t4. Valores menores que o informado" << endl << "\t5. Valores menores ou iguais ao informado" << endl;
    cout << "Obs: Se o que estiver sendo procurado for uma palavra, as opções acima serão em relação a ordem alfabética. Se ele for maior, virá depois da sua entrada; se menor, antes." << endl << "\t";
    cin >> option;
    getline(leitura, s);
    while (getline(leitura, s, ',') && aux == false) {
        strings.push_back(s);
        
        if(verficar_numString(dado)){ //se o dado recebido for um número:
          
            if(verficar_numString(s)){ //se a string atual for um numero, joga num vetor de floats.
                numeros[k] = stod(s);
                if(option == 1){
                        if(numeros[k] > stod(dado)){
                         cout << "Encontrado: " << s << endl;
                         control = false;;
                        }
                        
                }else if(option == 2){
                        if(numeros[k] >= stod(dado)){
                         cout << "Encontrado: " << s << endl;
                         control = false;
                        }
                }else if(option == 3){
                        if(numeros[k] == stod(dado)){
                        cout << "Encontrado: " << s << endl;
                        control = false;
                        }
                }else if(option == 4){
                        if(numeros[k] < stod(dado)){
                          cout << "Encontrado: " << s << endl; //caso
                          control = false;
                        }
                }else if(option == 5){
                        if(numeros[k] <= stod(dado)){
                          cout << "Encontrado: " << s << endl; //caso
                          control = false;
                        }
                }else{
                    cout << "Opção inválida, tente novamente." << endl;
                }
            }
        }else{
                 if(option == 1){
                        if(s > dado){
                         cout << "Encontrado: " << s << endl;
                         control = false;
                        }
                        
                }else if(option == 2){
                        if(s >= dado){
                         cout << "Encontrado: " << s << endl;
                         control = false;
                        }
                }else if(option == 3){
                        if(s == dado){
                        cout << "Encontrado: " << s << endl;
                        control = false;
                        }
                }else if(option == 4){
                        if(s < dado){
                          cout << "Encontrado: " << s << endl; //caso
                          control = false;
                        }
                }else if(option == 5){
                        if(s <= dado){
                          cout << "Encontrado: " << s << endl; //caso
                          control = false;
                        }
                }else{
                    cout << "Opção inválida, tente novamente." << endl;
                }       
        }


        k++;
        
        
            
    }

    if(control){
    cout << "Dado não encontrado." << endl;
    }
            
        
    
    leitura.close();


}

void todosOsDados(){

    ifstream leitura;
    string nome, linha;
    vector<string> strings;
    cout << "Digite o nome do arquivo que você deseja visualizar: " << endl << "\t";
    cin >> nome;
    leitura.open("tabelas/"+nome+".csv");
    
    if(leitura.fail() == true)
    {
        cout << "Impossível ler o arquivo, tente novamente." << endl;
        return;
    }

    while(!leitura.eof()){

        getline(leitura, linha);
        cout << linha << endl;
    }
}
