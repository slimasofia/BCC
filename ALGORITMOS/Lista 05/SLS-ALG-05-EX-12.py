def validar_senha(senha):
    if senha.isupper() == False and senha.islower() == False and senha.isdigit() == False and len(senha) >= 8:
        return True
    else: 
        return False

senha = input("Digite uma senha para verificar se ela é válida: ")

if validar_senha(senha):
    print("É uma senha válida.")

else:
    print("A senha não é válida. ")
