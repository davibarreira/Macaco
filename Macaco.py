from DataFrame import *
from matplotlib import pyplot as plt
from tabulate import tabulate

class DataFrameMc():
    """Classe DataFrame. Pode ser inicializada recebendo um dicionario como {'coluna1':[1,10],'coluna2':['valor1','valor2']}"""
    def __init__(self,dados=None):
        self.df      = DataFrame() # DataFrame do .cpp
        self.colunas = {}    # Dicionario de colunas com seus respectivos tipos
        self.shape   = [0,0] # Quantidade de linhas x colunas
        self.indices = []    # Colunas indexadas

        # Codigo não aceita valores None.
        if dados != None:
            for coluna in dados:
                self.InserirColuna(dados[coluna],str(coluna))


    def InserirColuna(self,valores,nome_coluna):
        """ 
        Infere o tipo do dado. Caso encontre multiplos,
        transforma em string. Valores devem ser passados dentro de uma lista.
        """

        if all(isinstance(x, int) for x in valores):
            if self.shape == [0,0]:
                self.df.InserirColunaInt(valores,nome_coluna)
                self.colunas[nome_coluna] ='int'
                self.shape[0] = len(valores)
                self.shape[1] += 1
            elif self.shape[0] != len(valores):
                raise Exception("Coluna com tamanhos diferentes.")
            else:
                self.df.InserirColunaInt(valores,nome_coluna)
                self.colunas[nome_coluna] ='int'
                self.shape[1] += 1

        elif all(isinstance(x, (float,int)) for x in valores):
            if self.shape == [0,0]:
                self.df.InserirColunaDouble(valores,nome_coluna)
                self.colunas[nome_coluna] ='double'
                self.shape[0] = len(valores)
                self.shape[1] += 1
            elif self.shape[0] != len(valores):
                raise Exception("Coluna com tamanhos diferentes.")
            else:
                self.df.InserirColunaDouble(valores,nome_coluna)
                self.colunas[nome_coluna] ='double'
                self.shape[1] += 1

        else:
            if not all(isinstance(x, str) for x in valores):
                valores = [str(i) for i in list(valores)]
            if self.shape == [0,0]:
                self.df.InserirColunaString(valores,nome_coluna)
                self.colunas[nome_coluna] ='string'
                self.shape[0] = len(valores)
                self.shape[1] += 1
            elif self.shape[0] != len(valores):
                raise Exception("Coluna com tamanhos diferentes.")
            else:
                self.df.InserirColunaString(valores,nome_coluna)
                self.colunas[nome_coluna] ='string'
                self.shape[1] += 1

    def GetColuna(self,nome_coluna):
        """ 
        Recebe uma coluna e retorna uma lista contendo os valores daquela coluna.
        """
        if self.colunas[nome_coluna] == 'int':
            return self.df.GetColunaInt(nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.GetColunaDouble(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.GetColunaString(nome_coluna)

    def RemoverColuna(self,nome_coluna):
        """ 
        Remove coluna do DataFrame.
        """
        if self.colunas[nome_coluna] == 'int':
            self.df.RemoverColunaInt([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1
            if nome_coluna in self.indices:
            	RemoverIndice(nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            self.df.RemoverColunaDouble([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1
            if nome_coluna in self.indices:
            	RemoverIndice(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            self.df.RemoverColunaString([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1
            if nome_coluna in self.indices:
            	RemoverIndice(nome_coluna)

    def RemoverLinha(self, linhas):
    	self.df.RemoverLinha(linhas)
    	self.shape[0] = self.shape[0] - len(linhas)
    	indices = list(self.indices)
    	for i in indices:
    		self.IndexarColuna(i)

    def GetLoc(self,linha, nome_coluna):
        """
        Recebe lista de linhas e UMA coluna e retorna os respectivos dados.
        """
        linhas = []
        if type(linha) == int:
            linhas.append(linha)
        else:
            linhas = list(linha)

        if max(linhas) > self.shape[0]-1:
            raise Exception("Linha fornecida excedeu o DataFrame")

        if self.colunas[nome_coluna] == 'int':
            return self.df.GetLinhaInt(linhas, nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.GetLinhaDouble(linhas, nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.GetLinhaString(linhas, nome_coluna)

    def GetLinha(self, linha):
        """
        Recebe lista de linhas e retorna dados.
        """
        resultado = {k: [] for k in self.colunas}
        if len(linha) > 0:
	        for nome_coluna in self.colunas:
	            resultado[nome_coluna].append(self.GetLoc(linha, nome_coluna))
	        resultado = {k:v[0] for k,v in resultado.items()}
        return resultado

    def GetDados(self):
        """
        Retorna todo os dataframe em formato de dicionario.
        """
        return self.GetLinha(range(0,self.shape[0]))

    def Slice(self, linhas,nome_colunas):
        """
        Recebe lista de linhas e lista de colunas e retorna os dados respectivos
        em formato de dicionario.
        """
        if len(linhas) == 0:
            linhas = list(range(0,self.shape[0]))
        if len(nome_colunas) == 1:
            slc = self.GetLoc(linhas,nome_coluna2)
        else:
            slc = {k:[] for k in nome_colunas}
            for k in slc:
                slc[k] = self.GetLoc(linhas,k)
        return slc 



    def Show(self, dados):
        # Recebe dicionario e printa em formato tabular
    	print(tabulate(dados,tablefmt='simple',headers='keys'))

    def InserirLinha(self,valores):
        num_linhas = [len(valores[i]) for i in valores][0]
        if len(set([len(valores[i]) for i in valores]))>1:
            raise Exception("Colunas com tamanhos de linhas diferentes")
        for nome_coluna in self.colunas:
            if self.colunas[nome_coluna] == 'int':
                self.df.InserirLinhaInt(valores[nome_coluna],nome_coluna)
            elif self.colunas[nome_coluna] == 'double':
                self.df.InserirLinhaDouble(valores[nome_coluna],nome_coluna)
            elif self.colunas[nome_coluna] == 'string':
                self.df.InserirLinhaString(valores[nome_coluna],nome_coluna)
        self.shape[0] += num_linhas

    def IndexarColuna(self, nome_coluna):
        """
        Recebe nome de coluna e indexa.
        """
        if self.colunas[nome_coluna] == 'int':
            self.df.IndexarColunaInt([], nome_coluna)
            self.indices.append(nome_coluna)
            self.indices = list(sorted(set(self.indices)))
        elif self.colunas[nome_coluna] == 'double':
            self.df.IndexarColunaDouble([], nome_coluna)
            self.indices.append(nome_coluna)
            self.indices = list(sorted(set(self.indices)))
        elif self.colunas[nome_coluna] == 'string':
            self.df.IndexarColunaString([], nome_coluna)
            self.indices.append(nome_coluna)
            self.indices = list(sorted(set(self.indices)))

    def RemoverIndice(self, nome_coluna):
        """
        Remove indice.
        """
        if self.colunas[nome_coluna] == 'int':
            self.df.RemoverIndiceInt([], nome_coluna)
            self.indices.remove(nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            self.df.RemoverIndiceDouble([], nome_coluna)
            self.indices.remove(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            self.df.RemoverIndiceString([], nome_coluna)
            self.indices.remove(nome_coluna)

    def Query_Tree(self, nome_coluna, operador,valor):
        """
        Usuario deve usar funcao Query. Essa eh um funcao auxiliar
        para fazer query na arvore binaria.
        """
        if self.colunas[nome_coluna] == 'int':
            return self.df.QueryTreeInt([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.QueryTreeDouble([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.QueryTreeString([valor],nome_coluna, operador)


    def Query_Simples(self, nome_coluna, operador, valor):
        """
        Usuario deve usar funcao Query. Essa eh um funcao auxiliar
        para fazer query sem arvore.
        """
        if self.colunas[nome_coluna] == 'int':
            return self.df.QuerySimpleInt([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.QuerySimpleDouble([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.QuerySimpleString([valor],nome_coluna, operador)

    def Query(self, nome_coluna, operador, valor):
        # Funcao para fazer query no dataframe. Operadores sao '==','<','<=','>','>='
    	if nome_coluna in self.indices:
    		return self.Query_Tree(nome_coluna,operador,valor)
    	else:
    		return self.Query_Simples(nome_coluna, operador, valor)

    def QueryRect(self, queryrect, nome_coordenada1, nome_coordenada2):
        """
        Exige que colunas de coordenadas sejam de double.
        queryrect = [xmin,ymin,xman,yman]
        """
        if self.colunas[nome_coordenada1] != 'double' or self.colunas[nome_coordenada2] != 'double':
            raise Exception('Colunas com coordenadas devem ser de doubles')
        if nome_coordenada1 in self.indices and nome_coordenada2 in self.indices:
            if len(queryrect) != 4 or not all(isinstance(x, (float,int)) for x in queryrect):
                raise Exception('queryrect deve ser uma lista com 4 valores numericos')
            return self.df.QueryRect(queryrect, nome_coordenada1, nome_coordenada2)

        else:
            raise Exception("Colunas de coordenadas precisam estar indexadas")




    # Funções de Visualização dos Dados (gráficos)

    # Funcao abaixo faz scatter plots e line plots.
    # Podem ser utilizados os mesmo argumentos que para o pyplot do matplotlib
    def Plot(self,nome_coluna1,nome_coluna2, *args,**kwargs):
        x = self.GetColuna(nome_coluna1)
        y = self.GetColuna(nome_coluna2)
        plt.plot(x,y,*args,**kwargs)

    def Hist(self,nome_coluna1, *args,**kwargs):
        x = self.GetColuna(nome_coluna1)
        plt.hist(x,*args,**kwargs)

    def Hist2D(self,nome_coluna1, nome_coluna2,*args,**kwargs):
        x = self.GetColuna(nome_coluna1)
        y = self.GetColuna(nome_coluna2)
        plt.hist2d(x,y,*args,**kwargs)

    def BarPlot(self, coluna_altura, coluna_posicao, tipo='soma',*args, **kwargs):
        altura   = self.GetColuna(coluna_altura)
        posicao  = self.GetColuna(coluna_posicao)
        categorias = sorted(list(set(self.GetColuna(coluna_posicao))))
        soma     = {k:0 for k in categorias}
        contador = {k:0 for k in categorias}
        media    = {k:0 for k in categorias}
        for cat in categorias:
            for i in range(len(self.GetColuna(coluna_altura))):
                if posicao[i] == cat:
                    contador[cat]+=1
                    soma[cat]+=altura[i]
        for cat in categorias:
            media[cat] = soma[cat]/contador[cat]

        if tipo == 'soma':
            plt.bar(soma.keys(),soma.values(),*args,**kwargs)
        if tipo == 'media':
            plt.bar(media.keys(),media.values(),*args,**kwargs)
        if tipo == 'contador':
            plt.bar(contador.keys(),contador.values(),*args,**kwargs)
