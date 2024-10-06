#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 95 // ASCII 32 to 126
#define MAX_PASSWORD_LENGTH 100

// Estrutura do nó da Trie
typedef struct NoTrie {
    struct NoTrie *filhos[ALPHABET_SIZE];
    bool fimDePalavra;
} NoTrie;

// Função para criar um novo nó da Trie
NoTrie* criarNo() {
    NoTrie *no = (NoTrie*)malloc(sizeof(NoTrie));
    no->fimDePalavra = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        no->filhos[i] = NULL;
    }
    return no;
}

// Função para inserir uma senha na Trie
void inserir(NoTrie *raiz, const char *senha) {
    NoTrie *atual = raiz;
    for (int i = 0; senha[i] != '\0'; i++) {
        char ch = senha[i];
        if (ch < 32 || ch > 126) {
            continue; // Ignora caracteres fora do intervalo ASCII permitido
        }
        int indice = ch - 32; // Calcula o índice no vetor de filhos
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
    }
    atual->fimDePalavra = true; // Marca o final da palavra
}

// Função de busca que verifica se a palavra existe na Trie


// Função auxiliar para buscar e imprimir senhas com um determinado prefixo
void explorar(NoTrie *atual, char *buffer, int profundidade) {
    // Se o nó atual marca o fim de uma palavra, imprime a senha
    if (atual->fimDePalavra) {
        buffer[profundidade] = '\0'; // Finaliza a string
        printf("%s\n", buffer); // Imprime a senha encontrada
    }

    // Explora todos os filhos do nó atual
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (atual->filhos[i] != NULL) {
            buffer[profundidade] = i + 32; // Converte o índice de volta para o caractere
            explorar(atual->filhos[i], buffer, profundidade + 1); // Chama recursivamente
        }
    }
}

// Função para buscar senhas que começam com um prefixo
void buscarSenhasComPrefixo(NoTrie *raiz, const char *prefixo) {
    NoTrie *atual = raiz;
    char buffer[MAX_PASSWORD_LENGTH];
    int profundidade = 0;

    // Navega pelo prefixo
    for (int i = 0; prefixo[i] != '\0'; i++) {
        char ch = prefixo[i];
        if (ch < 32 || ch > 126) {
            printf("Nenhuma senha encontrada com esse prefixo.\n");
            return;
        }
        int indice = ch - 32;
        if (atual->filhos[indice] == NULL) {
            printf("Nenhuma senha encontrada com esse prefixo.\n");
            return;
        }
        atual = atual->filhos[indice];
        buffer[profundidade++] = ch; // Adiciona caractere ao buffer
    }

    // Chama a função auxiliar para buscar senhas a partir do nó correspondente
    explorar(atual, buffer, profundidade);
}

void carregaSenhas(NoTrie *raiz, const char *a){
    
    // Abre o arquivo rockyou-menor.txt para leitura
    FILE *arquivo = fopen(a, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo");
        exit(1);
    }

    // Array para armazenar as senhas lidas do arquivo
    char senha[MAX_PASSWORD_LENGTH];
    
    // Lê senhas do arquivo linha por linha
    while (fgets(senha, sizeof(senha), arquivo)) {
        // Remove a nova linha se presente ao final da senha
        senha[strcspn(senha, "\n")] = 0;
        
        // Insere a senha na Trie
        inserir(raiz, senha);
    }
    fclose(arquivo); // Fecha o arquivo após ler todas as senhas
}

// Função para liberar a memória da Trie
void deletarTrie(NoTrie *raiz) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (raiz->filhos[i] != NULL) {
            deletarTrie(raiz->filhos[i]);
        }
    }
    free(raiz);
}

int main() {
    // Cria a raiz da Trie
    NoTrie *raiz = criarNo();
    carregaSenhas(raiz, "rockyou-menor.txt");

    // Array para armazenar os prefixos a serem consultados
    char prefixo[MAX_PASSWORD_LENGTH];
    
    // Lê os prefixos fornecidos pelo usuário até EOF
    while (fgets(prefixo, sizeof(prefixo), stdin)) {
        // Remove a nova linha se presente ao final do prefixo
        prefixo[strcspn(prefixo, "\n")] = 0;
        
        // Busca senhas que começam com o prefixo fornecido
        buscarSenhasComPrefixo(raiz, prefixo);
    }

    // Libera a memória utilizada pela Trie
    deletarTrie(raiz);
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
