from DataFrame import *

class DataFrameMc():
    """docstring for DataFrameMc"""
    def __init__(self):
        self.df = DataFrame()

    def InserirColuna(self,valores,nome_coluna):
        # Infere o tipo do dado. Caso encontre multiplos,
        # transforma em string

        if all(isinstance(x, int) for x in valores):
            self.df.InserirColunaInt(valores,nome_coluna)

        if all(isinstance(x, (float,int)) for x in valores):
            self.df.InserirColunaDouble(valores,nome_coluna)

        else all(isinstance(x, str) for x in valores):
            self.df.InserirColunaString(valores,nome_coluna)
