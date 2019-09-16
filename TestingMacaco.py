import Macaco as mc
from matplotlib import pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np

data = {'col_1': [3, 3, 3, 0], 'col_2': ['a', 'b', 'c', 'd']}
df = mc.DataFrameMc(data)


df.InserirColuna(['davi','b','z','z'],'col_3')
df.InserirColuna([2.3,3.14,1,2.0],'col_2')
df.InserirColuna([2.3,3.14,3.14,2.0],'col_4')

print(df.GetColuna('col_1'))
print(df.GetColuna('col_2'))

df.RemoverColuna('col_2')
print(df.colunas)

print(df.GetLoc([0,1,2],'col_1'))
print(df.GetLoc(0,'col_3'))
print(df.shape)
print(df.GetLoc([1,2,3],'col_4'))
df.Show(df.GetLinha([1,2]))
df.Show(df.GetDados())

row = {'col_1':[100,3],'col_3':['InserirLinha','Ok'],'col_4':[700.17,99]}
df.InserirLinha(row)
print(df.colunas)
df.Show(df.GetDados())

df.InserirColuna([2.3,3.14,1,2.0,'davi','ok'],'col_5')
df.Show(df.GetDados())

df.IndexarColuna('col_1')
df.IndexarColuna('col_3')
df.IndexarColuna('col_4')
row = {'col_1':[100,3],'col_3':['z','z'],'col_4':[700.17,3.14], 'col_5':['19','90']}
df.InserirLinha(row)

df.Show(df.GetDados())

df.RemoverLinha([0,1,2])
print(df.indices)

df.Show(df.GetDados())

print(df.Query_Simples('col_1',"<=",3))
print(df.Query_Tree('col_1',"<=",3))
print(df.Query('col_1',"<=",3))

print(df.Query_Simples('col_4',">",99))
print(df.Query_Tree('col_4',">",99))
print(df.Query('col_4',">",99))

print(df.Query_Simples('col_3',"==","z"))
print(df.Query_Tree('col_3',"==","z"))
print(df.Query('col_3',"==","z"))

df.RemoverIndice('col_1')
print(df.indices)

df.IndexarColuna('col_1')
print(df.indices)
df.Show(df.GetDados())
queryrect = [1,5,100,100]
print(df.QueryRect(queryrect, 'col_4','col_4'))




# Funcao para testar plotagem do grafico
fig = df.Bar('col_1','col_3')
plt.show()
fig = df.Bar('col_1','col_3','media')
plt.show()
fig = df.Bar('col_1','col_3','contador')
plt.show()
fig = df.Plot('col_1','col_4','o')
plt.show(fig,)
fig = df.Hist('col_1')
plt.show()
fig = df.Hist2D('col_1','col_4')
plt.show()


