#pragma once
#include <iostream>
#include <string.h>
class NoListaDupla {

    private:
        std::string info;
        NoListaDupla* ant;
        NoListaDupla* prox;
    
    public:
        NoListaDupla(std::string info);

        std::string getInfo();
        NoListaDupla* getAnt();
        NoListaDupla* getProx();

        void setInfo(std::string info);
        void setAnt(NoListaDupla* ant);
        void setProx(NoListaDupla* prox);
};