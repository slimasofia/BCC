#pragma once

#include <string>

class NoArvoreNaria {
private:
    std::string info;       // string armazenada no nó
    NoArvoreNaria* prim;    // referência para o primeiro filho do nó
    NoArvoreNaria* prox;    // referẽncia para o próximo irmão do nó

public:
    NoArvoreNaria(std::string info);
    ~NoArvoreNaria();

    // getters e setters
    std::string getInfo();
    NoArvoreNaria* getPrim();
    NoArvoreNaria* getProx();

    void setInfo(std::string info);
    void setPrim(NoArvoreNaria* prim);
    void setProx(NoArvoreNaria* prox);
};