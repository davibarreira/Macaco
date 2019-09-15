import Macaco as mc
from matplotlib import pyplot as plt

data = {'col_1': [3, 3, 3, 0], 'col_2': ['a', 'b', 'c', 'd']}
df = mc.DataFrameMc(data)


df.InserirColuna(['davi','b','z','z'],'col_3')
df.InserirColuna([2.3,3.14,1,2.0],'col_2')
df.InserirColuna([2.3,3.14,3.14,2.0],'col_4')

print(df.GetColuna('col_1'))
print(df.GetColuna('col_2'))

df.RemoverColuna('col_2')
# print(df.GetColuna('col_2'))
print(df.colunas)

print(df.GetLoc([0,1,2],'col_1'))
print(df.GetLoc(0,'col_3'))
print(df.shape)
print(df.GetLoc([1,2,3],'col_4'))
print(df.GetLinha([1,2]))
print(df.GetDados())

row = {'col_1':[100,3],'col_3':['InserirLinha','Ok'],'col_4':[700.17,99]}
df.InserirLinha(row)
print(df.colunas)
print(df.GetDados())

df.InserirColuna([2.3,3.14,1,2.0,'davi','ok'],'col_5')
print(df.GetDados())

df.IndexarColuna('col_1')
df.IndexarColuna('col_3')
df.IndexarColuna('col_4')
row = {'col_1':[100,3],'col_3':['z','z'],'col_4':[700.17,3.14], 'col_5':['19','90']}
df.InserirLinha(row)
print(df.GetDados())

print(df.Query_Valor([3,100],'col_1'))
print(df.Query_Valor(['z'],'col_3'))
print(df.Query_Valor([3.14],'col_4'))



# Funcao para testar plotagem do grafico
fig = df.Plot('col_1','col_3')
plt.show()


# for nome_coluna in df.colunas:
#     print(nome_coluna)
#     print(df.GetLoc(1,nome_coluna))
