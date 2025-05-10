#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100        
#define TAM_PALAVRA 50 

// Estrutura de um nó da lista encadeada (para tratamento de colisões na tabela hash).
typedef struct Node {
    char chave[TAM_PALAVRA];  
    char valor[TAM_PALAVRA];  
    struct Node *proximo;  // Ponteiro para o próximo nó (em caso de colisão).
} Node;

// Declaração da tabela hash como um array de ponteiros para `Node`, com TAM posições.
Node* tabelaHash[TAM];

// Função de hash: transforma uma string (chave) em um índice numérico entre 0 e TAM-1.
int hash(const char *chave) {
    int hash = 0;      // Armazena o valor acumulado para a chave.
    int i = 0;    

    for(int i = 0; i < strlen(chave); i++){
        hash = hash + (int)chave[i];
    }

    return hash % TAM;  // Retorna o índice final, fazendo o valor da chave caber na tabela.
}


void insere(const char *chave, const char *valor) {
    // Calcula o índice da tabela (de acordo com a chave) onde o novo nó vai ser inserido
    int index = hash(chave);  
   
    Node *novoNo = (Node*)malloc(sizeof(Node)); // alocando memória para um novo nó da estrutura Node; o novo nó vai armazenar o par(chave, valor)
    strcpy(novoNo->chave, chave);      // Copia a chave para o novo nó.
    strcpy(novoNo->valor, valor);      // Copia o valor associado para o novo nó.
    novoNo->proximo = NULL;            // Inicializa o ponteiro 'proximo' como NULL (sem colisão inicial).

    
    if (tabelaHash[index] == NULL) // se o index (posição na tabela) calculado estiver vazio, insere diretamente
        tabelaHash[index] = novoNo;
    else {
        // Se a posição já estiver ocupada, percorre a lista encadeada até o final.
        Node *temp = tabelaHash[index]; // criando um ponteiro temp para percorrer a lista encadeada, ele começa pelo primeiro nó na posição "index"
        
        // percorrendo a lista encadeada até encontrar o último nó (percorrendo até o ponteiro temp apontar para uma posição vazia)
        while (temp->proximo != NULL)
            temp = temp->proximo;

        // Adiciona o novo nó ao final da lista (o campo próximo do último nó para o novo nó)
        temp->proximo = novoNo;
    }
}

char* busca(const char *chave) {
    int index = hash(chave);  // Calcula o índice da tabela hash para a chave.
    Node *temp = tabelaHash[index];    

    /* 
    Percorre a lista encadeada buscando o nó cuja chave corresponda à chave desejada.
    Para cada nó a função compara a chave armazenada no nó com a chave passada no argumento
    strcmp retorna 0 se as strings forem iguais
    quando a chave é encontrada a função retorna o valor associado a essa chave
    */

    while (temp != NULL) {
        if (strcmp(temp->chave, chave) == 0)  // Se encontrar a chave, retorna o valor associado.
            return temp->valor;

        temp = temp->proximo;  // Avança para o próximo nó da lista encadeada
        //repete até encontrar a chave ou chegar ao fim da lista.
    }

    // Se não encontrar a chave, retorna uma mensagem de erro.
    return "Não há registro associado a esta chave!";
}

int main() {
    // Inicializa todas as posições da tabela hash como NULL.
    for (int i = 0; i < TAM; i++)
        tabelaHash[i] = NULL;

    insere("Turcomenistão", "Asgabate");
    
    printf("Buscando o país que tem Londres como capital:\n%s\n", busca("Londres"));  // Busca por um país que não existe na tabela.
    printf("Buscando a capital do Turcomenistão:\n%s\n", busca("Turcomenistão"));  // Busca pela capital do Turcomenistão.

    return 0;  
}
