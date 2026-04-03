#include "NoLista.hpp"

NoLista::NoLista(float info) {
    this->info = info;
    this->prox = nullptr;
}

void NoLista::setInfo(float info) {
    this->info = info;
}

float NoLista::getInfo() {
    return this->info;
}

void NoLista::setProx(NoLista* prox) {
    this->prox = prox;
}

NoLista* NoLista::getProx() {
    return this->prox;
};