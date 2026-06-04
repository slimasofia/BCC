#pragma once
#include <vector>
#include "ResultadoBusca.hpp"

class Busca {
    private:
        ResultadoBusca buscaBinariaRecursiva(const std::vector<int>& vet, int ini, int fim, int elem, int comparacoes);
    public:
        Busca();

        std::vector<int> criaVetorOrdenado(int n);
        void imprimeVetor(const std::vector<int>& vet);
        ResultadoBusca buscaLinear(const std::vector<int>& vet, int elem);
        ResultadoBusca buscaLinearOrdenada(const std::vector<int>& vet, int elem);
        ResultadoBusca buscaBinaria(const std::vector<int>& vet, int elem);
        ResultadoBusca buscaBinariaRecursiva(const std::vector<int>& vet, int elem);

        ~Busca();
};

