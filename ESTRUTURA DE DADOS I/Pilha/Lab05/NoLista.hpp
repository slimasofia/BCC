#pragma once

class NoLista {
    private: 
        float info;
        NoLista* prox;
        
    public:
        void setInfo(float info);
        float getInfo();

        void setProx(NoLista* prox);
        NoLista* getProx();

        NoLista(float info);
};