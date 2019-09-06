from DataFrame import *

class DataFrameMc():
    """docstring for DataFrameMc"""
    def __init__(self,dados=None):
        self.df = DataFrame()
        self.colunas = []
        if dados != None:
            for coluna in dados:
                self.InserirColuna(dados[coluna],coluna)


    def InserirColuna(self,valores,nome_coluna):
        # Infere o tipo do dado. Caso encontre multiplos,
        # transforma em string

        if all(isinstance(x, int) for x in valores):
            self.df.InserirColunaInt(valores,nome_coluna)
            self.colunas.append((nome_coluna,'int'))

        elif all(isinstance(x, (float,int)) for x in valores):
            self.df.InserirColunaDouble(valores,nome_coluna)
            self.colunas.append((nome_coluna,'double'))

        elif all(isinstance(x, str) for x in valores):
            self.df.InserirColunaString(valores,nome_coluna)
            self.colunas.append((nome_coluna,'string'))
        else:
            valores_string = [str(i) for i in list(valores)]
            self.df.InserirColunaString(valores_string,nome_coluna)
            self.colunas.append((nome_coluna,'string'))


    # def GetLinha(linha)
    # def GetColuna(coluna)
    # def GetLoc(linha,coluna)
