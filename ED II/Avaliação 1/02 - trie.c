#include <stdio.h>        
#include <stdlib.h>         
#include <string.h>        
#include <stdbool.h>        

#define TAM_ALFABETO 95     // Define o tamanho do alfabeto (valores ASCII de 32 a 126)
#define TAM_PALAVRA 100     // Define o tamanho máximo de uma palavra (senha)

// Estrutura do nó da Trie
typedef struct NoTrie {
    struct NoTrie *filhos[TAM_ALFABETO];    // Array de ponteiros para os filhos, correspondendo a cada caractere
    bool fimDePalavra;                      // indica se o nó marca o final de uma palavra
} NoTrie;

// Função para criar um novo nó da Trie
NoTrie* criarNo() {
    NoTrie *no = (NoTrie*)malloc(sizeof(NoTrie)); // Aloca memória para um novo nó
    no->fimDePalavra = false;                     // Inicializa 'fimDePalavra' como falso
    for (int i = 0; i < TAM_ALFABETO; i++) {
        no->filhos[i] = NULL;                     // Inicializa todos os filhos como NULL
    }
    return no; // Retorna o nó 
}

// Função para inserir uma senha na Trie
void inserir(NoTrie *raiz, const char *senha) {
    NoTrie *atual = raiz;                          // Inicia no nó raiz
    for (int i = 0; senha[i] != '\0'; i++) {       // Percorre cada caractere da senha até o final
        char c = senha[i];                         // Armazena o caractere atual
                                                   // Ignora caracteres fora do intervalo ASCII permitido
        if (c < 32 || c > 126) {
            continue;                              // Passa para o próximo caractere
        }
        int indice = c - 32;                       // Calcula o índice correspondente no array de filhos
        // Se não existe um nó filho para o caractere atual, cria um novo nó
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criarNo();     // Cria um novo nó para o caractere
        }
        atual = atual->filhos[indice];             // Move para o filho correspondente
    }
    atual->fimDePalavra = true;                    // Marca o final da senha
}

// Função auxiliar para buscar e imprimir senhas com um determinado prefixo
void explorar(NoTrie *atual, char *buffer, int profundidade) {
    // Se o nó atual marca o fim de uma palavra, imprime a senha
    if (atual->fimDePalavra) {
        buffer[profundidade] = '\0'; // Finaliza a string
        printf("%s\n", buffer);     // Imprime a senha encontrada
    }

    // Explora todos os filhos do nó atual
    for (int i = 0; i < TAM_ALFABETO; i++) {
        // Se tem um filho no índice i, continua a explorando
        if (atual->filhos[i] != NULL) {
            buffer[profundidade] = i + 32;                        // Converte o índice de volta pro caractere
            explorar(atual->filhos[i], buffer, profundidade + 1); // Chama recursivamente para o próximo nível
        }
    }
}

// Função para buscar senhas que começam com determinado prefixo
void buscar(NoTrie *raiz, const char *prefixo) {
    NoTrie *atual = raiz;           // Começa na raiz
    char buffer[TAM_PALAVRA];       // para armazenar o prefixo
    int profundidade = 0;           // controlando profundidade da exploração

    // Navega pelo prefixo fornecido
    for (int i = 0; prefixo[i] != '\0'; i++) {
        char c = prefixo[i]; // Armazena o caractere atual do prefixo
        // Verifica se o caractere está dentro do intervalo ASCII permitido
        if (c < 32 || c > 126) {
            printf("Nenhuma senha encontrada com esse prefixo.\n");
            return; // Retorna se o caractere não é válido
        }
        int indice = c - 32; // Calcula o índice correspondente
        // Verifica se existe um filho correspondente ao caractere do prefixo
        if (atual->filhos[indice] == NULL) {
            printf("Nenhuma senha encontrada com esse prefixo.\n");
            return; // Retorna se não há senha com esse prefixo
        }
        atual = atual->filhos[indice]; // Move para o próximo nó
        buffer[profundidade++] = c; // Adiciona o caractere ao buffer
    }

    // Chama a função auxiliar para buscar senhas a partir do nó correspondente
    explorar(atual, buffer, profundidade); // Explora as senhas a partir do nó correspondente ao prefixo
}

// Função para carregar senhas de um arquivo para a Trie
void carregaSenhas(NoTrie *raiz, const char *a) {
    // Abre o arquivo para leitura
    FILE *arquivo = fopen(a, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo");
        exit(1); // Termina o programa se não conseguir abrir o arquivo
    }

    // Array para armazenar as senhas que foram lidas do arquivo
    char senha[TAM_PALAVRA];

    // Lê senhas do arquivo linha por linha
    while (fgets(senha, sizeof(senha), arquivo)) {
        senha[strcspn(senha, "\n")] = 0; // Remove o caractere de nova linha
        // Insere a senha lida
        inserir(raiz, senha); 
    }
    fclose(arquivo); // Fecha o arquivo depois de ler todas as senhas
}

int main() {
    NoTrie *raiz = criarNo(); // Chama a função para criar o nó raiz 
    carregaSenhas(raiz, "rockyou-menor.txt"); // Carrega as senhas do arquivo

    // Array para armazenar os prefixos a serem consultados
    char prefixo[TAM_PALAVRA];

    // Lê os prefixos fornecidos até EOF
    while (fgets(prefixo, sizeof(prefixo), stdin)) {
        prefixo[strcspn(prefixo, "\n")] = 0; // Remove o caractere de nova linha
        // Busca senhas que começam com o prefixo fornecido
        buscar(raiz, prefixo); // Chama a função que busca senhas com o prefixo fornecido
    }

    return 0;
}
