#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100
#define TAM_PALAVRA 50

typedef struct Node {
    char chave[TAM_PALAVRA];
    char valor[TAM_PALAVRA];
    struct Node *proximo;
} Node;

Node* tabelaHash[TAM];

unsigned int hash(const char *chave) {
    unsigned long int valor = 0;
    unsigned int i = 0;
    unsigned int tamanhoChave = strlen(chave);

    while (i < tamanhoChave)
        valor = valor * 37 + chave[i++];

    return valor % TAM;
}

void insere(const char *chave, const char *valor) {
    unsigned int indice = hash(chave);

    Node *novoNo = (Node*)malloc(sizeof(Node));
    strcpy(novoNo->chave, chave);
    strcpy(novoNo->valor, valor);
    novoNo->proximo = NULL;

    if (tabelaHash[indice] == NULL)
        tabelaHash[indice] = novoNo;
    else {
        Node *temp = tabelaHash[indice];
        while (temp->proximo != NULL)
            temp = temp->proximo;

        temp->proximo = novoNo;
    }
}

char* busca(const char *chave) {
    unsigned int indice = hash(chave);
    Node *temp = tabelaHash[indice];

    while (temp != NULL) {
        if (strcmp(temp->chave, chave) == 0)
            return temp->valor;

        temp = temp->proximo;
    }
    return "Não há registro associado a esta chave!";
}

void adicionaPais(const char *pais, const char *capital) {
    insere(pais, capital);
    insere(capital, pais);
}

int main() {
    for (int i = 0; i < TAM; i++)
        tabelaHash[i] = NULL;

    adicionaPais("Brasil", "Brasília");
    adicionaPais("França", "Paris");
    adicionaPais("Turcomenistão", "Asgabate");
    adicionaPais("Quirguistão", "Bisqueque");
    adicionaPais("Tadjiquistão", "Dushanbe");

    printf("Buscando a capital do Brasil:\n%s\n", busca("Brasil"));
    printf("Buscando o país que tem Paris como capital:\n%s\n", busca("Paris"));
    printf("Buscando o país que tem Londres como capital:\n%s\n", busca("Londres"));
    printf("Buscando a capital do Turcomenistão:\n%s\n", busca("Turcomenistão"));

    return 0;
}