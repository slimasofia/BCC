#include <iostream>
#include "Busca.hpp"
#include <vector>

Busca::Busca() {}

std::vector<int> Busca::criaVetorOrdenado(int n) {
    std::vector<int> vet(n);
    for (int i = 0; i < n; i++) {
        vet[i] = i * 2;
    }
    
    return vet;
}

void Busca::imprimeVetor(const std::vector<int>& vet) {

    for (int i = 0; i < vet.size(); i++) {
        std::cout << vet[i] << " ";
    }
    std::cout << std::endl;
}

ResultadoBusca Busca::buscaLinear(const std::vector<int>& vet, int elem) {
    int comparacoes = 0;
    for (int i = 0; i < vet.size(); i++) {
        comparacoes++;
        if (elem == vet[i]) {
            return ResultadoBusca(i, comparacoes);
        }
    
    }    
    return ResultadoBusca(-1, comparacoes);

}

ResultadoBusca Busca::buscaLinearOrdenada(const std::vector<int>& vet, int elem) {
    int comparacoes = 0;
    for (int i = 0; i < vet.size(); i++) {
        comparacoes++;
        if (elem == vet[i]) {
            return ResultadoBusca(i, comparacoes);
        } else {
            if (elem < vet[i]) {
                return ResultadoBusca(-1, comparacoes);
            }
        }
    }
    return ResultadoBusca(-1, comparacoes);
}

ResultadoBusca Busca::buscaBinaria(const std::vector<int>& vet, int elem) {
    int ini = 0;
    int fim = (vet.size() - 1);
    int meio;
    int comparacoes = 0;

    while (ini <= fim) {
        meio = ini + (fim - ini)/2;
        comparacoes++;

        if (elem < vet[meio]) {
            fim = meio - 1;
        } else {
            if (elem > vet[meio]) {
                ini = meio + 1;
            } else {
                return ResultadoBusca(meio, comparacoes); // elemento encontrado
            }
        }
    }
    return ResultadoBusca(-1, comparacoes);
}

ResultadoBusca Busca::buscaBinariaRecursiva(const std::vector<int>& vet, int ini, int fim, int elem, int comparacoes) {
    
    // caso de parada
    if (ini > fim) {
        return ResultadoBusca(-1, comparacoes);
    }

    // passo recursivo
    int meio = 0;
    meio = ini + (fim - ini) / 2;

    comparacoes++;              // contabiliza a comparação que vai ser feita nessa chamada
    if (elem == vet[meio]) {
        return ResultadoBusca(meio, comparacoes);
    } else {
        // o elemento está na metade esquerda do vetor
        if(elem < vet[meio]) {
            return buscaBinariaRecursiva(vet, ini, meio - 1, elem, comparacoes);
        } else {
        // o elemento está na metade direita do vetor
            return buscaBinariaRecursiva(vet, meio + 1, fim, elem, comparacoes);
        }
    }
}

ResultadoBusca Busca::buscaBinariaRecursiva(const std::vector<int>& vet, int elem) {
    return buscaBinariaRecursiva(vet, 0, vet.size() - 1, elem, 0);
}

Busca::~Busca() {}