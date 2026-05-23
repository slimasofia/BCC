#pragma once
#include "NoArvoreNaria.hpp"

class ArvoreNaria {
    private:
        NoArvoreNaria* raiz;

        // métodos auxiliares recursivos
        bool pertence(NoArvoreNaria* no, std::string v);
        int numNos(NoArvoreNaria* no);
        int folhas(NoArvoreNaria* no);
        int altura(NoArvoreNaria* no);
        bool igual(NoArvoreNaria* no1, NoArvoreNaria* no2);
        std::string toString(NoArvoreNaria* no);
        void liberarNos(NoArvoreNaria* no);

    public:
        ArvoreNaria();

        void defineRaiz(NoArvoreNaria* r);
        void insereFilho(NoArvoreNaria* pai, NoArvoreNaria* filho);
        bool vazia();
        bool pertence(std::string v);
        int numNos();
        int folhas();
        int altura();
        bool igual(ArvoreNaria* a);
        std::string toString();

        ~ArvoreNaria();
};


