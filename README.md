# Macaco - DataFrame C++/Python 
## Projeto Final do curso de Algoritmos e Estrutura de Dados
Autores: Davi Barreira, Flavio Fontanella
![alt text](./Imagem/Macaco_Image.png)   

## Descrição
Este trabalho consistiu na criação de uma biblioteca entitulada **Macaco**
com funcionalidades parecidas com a famosa biblioteca Pandas do Python,
porém, nossa biblioteca utiliza [Python Boost](https://www.boost.org/doc/libs/1_70_0/libs/python/doc/html/index.html)
para realizar a integração do código de C++ com Python, utilizando o Python como interface
com o usuário.

## Instalação

Para se instalar o pacote basta clonar o repositório, entrar na sua pasta e executar:
```sh
pip install -e .
```
Recomenda-se utilizar um ambiente virtual para não instalar o pacote no seu Python nativo.

## Estrutura da Repositório
Uma breve explicação sobre os arquivos deste repositório:
* Macaco.py     - Modulo de Python contendo a biblioteca Macaco;
* DataFrame.cpp - DataFrame implementado em C++ utilizado pelo modulo Macaco;
* DataFrame.o , DataFrame.so - Arquivos binários utulizados pelo
Python Boost para importação dos arquivo em C++;
* BST.cpp - Estrutura de árvore binária utilizada pelo DataFrame.cpp;
* compile_pyboost.sh - Script para compilar o código de C++;
* setup.py - Arquivo com informações sobre a instalação do pacote Macaco;
* Imagem/  - Pasta com imagens utilizadas no README.md;
* Testes/  - Pasta com dois scripts de Python utilizados para testar a bibliotca. Script TestingMacaco_Iris.py compara os resultados do Macaco com
a biblioteca Pandas. Script TestingMacaco.py roda funções padrão do 
dataframe, garantindo assim a execução sem erros.


