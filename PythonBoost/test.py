from DataFrame import *

df = DataFrame()

v = [20,2]
u = [2.2,1.1]
df.PassColunaInt([6,1],"coluna1")
#df.PassColunaString("s",["davi","ok"],"coluna2")
df.PassColunaInt([5,1],"coluna3")

print(df.test)
print(df.ReturnColunaInt("coluna1"))
print(df.ReturnColunaInt("coluna3"))
