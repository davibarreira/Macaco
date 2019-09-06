from DataFrame import *

class DataFrameMc():
    """docstring for DataFrameMc"""
    def __init__(self,dados=None):
        self.df      = DataFrame()
        self.colunas = {}
        self.shape   = [0,0] # Quantidade de linhas x colunas

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
                valores_string = [str(i) for i in list(valores)]
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
        elif self.colunas[nome_coluna] == 'double':
            self.df.RemoverColunaDouble([],nome_coluna)
            self.colunas.pop(nome_coluna)
        elif self.colunas[nome_coluna] == 'string':
            self.df.RemoverColunaString([],nome_coluna)
            self.colunas.pop(nome_coluna)

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






    # def GetLinha(linha)
    # def GetColuna(coluna)
    # def GetLoc(linha,coluna)
    # def Query()
