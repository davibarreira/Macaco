from DataFrame import *
from matplotlib import pyplot as plt

class DataFrameMc():
    """docstring for DataFrameMc"""
    def __init__(self,dados=None):
        self.df      = DataFrame()
        self.colunas = {}
        self.shape   = [0,0] # Quantidade de linhas x colunas
        self.indices = []

        if dados != None:
            for coluna in dados:
                self.InserirColuna(dados[coluna],str(coluna))


    def InserirColuna(self,valores,nome_coluna):
        # Infere o tipo do dado. Caso encontre multiplos,
        # transforma em string

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
        if self.colunas[nome_coluna] == 'int':
            return self.df.GetColunaInt(nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.GetColunaDouble(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.GetColunaString(nome_coluna)

    def RemoverColuna(self,nome_coluna):
        if self.colunas[nome_coluna] == 'int':
            self.df.RemoverColunaInt([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1
        elif self.colunas[nome_coluna] == 'double':
            self.df.RemoverColunaDouble([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1
        elif self.colunas[nome_coluna] == 'string':
            self.df.RemoverColunaString([],nome_coluna)
            self.colunas.pop(nome_coluna)
            self.shape[1] = self.shape[1] - 1

    def RemoverLinha(self, linhas):
    	self.df.RemoverLinha(linhas)
    	self.shape[0] = self.shape[0] - len(linhas)
    	indices = list(self.indices)
    	for i in indices:
    		self.IndexarColuna(i)

    def GetLoc(self,linha, nome_coluna):
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
        resultado = {k: [] for k in self.colunas}
        for nome_coluna in self.colunas:
            resultado[nome_coluna].append(self.GetLoc(linha, nome_coluna))
        return resultado

    def GetDados(self):
        return self.GetLinha(range(0,self.shape[0]))

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
        if self.colunas[nome_coluna] == 'int':
            self.df.RemoverIndiceInt([], nome_coluna)
            self.indices.remove(nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            self.df.RemoverIndiceDouble([], nome_coluna)
            self.indices.remove(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            self.df.RemoverIndiceString([], nome_coluna)
            self.indices.remove(nome_coluna)

    def Query_Valor(self, valor,nome_coluna):
        if self.colunas[nome_coluna] == 'int':
            return self.df.GetNodeRowsInt(valor, nome_coluna)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.GetNodeRowsDouble(valor, nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.GetNodeRowsString(valor, nome_coluna)

    def Query_Tree(self, nome_coluna, operador,valor):
        if self.colunas[nome_coluna] == 'int':
            return self.df.QueryTreeInt([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.QueryTreeDouble([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.QueryTreeString([valor],nome_coluna, operador)


    def Query_Simples(self, nome_coluna, operador, valor):
        if self.colunas[nome_coluna] == 'int':
            return self.df.QuerySimpleInt([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'double':
            return self.df.QuerySimpleDouble([valor],nome_coluna, operador)
        elif self.colunas[nome_coluna] == 'string':
            return self.df.QuerySimpleString([valor],nome_coluna, operador)





    # def Query()


    # Funções de Visualização dos Dados (gráficos)

    def Plot(self,nome_coluna1,nome_coluna2):
        x = self.GetColuna(nome_coluna1)
        y = self.GetColuna(nome_coluna2)
        plt.plot(x,y,'o')
