from DataFrame import *

df = DataFrame()

## Primeira insercao
#df.InserirColunaInt([6,None,4],"coluna1")
df.InserirColunaInt([6,3,4],"coluna1")
df.InserirColunaDouble([1.3,0.4],"coluna2")
df.InserirColunaString(["davi","ok"],"coluna2")

df.InserirColunaInt([5,1],"coluna3")

## Alterando as colunas
df.InserirColunaInt([10,2],"coluna1")
df.InserirColunaString(['teste'],"coluna1")






## Note que são três mapas, então coluna2 double não muda coluna2 string
## Temos que lidar com isso no nível do python para gerenciar essas coisas
print(df.GetColunaInt("coluna1"))
print(df.GetColunaString("coluna1"))
print(df.GetColunaString("coluna2"))
print(df.GetColunaDouble("coluna2"))
print(df.GetColunaInt("coluna3"))



df.RemoverColunaInt([],"coluna1")
df.RemoverColunaInt([],"coluna3")
df.RemoverColunaDouble([],"coluna2")
df.RemoverColunaString([],"coluna1")
df.RemoverColunaString([],"coluna2")

print(df.GetColunaInt("coluna1"))
print(df.GetColunaInt("coluna3"))
print(df.GetColunaDouble("coluna2"))
print(df.GetColunaString("coluna1"))
print(df.GetColunaString("coluna2"))
#print(df.GetColunaDouble("coluna2"))
#print(df.GetColunaInt("coluna3"))
