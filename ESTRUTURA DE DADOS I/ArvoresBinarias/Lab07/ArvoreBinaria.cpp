#include "ArvoreBinaria.hpp"
#include <iostream>

ArvoreBinaria::ArvoreBinaria() {
    raiz = nullptr;  // cria uma árvore vazia
}

void ArvoreBinaria::defineRaiz(NoArvoreBinaria* r) {
    raiz = r;
}

bool ArvoreBinaria::vazia() {
    return (raiz == nullptr);
}

bool ArvoreBinaria::pertence(NoArvoreBinaria* no, std::string info) {
    if (no == nullptr) {
        return false;
    } else {
        return ((no->getInfo() == info) 
                || pertence(no->getEsq(), info) 
                || pertence(no->getDir(), info));
    }
}

bool ArvoreBinaria::pertence(std::string v) {
    return pertence(raiz, v);
}

int ArvoreBinaria::folhas(NoArvoreBinaria* no) {
    // se o nó atual é nulo, ele não é um nó folha
    if (no == nullptr) {
        return 0;
    // se ele não é nulo
    } else {
        // um nó folha é um nó cuja as referências esq e dir são nulas
        if(no->getDir() == nullptr && no->getEsq() == nullptr) {
            return 1;
        } else {
           // se não é nulo mas também não é um nó folha (tem filhos)
           // soma as folhas que estão na subárvore esquerda com as da subárovre direita
           return folhas(no->getEsq()) + folhas(no->getDir());
        }
    }
}

int ArvoreBinaria::folhas() {
    return folhas(raiz);
}

int ArvoreBinaria::numNos(NoArvoreBinaria* no) {
    if (no == nullptr) {
        return 0;
    } else {
        return 1 + numNos(no->getEsq()) + numNos(no->getDir());
    }
}   

int ArvoreBinaria::numNos() {
    return numNos(raiz);
}

// a altura de uma árvore binária é: a altura de um nó é o caminho mais longo dele até a folha mais profunda
int ArvoreBinaria::altura(NoArvoreBinaria* no) {
    if (no == nullptr) {
        return 0;
    } else {
        // calcula a altura dos dois lados, pega a maior e soma 1 (referente ao próprio nó)
        return 1 + std::max(altura(no->getEsq()), altura(no->getDir()));
    }   
}

int ArvoreBinaria::altura() {
    return altura(raiz);
}

bool ArvoreBinaria::igual(NoArvoreBinaria* no1, NoArvoreBinaria* no2) {
    // se ambos são nulos, chegamos ao fim do caminho e são iguais
    if (no1 == nullptr && no2 == nullptr) {
        return true;
    } 
    // se apenas um deles é nulo, são diferentes
    else if (no1 == nullptr || no2 == nullptr) {
        return false;
    } 
    else {
        return (no1->getInfo() == no2->getInfo() 
                && igual(no1->getDir(), no2->getDir())
                && igual(no1->getEsq(), no2->getEsq()));
    }
}

bool ArvoreBinaria::igual(ArvoreBinaria& a) {
    return igual(raiz, a.raiz);
}

// regra de visitação: raiz, esquerda, direita
std::string ArvoreBinaria::imprimePreOrdem(NoArvoreBinaria* no) {
    if (no == nullptr) {
        return "";    // nó nulo não adiciona nada no texto
    } else {
        // utilizando operador ternário pra organizar melhor a impressão das seleções no ArvoreMain
        return no->getInfo() 
        + (no->getEsq() != nullptr ? " - " + imprimePreOrdem(no->getEsq()) : "")
        + (no->getDir() != nullptr ? " - " + imprimePreOrdem(no->getDir()) : "");
    }
}

std::string ArvoreBinaria::imprimePreOrdem() {
    return imprimePreOrdem(raiz);
}

// regra de visitação: esquerda, raiz, direita
std::string ArvoreBinaria::imprimeSimetrica(NoArvoreBinaria* no) {
    if (no == nullptr) {
        return "";   
    } else {
        return (no->getEsq() != nullptr ? imprimeSimetrica(no->getEsq()) + " - " : "")
        + no->getInfo()
        + (no->getDir() != nullptr ? " - " + imprimeSimetrica(no->getDir()) : "");
    }
}
std::string ArvoreBinaria::imprimeSimetrica() {
    return imprimeSimetrica(raiz);
}

// regra de visitação: esquerda, direita, raiz
std::string ArvoreBinaria::imprimePosOrdem(NoArvoreBinaria* no) {
    if (no == nullptr) {
        return ""; 
    } else {
        return (no->getEsq() != nullptr ? imprimePosOrdem(no->getEsq()) + " - " : "")
        + (no->getDir() != nullptr ? imprimePosOrdem(no->getDir()) + " - " : "")
        + no->getInfo();
    }
}

std::string ArvoreBinaria::imprimePosOrdem() {
    return imprimePosOrdem(raiz);
}

void ArvoreBinaria::destruir(NoArvoreBinaria* no) {
    // se o nó não for nulo, apagar seus filhos e depois ele mesmo
    if (no != nullptr) {
        destruir(no->getEsq()); 
        destruir(no->getDir()); 
        delete no;             
    }
}

ArvoreBinaria::~ArvoreBinaria() { 
    destruir(raiz);
}
