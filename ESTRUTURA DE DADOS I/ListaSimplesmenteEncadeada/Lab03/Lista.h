#pragma once
#include "NoLista.h"
#include <string>

class Lista {
    private: 
        NoLista* prim;

        void imprimeRecursivoAux(NoLista* l);
        NoLista* retiraRecursivoAux(NoLista* l, int v);
        bool igualRecursivoAux(NoLista* l1, NoLista* l2);
        int comprimentoRecursivoAux(NoLista* l);

    public:
        void insere(int v);
        void imprime();
        void retira(int v);
        void libera();
        void insereFim(int v);
        bool igual(Lista& l);

        bool vazia();        
        int comprimento();

        NoLista* busca(int v);
        NoLista* ultimo();

        void imprimeRecursivo();
        void retiraRecursivo(int v);
        bool igualRecursivo(Lista& l);
        int comprimentoRecursivo();
        

        friend std::ostream& operator<<(std::ostream& os, Lista& l);

        Lista();
};