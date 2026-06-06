#pragma once

class NoArvoreBusca {
    private:
        int info;               // valor inteiro armazenado no nó
        NoArvoreBusca* esq;     // referência para a subárvore esquerda
        NoArvoreBusca* dir;     // referência para a subárvore direita
    public:
        NoArvoreBusca(int info);

        int getInfo();
        NoArvoreBusca* getEsq();
        NoArvoreBusca* getDir();

        void setInfo(int info);
        void setEsq(NoArvoreBusca* esq);
        void setDir(NoArvoreBusca* dir);

        ~NoArvoreBusca();
};


