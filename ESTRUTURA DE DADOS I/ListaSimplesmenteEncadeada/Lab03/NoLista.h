#pragma once
class NoLista {
    private: 
        int info;
        NoLista* prox;
        
    public:
        void setInfo(int info);
        int getInfo();

        void setProx(NoLista* prox);
        NoLista* getProx();

        NoLista(int info, NoLista* prox);
};
