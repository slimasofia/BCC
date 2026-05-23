#include "NoArvoreNaria.hpp"


NoArvoreNaria::NoArvoreNaria(std::string info) {
    this->info = info;
    this->prim = nullptr;
    this->prox = nullptr;
}

std::string NoArvoreNaria::getInfo() {
    return this->info;
}

NoArvoreNaria* NoArvoreNaria::getPrim() {
    return this->prim;
}

NoArvoreNaria* NoArvoreNaria::getProx() {
    return this->prox;
}

void NoArvoreNaria::setInfo(std::string info) {
    this->info = info;
}

void NoArvoreNaria::setPrim(NoArvoreNaria* prim) {
    this->prim = prim;
}

void NoArvoreNaria::setProx(NoArvoreNaria* prox) {
    this->prox = prox;
}


NoArvoreNaria::~NoArvoreNaria() { }
