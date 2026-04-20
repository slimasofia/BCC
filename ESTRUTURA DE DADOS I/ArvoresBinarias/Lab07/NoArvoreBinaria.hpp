#pragma once
#include <string>

class NoArvoreBinaria {
    private: 
        std::string info;
        NoArvoreBinaria* esq;       // subárvore da esquerda
        NoArvoreBinaria* dir;       // subárvore da direita

    public:
        NoArvoreBinaria(std::string info, NoArvoreBinaria* esq, NoArvoreBinaria* dir);
        
        NoArvoreBinaria* getEsq();
        NoArvoreBinaria* getDir();
        std::string getInfo();

        void setInfo(std::string info);  
        void setEsq(NoArvoreBinaria* esq);
        void setDir(NoArvoreBinaria* dir);  
};