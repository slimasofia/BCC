#pragma once
#include "NoListaDupla.h"

class ListaDupla {
    private:
        NoListaDupla* head;
    public:
        ListaDupla();
        ~ListaDupla();
        
        // PARTE 1 - IMPLEMENTAÇÃO DA LISTA
        void insere(std::string v);
        void imprime();
        bool vazia();
        NoListaDupla* busca(std::string v);
        int comprimento();
        NoListaDupla* ultimo();
        void retira(std::string v);
        void libera();
        void insereFim(std::string v);

        // PARTE 2 - PROBLEMA APLICADO: PLAYLIST DE MÚSICAS

        // Item 1 (Inserir no final): função insereFim(v).
        // Item 3 (Remover por título): função retira(v).
        // Item 6 (Imprimir numerada): função imprime().

        // Item 2: Inserir em posição específica
        void insereNaPosicao(std::string v, int pos);

        // Item 4: Remover por posição numérica
        void retiraPorPosicao(int pos);

        // Item 5: Mover música (chamar função de remover e depois de inserir)
        void moverMusica(std::string titulo, int posNova);
    };