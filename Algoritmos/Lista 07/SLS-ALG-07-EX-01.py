def possui_caracteres_unicos(palavra):
    caracteres = set() 

    for x in palavra:
        if x in caracteres:
            return False  
        caracteres.add(x) 
    return True  

palavra = input("Digite uma palavra para verificar se ela possui caracteres únicos: ")
if possui_caracteres_unicos(palavra):
    print("Essa palavra possui caracteres únicos. ")
else:
    print("A palavra possui caracteres repetidos. ")
