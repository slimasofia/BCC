#pragma once
#include "NoArvoreBusca.hpp"
#include <iostream>
#include <string>

class ArvoreBinariaBusca {
    private:
        NoArvoreBusca* raiz;

        // métodos auxiliares recursivos
        NoArvoreBusca* busca(NoArvoreBusca* no, int v);
        NoArvoreBusca* insere(NoArvoreBusca* no, int v);
        NoArvoreBusca* retira(NoArvoreBusca* no, int v);
        NoArvoreBusca* maiorEsquerda(NoArvoreBusca* no);
        int folhas(NoArvoreBusca* no);
        int altura(NoArvoreBusca* no);
        int numNos(NoArvoreBusca* no);
        std::string toString(NoArvoreBusca* no);
        std::string toStringDecrescente(NoArvoreBusca* no);
        void destruir(NoArvoreBusca* no);

    public:
        ArvoreBinariaBusca();

        bool vazia();
        NoArvoreBusca* busca(int v);
        void insere(int v);
        void retira(int v);
        bool pertence(int v);
        int numNos();
        int folhas();
        int altura();
        std::string toString();
        std::string toStringDecrescente();

        ~ArvoreBinariaBusca();
};

