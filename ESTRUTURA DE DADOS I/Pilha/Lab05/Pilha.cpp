#include "Pilha.hpp"
#include <iostream>

Pilha::Pilha() {
    this->topo = nullptr;
}
        
void Pilha::push(float v) {
    NoLista* novoNo = new NoLista(v);
    novoNo->setProx(topo);
    topo = novoNo;
}

float Pilha::pop() {
    
    // trata o caso da pilha estar vazia
    if (vazia()) {
        std::cerr << "Erro: A pilha está vazia." << std::endl;
        exit(1);    // interrompe a execução
    }
    
    float v = topo->getInfo();  // guarda o valor que está no nó que será removido
    NoLista* p = topo;          // guarda o ponteiro do nó que será removido

    topo = topo->getProx();     // o novo topo é o elemento que estava abaixo
    delete p;                   // remove o elemento do topo

    return v;                   // retorna o valor dele
}

bool Pilha::vazia() {
    return (topo == nullptr);
}

float Pilha::top() {
    
    // trata o caso da pilha estar vazia
    if (vazia()) {
        std::cerr << "Erro: A pilha está vazia." << std::endl;
        exit(1);    // interrompe a execução
    }

    return topo->getInfo();
}   

void Pilha::libera() {
    while (topo != nullptr) {
        pop();
    }
}

Pilha::~Pilha() {
    libera();
}
