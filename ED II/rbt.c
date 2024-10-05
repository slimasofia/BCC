/* é um tipo de árvore binária balanceada
usa o esquema de coloração para manter a árvore balanceada

A árvore vermelho-preto deve satisfazer as seguintes propriedades:
1. Todo nó da árvore é vermelho ou preto.
2. O nó raiz é preto.
3. Toda folha (nil) é preta.
4. Se um nó é vermelho, então seus filhos são pretos.
5. Para cada nó, todos os caminhos de um nó até seus descendentes possuem o mesmo número de nós pretos.
 
com exceção da inserção e remoção, as demais funções da rbt são identicas a bst
*/

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct No{
    int valor;
    struct No *esq, *dir, *p;
    int cor;

} No;


int cor(struct No* raiz){
    if (raiz == NULL)
    {
     return BLACK;
    } else{
        return RED;
    } 
}

void trocaCor(struct No* raiz){
    raiz->cor = !raiz->cor;
    if (raiz->esq != NULL){
        raiz->esq->cor = !raiz->esq->cor;
    }

    if (raiz->dir != NULL){
        raiz->dir->cor = !raiz->dir->cor;
    }   
}

struct No* giraEsquerda(struct No* A){
    struct No* B = A->dir;
    A->dir = B->esq;
    B->esq = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

struct No* giraDireita(struct No* A){
    struct No* B = A->esq;
    A->esq = B->dir;
    B->dir = A;
    B->cor = A->cor;
    A->cor = RED;
    return B;
}

void arrumar(No* k, No* raiz){
    while (k != raiz && k->p->cor == "RED") {

        if (k->p == k->p->p->esq){
            No* u = k->p->p->dir; // tio

            if (u->cor == "RED"){
                k->p->cor = "BLACK";
                u->cor = "BLACK";   
                k->p->p->cor = "RED";
                k = k->p->p;
            } else {
                
            }
            
        }
        
    }
    
}

/*
Casos do fixInsert
Caso 1: O tio é vermelho

Se o tio do novo nó é vermelho, isso significa que temos uma "violação" em nível superior.
Nesse caso, simplesmente recolorimos:
O pai e o tio se tornam pretos.
O avô (pai do pai) se torna vermelho.
Depois disso, continuamos a verificar a árvore a partir do avô.

Caso 2: O tio é preto e o novo nó é um filho direito

Se o tio é preto e o novo nó está na posição direita em relação ao seu pai (o que cria uma forma de "zig-zag"), 
fazemos uma rotação à esquerda no pai. Isso transforma a árvore em
uma situação onde o novo nó está na posição esquerda em relação ao pai.

Caso 3: O tio é preto e o novo nó é um filho esquerdo

Agora, se o tio é preto e o novo nó está na posição esquerda em relação ao pai 
(o que é uma configuração "linear"), fazemos uma rotação à direita no avô.
Antes de fazer essa rotação, mudamos a cor do pai para preto e do avô para vermelho.
Resumo do Funcionamento
Início: Começamos com o nó que acabamos de inserir e verificamos seu pai.
Verificação do pai: Se o pai é vermelho, precisamos corrigir a árvore.
Identificação do tio: Com base em onde o novo nó está (à esquerda ou à direita), e a cor do tio, decidimos qual dos três casos aplicar.
Aplicação das regras: Dependendo do caso, recolorimos ou fazemos rotações até que a árvore respeite todas as propriedades rubro-negras.
Exemplo Passo a Passo
Inserir um nó: Vamos supor que temos uma árvore e inserimos um novo nó que resulta em um pai vermelho.
Verificação: Se o pai é vermelho e o tio (irmão do pai) é vermelho, recoloramos os nós.
Prossiga para cima: Continuamos esse processo até que todas as propriedades da árvore estejam corretas.
*/





// a rotação pode gerar uma violação, isso será corrigido depois em outra função

//mover um nó de vermelho para esquerda:



