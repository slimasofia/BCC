#include <iostream>
#include "NoListaDupla.h"

NoListaDupla::NoListaDupla(std::string info) {
    this->info = info;
    this->ant = NULL;
    this->prox = NULL;
}

std::string NoListaDupla::getInfo() {
    return this->info;
}

NoListaDupla* NoListaDupla::getAnt() {
    return this->ant;
}

NoListaDupla* NoListaDupla::getProx() {
    return this->prox;
}

void NoListaDupla::setInfo(std::string info) {
    this->info = info;
}

void NoListaDupla::setAnt(NoListaDupla* ant) {
    this->ant = ant;
}

void NoListaDupla::setProx(NoListaDupla* prox) {
    this->prox = prox;
}
