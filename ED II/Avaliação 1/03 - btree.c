#include <stdio.h>      
#include <stdlib.h>     
#include <stdbool.h>   
#include <string.h>     

#define ORDEM 4    // Definindo a ordem. Neste caso, cada nó pode ter no máximo 3 chaves e 4 filhos

// Estrutura que representa um nó da árvore B
typedef struct No {
    struct No **filhos; // Ponteiro para um array de ponteiros para nós filhos
    int *chaves;        // Ponteiro para um array que armazena as chaves do nó
    int nChaves;        // Número atual de chaves armazenadas no nó
    bool folha;         // Indica se o nó é uma folha (não possui filhos)
} No;

/*
Função para criar um novo nó
Recebe um argumento 'folha' para indicar se o nó criado será ou não uma folha 
Se folha for 1: o nó é uma folha (não terá filhos).
Se folha for 0: o nó não é uma folha (pode ter filhos).
*/
No* criaNo(int folha) {                 
    No* no = (No*)malloc(sizeof(No));   // Aloca memória para um novo nó
    
    // Aloca memória para o array de chaves do nó
    // o número máximo de chaves é dado por (ORDEM - 1), mas ele pode armazenar 
    // até (2 * ORDEM - 1) chaves, temporariamente antes de ser dividido
    no->chaves = (int*)malloc((2 * ORDEM - 1) * sizeof(int)); 

    // Aloca memória para o array de filhos do nó
    // O nó pode ter temporariamente até (2 * ORDEM) filhos, 
    // já que na divisão, o nó pode precisar desse espaço para organizar os filhos
    no->filhos = (No**)malloc(2 * ORDEM * sizeof(No*)); // Máximo temporário de (2 * ORDEM) filhos

    no->nChaves = 0;   // Inicializa o número de chaves do nó como 0 (nó vazio)
    no->folha = folha; // Define se o nó é folha (não possui filhos) ou não

    return no; // Retorna o nó criado
}

// Estrutura que representa a árvore B
typedef struct BTree {
    struct No *raiz; // PContém um ponteiro para a raiz da árvore B
} BTree;

// Função para percorrer a árvore B (em ordem)
void percorrer(No* no) {
    int i;
    // Percorre todas as chaves do nó
    for (i = 0; i < no->nChaves; i++) {
        // Se o nó não for uma folha, percorre os filhos antes de imprimir a chave
        if (!no->folha) {
            percorrer(no->filhos[i]);
        }
        // Imprime a chave atual
        printf("%d ", no->chaves[i]);
    }
    // Se o nó não for uma folha, percorre o último filho
    if (!no->folha) {
        percorrer(no->filhos[i]);
    }
}

// Função para buscar uma chave na árvore B
bool buscar(No* no, int chave) {
    int i = 0;
    // Encontra o índice da chave no nó
    while (i < no->nChaves && chave > no->chaves[i]) {
        i++;
    }
    // Se a chave é encontrada, retorna true
    if (i < no->nChaves && chave == no->chaves[i]) {
        return true; // Valor encontrado
    }
    // Se o nó é uma folha e a chave não foi encontrada, retorna false
    if (no->folha) {
        return false; // Valor não encontrado
    }
    // Se não é uma folha, faz a busca no filho 
    return buscar(no->filhos[i], chave);
}

// Função para dividir um nó cheio
void dividirFilho(struct No* pai, int i, No* filhoCheio) {
    No* novoFilho = criaNo(filhoCheio->folha);  // Cria um novo nó que será o filho à direita do filhoCheio
    novoFilho->nChaves = ORDEM - 1;             // Define o número de chaves do novo filho

    // Copia as últimas (ORDEM - 1) chaves de filhoCheio para novoFilho
    for (int j = 0; j < ORDEM - 1; j++) {
        novoFilho->chaves[j] = filhoCheio->chaves[j + ORDEM];
    }

    // Se filhoCheio não for uma folha, copia os últimos filhos para novoFilho
    if (!filhoCheio->folha) {
        for (int j = 0; j < ORDEM; j++) {
            novoFilho->filhos[j] = filhoCheio->filhos[j + ORDEM];
        }
    }

    // Reduz o número de chaves do filhoCheio
    filhoCheio->nChaves = ORDEM - 1;

    // Move os filhos do pai para abrir espaço para novoFilho
    for (int j = pai->nChaves; j >= i + 1; j--) {
        pai->filhos[j + 1] = pai->filhos[j];
    }

    // Adiciona novoFilho ao pai
    pai->filhos[i + 1] = novoFilho;

    // Move as chaves do pai para abrir espaço para a chave do meio de filhoCheio
    for (int j = pai->nChaves - 1; j >= i; j--) {
        pai->chaves[j + 1] = pai->chaves[j];
    }

    // Copia a chave do meio de filhoCheio para o pai
    pai->chaves[i] = filhoCheio->chaves[ORDEM - 1];
    pai->nChaves++; // Aumenta o número de chaves do pai
}

