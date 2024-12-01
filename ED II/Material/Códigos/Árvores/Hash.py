tabelaHash = {}

def adicionaPais(pais, capital):
    tabelaHash[pais] = capital
    tabelaHash[capital] = pais

def busca(chave):
    return tabelaHash.get(chave, "Não há registro associado a esta chave!")

adicionaPais("Brasil", "Brasília")
adicionaPais("França", "Paris")
adicionaPais("Turcomenistão", "Asgabate")
adicionaPais("Quirguistão", "Bisqueque")
adicionaPais("Tadjiquistão", "Dushanbe")

print(f"A capital do Brasil é: {busca('Brasil')}")
print(f"O país de Paris é: {busca('Paris')}")
print(f"O país de Londres é: {busca('Londres')}")
print(f"A capital do Turcomenistão é: {busca('Turcomenistão')}")
