# SGBD
**Sistema de gerenciamento de banco de dados**

## Para compilar e executar: 
Clone o repositório e, **dando cd no diretório criado**, utilize o comando 'make' para gerar o arquivo executável. Depois disso, digite ./exe  no terminal de comandos para executar o programa.
 
```
git clone https://github.com/htmluke/SGBD
make
./exe

```
## Sobre o projeto
Nesse projeto, programdo em **c++**, foi feito a simulação das operações de um bando de dados relacional, permitindo que o usuário crie tabelas, nomeie-as, adicione/exclua elementos nas tabelas, além de poder pesquisar dados e, também, excluir o arquivo em .csv gerado.

## Funcionalidades
As funcionalidades do programa foram dividas em duas secções, a primeira, referente às classes/srtucts, lida com os métodos criados, trabalhando com a noção de **Orientação a Objeto** das tabelas e colunas do projeto. Em seguida, na segunda secção, foram selecionadas as funções gerais do probrama, que trabalham em conjunto com o arquivo de classes, mas realizando funções independentes que auxiliam o código como um todo.

### Classes
* **Tabela**
Classe tabela contendo os atributos: chave primária, chave estrangeira e um vector de structs representando as colunas. Sua função, enquanto orientação a objeto, é de realizar as "ações" de uma tabela de um bando de dados relacional, sendo inicializada por seu construtor e deletada pelo destrutor.
* **Coluna**
Struct coluna, armazenando o nome da coluna e, também, o seu tipo (int, float, string, etc), realizando, enquanto orientação a objeto, a função de uma coluna de uma tabela presente em um bando de dados relacional.
### Funções
* **Menu**
Função que realiza a impressão, a partir de cout, de um menu, dado as opções que o usuário pode realizar no main.cpp, sendo impresso sempre que o usuário quiser realizar algo que não seja a opção de sair do programa.
* **Criar Tabela**
Conjunto de funções que realizam a criação da tabela. A partir da entrada do usuário, como o nome da tebla, o tipo dos dados e, também, o conteúdo da tabela, definindo o documento que, por fim, é gerado em arquivo .csv que é salvo na pasta **/tabelas**.
* **Listar Tabela**
Função que realiza a listagem das tabelas já criadas pelo usuário, a partir da biblioteca **<dirent.h>**, o programa pode adentrar o diretório criado para armazenar os arquivos .csv e, depois disso, iterar entre eles para poder os listar, realizando a impressão de todos os arquivos ou de nenhum, caso não haja documentos.
* **Inserir Linha**
Com o intuito de aumentar o tamanho da tabela para inserir mais informações, a função de inserir tabela realiza justamente a funçaõ de inserir mais um espaço em baixo da tabela(arquivo .csv), fazendo com que o usuário tenha mais campos de inserção de dados.
* **Pesquisar Dado**
A função de pesquisar dado realiza justamente uma função de pesquisa, acessando o documento criado(a tabela) ele pode se deslocar pelos campos da tabela para encontrar o dado desejado pelo usuário, retornando uma resposta afirmativa, para o caso de encontrar o que lhe foi requisitado, ou uma resposta negativa, quando não se há informação que supra o que o usuário solicitou.
* **Excluir Dado**
Função que realiza a exclusão de dados selecionados pelo usuário. A partir da entrada(tabela e dado a ser excluído), data pelo usuário, o programa pesquisa pela tabela desejada e procura a informação que se quer excluir, se o dado existe o programa exclui, se não ele o informa que não há essa informação.
* **Excluir Tabela**
Função que desempenha o papel de remover todo e qualquer arquivo .csv da pasta que se encontra, fazendo com que não haja nenhuma informação acerca dele no programa após sua deleção. 
## O que não foi feito
A única parte não realizada do projeto foi a função referente à exclusão do dado escolhido pelo usuário.
## O que faríamos diferente
Devido ao tempo, que poderia ter sido administrado de outra forma mais adequada, alguns detalhes deixaram a desejar. Sendo assim, teríamos feito a oganização do projeto de outra forma, de tal forma que todos os pontos desejados fossem cumpridos da melhor forma, chegando a um resultado mais satifatório.

## Autores

* **Lucas Emanoell** - [htmluke](https://github.com/htmluke)
>Estrutura inicial - 
>Estruturação do código - 
>Modularização - 
>Classes e Structs - 
>Listar Tabela - 
>Pesquisar Dado - 
>Todos os Dados (das tabelas)

* **Lucas Oliveira** - [lucasx7](https://github.com/lucasx7)
>Uso de templates - 
>Inserir campo/pkey - 
>Funçãp isCleanString - 
>Verifica Coluna/numString - 
>Inserir Linha - 
>listar Tabela 

* **Nathalia Bezerra** - [nathalia-b](https://github.com/nathalia-b)
>Uso de templates - 
>Inserir campo/pkey - 
>Funçãp isCleanString - 
>Verifica Coluna/numString - 
>Excluir Tabela - 
>Pesquisar Dado - 
>Todos os Dados (das tabelas)
