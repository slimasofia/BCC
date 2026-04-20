#include "NoArvoreBinaria.hpp"

class ArvoreBinaria {
    private:
        NoArvoreBinaria* raiz;
        // métodos auxiliares recursivos
        bool pertence(NoArvoreBinaria* no, std::string info);
        int folhas(NoArvoreBinaria* no);
        int numNos(NoArvoreBinaria* no);
        int altura(NoArvoreBinaria* no);
        bool igual(NoArvoreBinaria* no1, NoArvoreBinaria* no2);
        std::string imprimePreOrdem(NoArvoreBinaria* no);
        std::string imprimeSimetrica(NoArvoreBinaria* no);
        std::string imprimePosOrdem(NoArvoreBinaria* no);
        void destruir(NoArvoreBinaria* no); 

    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void defineRaiz(NoArvoreBinaria* r);
        bool vazia();
        bool pertence(std::string info);
        int folhas();
        int numNos();
        int altura();
        bool igual(ArvoreBinaria& a);
        std::string imprimePreOrdem();
        std::string imprimeSimetrica();
        std::string imprimePosOrdem();
};

