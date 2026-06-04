#include "ResultadoBusca.hpp"

ResultadoBusca::ResultadoBusca(int indice, int comparacoes) {
    this->indice = indice;
    this->comparacoes = comparacoes;
}

void ResultadoBusca::setIndice(int indice) {
    this->indice = indice;
}
void ResultadoBusca::setComp(int comparacoes) {
    this->comparacoes = comparacoes;
}

int ResultadoBusca::getIndice() {
    return indice;
}
int ResultadoBusca::getComp() {
    return comparacoes;
}