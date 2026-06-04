#pragma once

class ResultadoBusca {
    private:
        int indice;         // posição em que o elemento foi encontrado (-1 caso o elemento não esteja no vetor)
        int comparacoes;    // quantidade de comparações realizadas entre o elemento procurado e elementos do vetor

    public:
        ResultadoBusca(int indice, int comparacoes);

        void setIndice(int indice);
        void setComp(int comparacoes);

        int getIndice();
        int getComp();
};


