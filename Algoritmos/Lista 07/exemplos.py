# adicionar um item:
thisset = {"apple", "banana", "cherry"}

thisset.add("orange")


#adicionar itens de outro conjunto:
thisset = {"apple", "banana", "cherry"}
tropical = {"pineapple", "mango", "papaya"}
mylist = ["kiwi", "orange"]

thisset.update(tropical)
thisset.update(mylist)

# remover item:
thisset.remove("banana") # ou discard

#remove um item aleatório:
x = thisset.pop()

print(x)

print(thisset)

thisset.clear() # esvazia o conjunto
del thisset # exclui todo o conjunto


for x in thisset: # percorre cada item
  print(x)

# retorna um novo conjunto com a união 
set1 = {"a", "b" , "c"}
set2 = {1, 2, 3}

set3 = set1.union(set2)
print(set3)  

#  intersecção 
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}

x.intersection_update(y) #retorna os itens que estão nos dois conjuntos 
z = x.intersection(y) #retorna a mesma coisa mas em um novo conjunto
x.symmetric_difference_update(y) #retorna os que não estão nos dois (disjunção)
z = x.symmetric_difference(y) #retorna num novo conjunto

