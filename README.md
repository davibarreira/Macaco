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
* Macaco_Notebook_Showcase.ipynb - Notebook com showcase da biblioteca.
Dê uma olhada para ver um exemplo prático de como utilizá-la;
* Imagem/  - Pasta com imagens utilizadas no README.md;
* Testes/  - Pasta com dois scripts de Python utilizados para testar a bibliotca. Script TestingMacaco_Iris.py compara os resultados do Macaco com
a biblioteca Pandas. Script TestingMacaco.py roda funções padrão do 
dataframe, garantindo assim a execução sem erros.

## Requerimentos
Essa biblioteca utiliza `C++17` e `Python 3.6`. Durante a instalação do 
pacote Macaco, são instaladas também a biblioteca Matplotlib e Tabulate.
Para rodar o TestingMacaco_Iris.py é necessário ter também instalada a 
biblioteca Pandas, Numpy e Seaborn do Python.

Note que os binários do C++ já vem junto com o repositório. Eles foram
compilados em Linux, portanto, é possível que não funcione diretamente
em outros sistema Operacionais, sendo assim necessário que o usuário
compile novamente os arquivos. Caso seja o caso, o usuário precisará
instalar a biblioteca Boost com Python Boost em seu computador, junto
com um compilador para C++17.

## Documentação do Código
Abaixo mostramos a estrutura geral do código. Ele é composto por três
arquivos principais que já falamos na sessão de "Estrutura do Repositório".

![alt text](./Imagem/EstruturaCodigo.png)   