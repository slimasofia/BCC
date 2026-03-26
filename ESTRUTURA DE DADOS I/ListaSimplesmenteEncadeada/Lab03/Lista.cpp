#include <iostream>
#include <string>
#include "Lista.h"

// inicializar uma lista vazia
Lista::Lista() {
    this->prim = NULL;
}

void Lista::insere(int v) {
    // o "prox" do novo nó vai apontar para o que era o primeiro nó
    NoLista* novoNo = new NoLista(v, prim);
    // e o novo nó será o primeiro 
    this->prim = novoNo;
}

void Lista::insereFim(int v) {
    NoLista* novoNo = new NoLista(v, NULL);
    if (vazia()) {
        prim = novoNo;
    } else { 
        ultimo()->setProx(novoNo);
    }
}

bool Lista::igual(Lista& l) {
    NoLista* p1 = this->prim;
    NoLista* p2 = l.prim;

    while (p1 != NULL && p2 != NULL) {
        if(p1->getInfo() != p2->getInfo()) {
            return false;
        }
        p1 = p1->getProx();
        p2 = p2->getProx();
    }
    
    return p1 == p2;
}

// imprime os valores armazenados nos nós
void Lista::imprime() {
    // referência pra armazenar o endereço de cada elemento
    NoLista* aux = prim;
    while (aux != NULL) {
        // aponta pra cada um dos elementos da lista
        std::cout << aux->getInfo() << std::endl;
        aux = aux->getProx();
    } 
}

bool Lista::vazia() {
    if (prim == NULL) {
        return true;
    } else {
        return false;   
    }
}       

int Lista::comprimento() {
    NoLista* aux = prim;
    int count = 0;

    while (aux != NULL) {
        count++;
        aux = aux->getProx();
    }

    return count;
}

int Lista::comprimentoRecursivoAux(NoLista* l) {
    if (l == NULL) {
        return 0;
    } else {
        return 1 + comprimentoRecursivoAux(l->getProx());
    }
}

int Lista::comprimentoRecursivo() {
    return comprimentoRecursivoAux(this->prim);
}

// recebe a informação referente ao elemento a pesquisar
NoLista* Lista::busca(int v) {
    NoLista* aux = prim;
    while (aux != NULL) {
        // se o dado do nó atual for igual ao dado que procuramos
        if (aux->getInfo() == v) {
            // retorna o endereço do nó
            return aux;        
        }
        aux = aux->getProx();
    }
    // retorna null caso o elemento não seja encontrado 
    return NULL;
}

// retorna o endereço do último nó da lista
NoLista* Lista::ultimo() {
    if (vazia()) {
        return NULL;
    }

    NoLista* aux = prim;
    while (aux->getProx() != NULL) {
        aux = aux->getProx();
    }
    return aux;
}

std::ostream& operator<<(std::ostream& os, Lista& l) {
    os << "[ ";

    NoLista* atual = l.prim;

    while (atual != NULL) {
        os << atual->getInfo() << " ";
        atual = atual->getProx();
    }

    os << "]";
    return os;
}

void Lista::retira(int v) {
    // utiliza dois ponteiros caminhando pela lista
    NoLista* p = prim; 
    NoLista* ant = NULL;

    while (p != NULL && p->getInfo() != v) {
        ant = p;
        p = p->getProx();
    }

    // não achou o elemento para remover
    if (p == NULL){
        return;
    }

    // se anterior é NULL então a busca não deu nenhum passo e o elemento a ser removido é o primeiro
    if (ant == NULL) {
        // o novo começo da lista passará a ser o segundo nó
        this->prim = p->getProx();
    // o nó a ser removido não é o primeiro
    } else {
        // o "next" do anterior passa a apontar pra o que vem depois do atual
        // assim "pulamos" o nó "atual" e ele é ignorado
        ant->setProx(p->getProx());
    }
    delete p;
}

void Lista::imprimeRecursivoAux(NoLista* l) {
    if (l != NULL) {
        std::cout << l->getInfo() << std::endl;
        imprimeRecursivoAux(l->getProx());
    }
}

void Lista::imprimeRecursivo() {
    imprimeRecursivoAux(prim);
}

NoLista* Lista::retiraRecursivoAux(NoLista* l, int v) {
    if (l != NULL) {
        if (l->getInfo() == v) {
            NoLista* aux = l;   // segura o nó que vai ser apagado
            l = l->getProx();   // a lista avança, pulando o nó
            delete aux;         // destrói o nó que ficou pra trás
        } else {
            l->setProx(retiraRecursivoAux(l->getProx(), v));
        }
    }
    return l;
}

void Lista::retiraRecursivo(int v) {
    prim = retiraRecursivoAux(prim, v);
}


bool Lista::igualRecursivoAux(NoLista* l1, NoLista* l2) {
    // se as duas listas esao vazias elas são iguais
    if (l1 == NULL && l2 == NULL) {
        return true;
    } else {
        if (l1 == NULL || l2 == NULL) { // se apenas uma lista está vazia, elas não são iguais
            return false;
        } else {
            return l1->getInfo() == l2->getInfo() && 
            igualRecursivoAux(l1->getProx(), l2->getProx());
        }
    }
}

bool Lista::igualRecursivo(Lista& l) {
    return igualRecursivoAux(this->prim, l.prim);
}


void Lista::libera() {
    NoLista* atual = prim;
    while (atual != NULL) {
        NoLista* proxNo = atual->getProx();
        delete atual;
        atual = proxNo;
    }
    prim = NULL;
}