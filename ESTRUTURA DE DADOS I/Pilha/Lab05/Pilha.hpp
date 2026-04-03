#pragma once
#include "NoLista.hpp"

class Pilha {
    private:
    NoLista* topo;

    public:
        Pilha();
        ~Pilha();
        
        void push(float v); // insere um novo valor no topo da pilha
        float pop();        // remove o elemento do topo da pilha e retorna seu valor
        bool vazia();
        float top();        // retorna o valor do topo da pilha sem removê-lo
        void libera();
};