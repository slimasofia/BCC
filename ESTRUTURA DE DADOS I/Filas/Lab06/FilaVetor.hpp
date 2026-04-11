#pragma once
#include "Fila.hpp"
#include <iostream>

class FilaVetor : public Fila {
    private:
        int tam;                // capacidade máxima da fila
        int n;                  // quantidade atual de elementos armazenados
        int ini;                // índice da posição do pŕoximo elemento a ser removido
        int* vet;               // ponteiro para alocar o vetor dinâmicamente

    public:
        FilaVetor(int tam);
        ~FilaVetor();

        void enqueue(int v) override;
        int dequeue() override;
        bool isEmpty() override;
        void reset() override;

        std::string toString(); 
        FilaVetor merge(FilaVetor& f2);    
        FilaVetor concatena(FilaVetor& f2);
};