// Função para inserir uma chave em um nó que não está cheio
void inserirNaoCheio(struct No* no, int chave) {
    int i = no->nChaves - 1; // Começa pela última chave

    if (no->folha) {
        // Se o nó é uma folha, move as chaves para encontrar o local adequado para a nova chave
        while (i >= 0 && chave < no->chaves[i]) {
            no->chaves[i + 1] = no->chaves[i]; // Move a chave uma posição para a direita
            i--;
        }
        // Insere a nova chave
        no->chaves[i + 1] = chave;
        no->nChaves++; // Aumenta o número de chaves
    } else {
        // Se não for uma folha, encontra o filho adequado para a inserção
        while (i >= 0 && chave < no->chaves[i]) {
            i--;
        }
        i++; // Move para o índice do filho adequado

        // Se o filho estiver cheio, divida-o
        if (no->filhos[i]->nChaves == 2 * ORDEM - 1) {
            dividirFilho(no, i, no->filhos[i]); // Divide o filho

            // Após a divisão, a chave do meio sobe, então decidimos em qual metade inserir
            if (chave > no->chaves[i]) {
                i++; // Se a nova chave for maior, vai para o filho à direita
            }
        }
        // Insere a chave no filho adequado
        inserirNaoCheio(no->filhos[i], chave);
    }
}

// Função para inserir uma chave na árvore B
void inserir(struct BTree* arvore, int chave) {
    No* raiz = arvore->raiz; // Obtém a raiz da árvore

    // Se a raiz estiver cheia, precisamos dividi-la
    if (raiz->nChaves == 2 * ORDEM - 1) {
        No* novaRaiz = criaNo(0);  // Nova raiz não será uma folha
        novaRaiz->filhos[0] = raiz; // O filho 0 da nova raiz será a antiga raiz
        dividirFilho(novaRaiz, 0, raiz); // Divide a raiz antiga
        inserirNaoCheio(novaRaiz, chave); // Insere a chave na nova raiz
        arvore->raiz = novaRaiz; // Atualiza a raiz da árvore
    } else {
        // Se a raiz não estiver cheia, insere a chave diretamente
        inserirNaoCheio(raiz, chave);
    }
}

int main() {
    // Aloca memória para a árvore B
    BTree* arvore = (BTree*)malloc(sizeof(BTree));
    arvore->raiz = criaNo(1);  // Inicialmente a raiz é uma folha

    char comando[20]; // armazenar comandos
    int valor; // Variável para armazenar valores a serem inseridos ou buscados

    // Laço para ler comandos até o final do arquivo
    while (scanf("%s", comando) != EOF) {
        // Se o comando for "insere", lê um valor e insere na árvore
        if (strcmp(comando, "insere") == 0) {
            scanf("%d", &valor); // Lê o valor a ser inserido
            inserir(arvore, valor); // Chama a função de inserção
        } 
        // Se o comando for "percorre", realiza a travessia em ordem
        else if (strcmp(comando, "percorre") == 0) {
            printf("Percurso da árvore B em ordem: ");
            percorrer(arvore->raiz); // Chama a função de percorrer
            printf("\n");
        } 
        // Se o comando for "busca", lê um valor e busca na árvore
        else if (strcmp(comando, "busca") == 0) {
            scanf("%d", &valor);                                // Lê o valor a ser buscado
            if (buscar(arvore->raiz, valor)) {                  // Chama a função de busca
                printf("Valor %d encontrado!\n", valor);        // Informa que o valor foi encontrado
            } else {
                printf("Valor %d não encontrado!\n", valor);    // Informa que o valor não foi encontrado
            }
        }
    }

    return 0; 
}
