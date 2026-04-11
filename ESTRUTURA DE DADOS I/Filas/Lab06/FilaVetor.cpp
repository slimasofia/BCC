#include <iostream>
#include "FilaVetor.hpp"
#include <stdexcept>
#include <algorithm>

FilaVetor::FilaVetor(int tam){
    this->tam = tam;
    this->n = 0;
    this->ini = 0;
    this->vet = new int[tam];
}

void FilaVetor::enqueue(int v) {
    int fim;

    if(n == tam) {
        throw std::runtime_error("Erro: a capacidade da fila estourou!");
    } else {
        // insere o elemento na próxima posição livre
        fim = (ini + n) % tam;
        this->vet[fim] = v;

        // incrementa o número de elementos
        this->n++;
    }
}

// retira o elemento do início da fila retornando seu valor
int FilaVetor::dequeue() {
    int v;

    if(isEmpty()) {
        throw std::runtime_error("Erro: a fila está vazia!");
    } else {
        // salva valor do início
        v = this->vet[ini];

        // incrementa índice do início
        ini = (ini + 1) % tam;

        // decrementa o número de elementos
        this->n--;

        return v;
    }
}

bool FilaVetor::isEmpty() {
    return n == 0;
}

// esvazia a fila reinicializando os atributos ini e n
void FilaVetor::reset() {
    this->ini = 0;
    this->n = 0;
}

std::string FilaVetor::toString() {
    if(isEmpty()) {
        return "[Fila Vazia]";
    } else {
        std::string fila;
        // n passos (quantidade atual de elementos)
        for(int i = 0; i < n; i++) {
            // soma o passo ao ponto de partida para avançar,
            // se (ini + i) ultrapassar a capacidade máxima (tam), '% tam' pega o resto da divisão,
            // forçando o índice a "dar a volta" e voltar para o começo
            int indice_circular = (ini + i) % tam;

            // pega o valor e transforma em texto
            fila += std::to_string(vet[indice_circular]);

            fila += " ";
        }
        return fila;
    }
}

FilaVetor FilaVetor::merge(FilaVetor& f2) {

    FilaVetor f3(this->tam + f2.tam);

    // define quantos passos serão dados com base no tamanho das filas
    int max = std::max(this->n, f2.n);

    for (int i = 0; i < max; i++) {

        // se ainda tem elementos na fila atual
        if(i < this->n) {
            int indice_circular = (ini + i) % tam;
            f3.enqueue(this->vet[indice_circular]);
        }
    
        // se ainda tem elements na f2 
        if(i < f2.n) {
            int indice_circular = (f2.ini + i) % f2.tam;
            f3.enqueue(f2.vet[indice_circular]);
        }
    }
    
    return f3;
}   

FilaVetor FilaVetor::concatena(FilaVetor& f2) {
    // cria uma nova fila para armazenar os elementos da fila atual e de f2
    FilaVetor f3(this->tam + f2.tam);

    int i;

    // preenche a fila f3 com os elementos da fila atual
    for(i = 0; i < this->n; i++) {
        int indice_circular = (ini + i) % tam;
        f3.enqueue(this->vet[indice_circular]);
    }

    // continua preenchendo f3, agora com os elementos da f2
    for(int i = 0; i < f2.n; i++) {
        int indice_circular = (f2.ini + i) % f2.tam;
        f3.enqueue(f2.vet[indice_circular]);
    }

    return f3;
}

FilaVetor::~FilaVetor() {
    delete[] vet;
}

