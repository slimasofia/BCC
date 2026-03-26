#include "NoLista.h"

NoLista::NoLista(int info, NoLista* prox) {
    this->info = info;
    this->prox = prox;
}

void NoLista::setInfo(int info) {
    this->info = info;
}

int NoLista::getInfo() {
    return this->info;
}

void NoLista::setProx(NoLista* prox) {
    this->prox = prox;
}

NoLista* NoLista::getProx() {
    return this->prox;
};