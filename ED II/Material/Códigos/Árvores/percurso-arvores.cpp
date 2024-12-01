#include <iostream>
using namespace std;

struct No {
    int val;
    No* esq;
    No* dir;
    
    No(int valor) : val(valor), esq(NULL), dir(NULL) {}
};

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        cout << raiz->val << " ";
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        cout << raiz->val << " ";
        emOrdem(raiz->dir);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        cout << raiz->val << " ";
    }
}

int main() {
    
    No* raiz = new No(1);
    raiz->esq = new No(2);
    raiz->dir = new No(3);
    raiz->esq->esq = new No(4);
    raiz->esq->dir = new No(5);
    
    cout << "Travessia Pré-Ordem: ";
    preOrdem(raiz);
    cout << endl;

    cout << "Travessia Em-Ordem: ";
    emOrdem(raiz);
    cout << endl;

    cout << "Travessia Pós-Ordem: ";
    posOrdem(raiz);
    cout << endl;

    return 0;
}