#include "NoArvoreBinaria.hpp"

NoArvoreBinaria::NoArvoreBinaria(std::string info, NoArvoreBinaria* esq, NoArvoreBinaria* dir) {
    this->info = info;
    this->dir = dir;
    this->esq = esq;
}

std::string NoArvoreBinaria::getInfo() {
    return this->info;
}

void NoArvoreBinaria::setInfo(std::string info) {
    this->info = info;
}

NoArvoreBinaria* NoArvoreBinaria::getEsq() {
    return this->esq;
}

NoArvoreBinaria* NoArvoreBinaria::getDir() {
    return this->dir;
}

void NoArvoreBinaria::setEsq(NoArvoreBinaria* esq) {
    this->esq = esq;
}

void NoArvoreBinaria::setDir(NoArvoreBinaria* dir){
    this->dir = dir;
}