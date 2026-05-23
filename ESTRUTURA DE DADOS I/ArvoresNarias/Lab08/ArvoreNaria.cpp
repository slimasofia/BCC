#include "ArvoreNaria.hpp"

ArvoreNaria::ArvoreNaria() {
    this->raiz = nullptr;
}

void ArvoreNaria::defineRaiz(NoArvoreNaria* r) {
    raiz = r;
}

// O novo filho será irmão dos filhos que o pai já tem e ficará no mesmo nível deles
void ArvoreNaria::insereFilho(NoArvoreNaria* pai, NoArvoreNaria* filho) {
    // o prox do novo filho irá apontar para o que antes era o primeiro filho
    filho->setProx(pai->getPrim());
    // o novo filho se torna o primeiro filho
    pai->setPrim(filho);
}

bool ArvoreNaria::vazia() {
    return raiz == nullptr;
}

// 'no' representa o nó atual, e 'p' recebe o primeiro filho dele
bool ArvoreNaria::pertence(NoArvoreNaria* no, std::string v) {
    if(no->getInfo() == v) {
        return true;
    } else {
        // pega o primeiro filho e entra no laço pra visitar cada irmão
        NoArvoreNaria* p = no->getPrim();
        while(p != nullptr) {
            if (pertence(p, v)) {
                return true;
            }
            p = p->getProx();
        }
    }
    return false;
}

bool ArvoreNaria::pertence(std::string v) {
    return pertence(raiz, v);
}

int ArvoreNaria::numNos(NoArvoreNaria* no) {
    // já considera a existência do nó recebido como argumento
    int total = 1;

    // pega o primeiro filho e entra no laço pra visitar cada irmão
    NoArvoreNaria* p = no->getPrim();
    while(p != nullptr) {
        total += numNos(p);
        p = p->getProx();
    }

    return total;
}

int ArvoreNaria::numNos() {
    return numNos(raiz);
}

// conta apenas os nós que ficam nas folhas das árvores
// um nó folha é aquele cuja referência prim é null, ou seja, ele não tem filhos
int ArvoreNaria::folhas(NoArvoreNaria* no) {

    int total = 0;
    NoArvoreNaria* p = no->getPrim();

    if(no->getPrim() == nullptr) {   
        total = 1;
    } else {
        while(p != nullptr) {
            total += folhas(p);
            p = p->getProx();
        }    
    }
    return total;
}

int ArvoreNaria::folhas() {
    return folhas(raiz);
}

// a altura de uma árvore é o caminho mais longo da raiz até a folha mais profunda
// a altura de uma árvore com apenas um nó (uma folha) é 0.
int ArvoreNaria::altura(NoArvoreNaria* no) {
    int hmax = -1;

    // pega o primeiro filho e entra no laço pra visitar cada irmão
    NoArvoreNaria* p = no->getPrim();
    while(p != nullptr) {
        // guarda a altura do nó atual
        int h = altura(p);
        // se a altura do nó atual for maior que a altura máxima registrada até o momento
        if(h > hmax) {
            hmax = h; // atualiza
        }
        p = p->getProx();
    }

    return hmax + 1;
}

int ArvoreNaria::altura() {
    return altura(raiz);
}

// verifica se a árvore atual e a árvore 'a' possuem a mesma estrutura e valores
bool ArvoreNaria::igual(NoArvoreNaria* no1, NoArvoreNaria* no2) {

    // se um nó for nulo e o outro não
    if((no1 == nullptr && no2 != nullptr) || (no2 == nullptr && no1 != nullptr)) {
        return false;
    }

    // se os dois nós forem nulos
    if(no1 == nullptr && no2 == nullptr) {
        return true;
    }   

    // se as informações dos nós forem diferentes
    if(no1->getInfo() != no2->getInfo()) {
        return false;
    }

    return igual(no1->getPrim(), no2->getPrim()) && igual(no1->getProx(), no2->getProx());
}


bool ArvoreNaria::igual(ArvoreNaria* a) {
    return igual(raiz, a->raiz);
}

std::string ArvoreNaria::toString(NoArvoreNaria* no) {
    // caso base: se o nó não existir
    if(no == nullptr) {
        return "";
    } 

    // concatena a informação do nó atual
    std::string s = "<" + no->getInfo();

    // pega o primeiro filho e entra no laço pra visitar cada irmão
    NoArvoreNaria* p = no->getPrim();
    while(p != nullptr) {
        s += toString(p);
        p = p->getProx();
    }

    s = s + ">";
    return s;
}

std::string ArvoreNaria::toString() {
    return toString(raiz);
}

// liberar a memória
void ArvoreNaria::liberarNos(NoArvoreNaria* no) {
    // caso base: se o nó não existe, não há o que deletar
    if (no == nullptr) {
        return;
    }

    // libera todos os filhos
    liberarNos(no->getPrim());

    // libera todos os irmãos
    liberarNos(no->getProx());

    // deleta nó atual
    delete no;
}

ArvoreNaria::~ArvoreNaria() {
    liberarNos(raiz);
    raiz = nullptr; 
}