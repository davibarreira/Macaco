from DataFrame import *

df = DataFrame()

v = [20,2]
u = [2.2,1.1]
df.InserirColunaInt([6,1],"coluna1")
df.InserirColunaString(["davi","ok"],"coluna2")
df.InserirColunaDouble([1.3,0.4],"coluna2")
df.InserirColunaInt([5,1],"coluna3")

print(df.GetColunaInt("coluna1"))
print(df.GetColunaString("coluna2"))
## Note que são três mapas, então coluna2 double não muda coluna2 string
## Temos que lidar com isso no nível do python para gerenciar essas coisas
print(df.GetColunaDouble("coluna2"))
print(df.GetColunaInt("coluna3"))
