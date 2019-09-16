import Macaco as mc
from matplotlib import pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np


#############################################################################
# Arquivo contendo testes para o DataFrame. Compara as                      #
# queries realizadas pela biblioteca Macaco vs as queries utilizando Pandas.#
# O teste utiliza a famosa base de dados iris.                              #
#############################################################################


print('Iniciando os testes.')

iris = sns.load_dataset('iris')
data = iris.to_dict('list')
df = mc.DataFrameMc(data)

# Testando queries sem indexação

species = pd.unique(iris['species'])
for i in species:
    assert df.GetLinha(df.Query('species','==',i)) == iris[iris['species']==i].to_dict('list')

colunas = iris.columns[0:-1]
for col in colunas:
    for i in np.linspace(iris[col].min(),iris[col].max()):
        assert df.GetLinha(df.Query(col,'<',i)) == iris[iris[col]<i].to_dict('list')
        assert df.GetLinha(df.Query(col,'<=',i)) == iris[iris[col]<=i].to_dict('list')
        assert df.GetLinha(df.Query(col,'>',i)) == iris[iris[col]>i].to_dict('list')
        assert df.GetLinha(df.Query(col,'>=',i)) == iris[iris[col]>=i].to_dict('list')
        assert df.GetLinha(df.Query(col,'==',i)) == iris[iris[col]==i].to_dict('list')
        
# Testando queries com indexação        
df.IndexarColuna('species')
df.IndexarColuna('sepal_length')
df.IndexarColuna('sepal_width')
df.IndexarColuna('petal_length')
df.IndexarColuna('petal_width')

for i in species:
    assert df.GetLinha(df.Query('species','==',i)) == iris[iris['species']==i].to_dict('list')
    
colunas = iris.columns[0:-1]
for col in colunas:
    for i in np.linspace(iris[col].min(),iris[col].max()):
        assert df.GetLinha(df.Query(col,'<',i)) == iris[iris[col]<i].to_dict('list')
        assert df.GetLinha(df.Query(col,'<=',i)) == iris[iris[col]<=i].to_dict('list')
        assert df.GetLinha(df.Query(col,'>',i)) == iris[iris[col]>i].to_dict('list')
        assert df.GetLinha(df.Query(col,'>=',i)) == iris[iris[col]>=i].to_dict('list')
        assert df.GetLinha(df.Query(col,'==',i)) == iris[iris[col]==i].to_dict('list')
df.RemoverIndice('species')
df.RemoverIndice('sepal_length')
df.RemoverIndice('sepal_width')
df.RemoverIndice('petal_length')
df.RemoverIndice('petal_width')


for col in colunas:
    assert sum(df.GetColuna(col) == iris[col])

df.RemoverColuna('species')
for col in colunas:
    for i in np.linspace(iris[col].min(),iris[col].max()):
        assert df.GetLinha(df.Query(col,'<',i)) == iris[iris[col]<i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'<=',i)) == iris[iris[col]<=i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'>',i)) == iris[iris[col]>i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'>=',i)) == iris[iris[col]>=i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'==',i)) == iris[iris[col]==i].drop('species',axis=1).to_dict('list')
        
# Testando queries com indexação        
df.IndexarColuna('sepal_length')
df.IndexarColuna('sepal_width')
df.IndexarColuna('petal_length')
df.IndexarColuna('petal_width')

for col in colunas:
    for i in np.linspace(iris[col].min(),iris[col].max()):
        assert df.GetLinha(df.Query(col,'<',i)) == iris[iris[col]<i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'<=',i)) == iris[iris[col]<=i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'>',i)) == iris[iris[col]>i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'>=',i)) == iris[iris[col]>=i].drop('species',axis=1).to_dict('list')
        assert df.GetLinha(df.Query(col,'==',i)) == iris[iris[col]==i].drop('species',axis=1).to_dict('list')

df.InserirColuna(list(iris['species'].values),'species')

df.RemoverLinha([0,1,2,3,5])
assert df.shape[0] == iris.shape[0] - 5
assert df.shape[1] == iris.shape[1]
assert len(df.indices) == 4

print('Passou em todos os testes!')