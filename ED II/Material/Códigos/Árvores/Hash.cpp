#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> tabelaHash;

void adicionaPais(const string& pais, const string& capital) {
    tabelaHash[pais] = capital;
    tabelaHash[capital] = pais;
}

string busca(const string& chave) {
    if (tabelaHash.find(chave) != tabelaHash.end())
        return tabelaHash[chave];
    else
        return "Não há registro associado a esta chave!";
}

int main() {

    adicionaPais("Brasil", "Brasília");
    adicionaPais("França", "Paris");
    adicionaPais("Turcomenistão", "Asgabate");
    adicionaPais("Quirguistão", "Bisqueque");
    adicionaPais("Tadjiquistão", "Dushanbe");

    cout << "A capital do Brasil é: " << busca("Brasil") << endl;
    cout << "O país de Paris é: " << busca("Paris") << endl;
    cout << "O país de Londres é: " << busca("Londres") << endl;
    cout << "A capital do Turcomenistão é: " << busca("Turcomenistão") << endl;

    return 0;
}