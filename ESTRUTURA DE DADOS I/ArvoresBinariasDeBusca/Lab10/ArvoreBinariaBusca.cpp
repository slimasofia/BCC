#include "ArvoreBinariaBusca.hpp"
#include <iostream>
#include <algorithm>
#include <string> 

ArvoreBinariaBusca::ArvoreBinariaBusca() {
    raiz = nullptr;
}

bool ArvoreBinariaBusca::vazia() {
    return raiz == nullptr;
}

NoArvoreBusca* ArvoreBinariaBusca::busca(int v) {
    return busca(raiz, v);
}

void ArvoreBinariaBusca::insere(int v) {
    raiz = insere(raiz, v);
}

void ArvoreBinariaBusca::retira(int v) {
    raiz = retira(raiz, v);
}

bool ArvoreBinariaBusca::pertence(int v) {
    return busca(v) != nullptr;
}

int ArvoreBinariaBusca::numNos() {
    return numNos(raiz);
}

int ArvoreBinariaBusca::folhas() {
    return folhas(raiz);
}

int ArvoreBinariaBusca::altura() {
    return altura(raiz);
}

int ArvoreBinariaBusca::numNos(NoArvoreBusca* no) {
    if(no == nullptr) {
        return 0;
    }    

    return 1 + numNos(no->getEsq()) + numNos(no->getDir());
}

int ArvoreBinariaBusca::folhas(NoArvoreBusca* no) {
    // se o nó é null não há nós folha
    if(no == nullptr) {
        return 0;
    }

    // se o nó não tem filhos ele é um nó folha
    if (no->getEsq() == nullptr && no->getDir() == nullptr) {
        return 1;
    }  
    return folhas(no->getEsq()) + folhas(no->getDir());
}

int ArvoreBinariaBusca::altura(NoArvoreBusca* no) {
    if(no == nullptr) {
        return -1;
    }
    return 1 + std::max(altura(no->getEsq()), altura(no->getDir()));
}

// percurso em ordem crescente
std::string ArvoreBinariaBusca::toString() {
    return toString(raiz);
}

std::string ArvoreBinariaBusca::toStringDecrescente() {
    return toStringDecrescente(raiz);
}

std::string ArvoreBinariaBusca::toString(NoArvoreBusca* no) {
    if (no == nullptr) {
        return "";
    }  
    return toString(no->getEsq()) + std::to_string(no->getInfo()) + " " + toString(no->getDir());
}

std::string ArvoreBinariaBusca::toStringDecrescente(NoArvoreBusca* no) {
    if (no == nullptr) {
        return "";
    } 
    return toStringDecrescente(no->getDir()) + std::to_string(no->getInfo()) + " " + toStringDecrescente(no->getEsq());
}

// se o nó atual não resolve o problema: chama a função para a esquerda OU chama a função para a direita, até encontrar um caso base
NoArvoreBusca* ArvoreBinariaBusca::busca(NoArvoreBusca* no, int v) {

    // caso 1
    if (no == nullptr) {
        return nullptr;
    }

    // caso 2: valor igual ao nó
    if (v == no->getInfo()) {
        return no;
    }

    // caso 3: valor menor que o nó
    if (v < no->getInfo()) {
        return busca(no->getEsq(), v);
    } else {
        return busca(no->getDir(), v); // caso 4: valor maior que o nó
    }
}

NoArvoreBusca* ArvoreBinariaBusca::insere(NoArvoreBusca* no, int v) {

    // encontrou uma posição vazia para inserir
    if(no == nullptr) {
        return new NoArvoreBusca(v);
    }

    if (v < no->getInfo()) {
        no->setEsq(insere(no->getEsq(), v));
    } else {
        no->setDir(insere(no->getDir(), v));
    }

    return no;
}

// retorna a nova raiz da subárovre após a remoção
NoArvoreBusca* ArvoreBinariaBusca::retira(NoArvoreBusca* no, int v) {

    if (no == nullptr) {
        return nullptr;
    }

    if (v < no->getInfo()) {
        no->setEsq(retira(no->getEsq(), v));
        return no;
    }

    if (v > no->getInfo()) {
        no->setDir(retira(no->getDir(), v));
        return no;
    }

    // caso 1: o nó é folha (sem filhos)
    if(no->getEsq() == nullptr && no->getDir() == nullptr) {
        delete no;
        return nullptr;
    }

    // caso 2: nó com um filho
    if(no->getEsq() != nullptr && no->getDir() == nullptr) {
        NoArvoreBusca* filho = no->getEsq();
        delete no;
        return filho;
    }
    if(no->getDir() != nullptr && no->getEsq() == nullptr) {
        NoArvoreBusca* filho = no->getDir();
        delete no;
        return filho;    
    }

    // caso 3: nó com dois filhos

    // encontrar substituto: maior da esquerda
    NoArvoreBusca* maior = maiorEsquerda(no->getEsq());
    // substituir o nó que será removido pelo maior
    no->setInfo(maior->getInfo());
    no->setEsq(retira(no->getEsq(), maior->getInfo()));
    return no;
}

// função recursiva pra achar o maior da esquerda
NoArvoreBusca* ArvoreBinariaBusca::maiorEsquerda(NoArvoreBusca* no) {
    if (no->getDir() == nullptr) {
        return no;
    }

    return maiorEsquerda(no->getDir());
}


void ArvoreBinariaBusca::destruir(NoArvoreBusca* no) {
    if (no == nullptr) {
        return;
    }

    destruir(no->getEsq());
    destruir(no->getDir());

    delete no;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    destruir(raiz);
}