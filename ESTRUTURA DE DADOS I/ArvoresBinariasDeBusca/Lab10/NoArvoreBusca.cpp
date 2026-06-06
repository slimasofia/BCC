#include "NoArvoreBusca.hpp"

NoArvoreBusca::NoArvoreBusca(int info) { 
    this->info = info;
    this->esq = nullptr;
    this->dir = nullptr;
}

int NoArvoreBusca::getInfo() {
    return this->info;
}

NoArvoreBusca* NoArvoreBusca::getEsq() {
    return this->esq;
}

NoArvoreBusca* NoArvoreBusca::getDir() {
    return this->dir;
}

void NoArvoreBusca::setInfo(int info) {
    this->info = info;
}

void NoArvoreBusca::setEsq(NoArvoreBusca* esq) {
    this->esq = esq;
}

void NoArvoreBusca::setDir(NoArvoreBusca* dir) {
    this->dir = dir;
}

NoArvoreBusca::~NoArvoreBusca() { }