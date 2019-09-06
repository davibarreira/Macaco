import Macaco as mc

data = {'col_1': [3, 2, 1, 0], 'col_2': ['a', 'b', 'c', 'd']}
df = mc.DataFrameMc(data)


df.InserirColuna(['davi','b','z','z'],'col_3')
df.InserirColuna([2.3,3.14,1,2.0],'col_2')
df.InserirColuna([2.3,3.14,1,2.0],'col_4')

print(df.GetColuna('col_1'))
print(df.GetColuna('col_2'))

df.RemoverColuna('col_2')
# print(df.GetColuna('col_2'))

print(df.GetLoc([0,1,2],'col_1'))
print(df.GetLoc(0,'col_3'))
print(df.shape)
print(df.GetLoc([1,2,3],'col_4'))
print(df.GetLinha([1,2]))

# for nome_coluna in df.colunas:
#     print(nome_coluna)
#     print(df.GetLoc(1,nome_coluna))