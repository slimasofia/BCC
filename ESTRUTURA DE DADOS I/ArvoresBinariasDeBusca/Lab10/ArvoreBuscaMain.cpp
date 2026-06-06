#include <iostream>
#include "ArvoreBinariaBusca.hpp"

int main() {
    ArvoreBinariaBusca arvore;

    std::cout << "Árvore criada.\n";
    std::cout << "A árvore está vazia? "
              << (arvore.vazia() ? "Sim" : "Não") << "\n\n";

    int codigos[] = {
        50, 30, 70, 20, 40, 60, 80,
        35, 45, 55, 65, 75, 85, 10, 25
    };

    for (int i = 0; i < 15; i++) {
        arvore.insere(codigos[i]);
    }

    std::cout << "Códigos inseridos.\n";
    std::cout << "A árvore está vazia? "
              << (arvore.vazia() ? "Sim" : "Não") << "\n\n";

    std::cout << "Ordem crescente:\n";
    std::cout << arvore.toString() << "\n\n";

    std::cout << "Ordem decrescente:\n";
    std::cout << arvore.toStringDecrescente() << "\n\n";

    int existentes[] = {60, 35, 25};

    std::cout << "Busca por códigos existentes:\n";
    for (int i = 0; i < 3; i++) {
        int codigo = existentes[i];

        std::cout << "Código " << codigo << ": "
                  << (arvore.pertence(codigo) ? "encontrado" : "não encontrado")
                  << "\n";
    }

    std::cout << "\n";

    int inexistentes[] = {14, 2, 90};

    std::cout << "Busca por códigos inexistentes:\n";
    for (int i = 0; i < 3; i++) {
        int codigo = inexistentes[i];

        std::cout << "Código " << codigo << ": "
                  << (arvore.pertence(codigo) ? "encontrado" : "não encontrado")
                  << "\n";
    }

    std::cout << "\n";

    std::cout << "Número total de nós: " << arvore.numNos() << "\n";
    std::cout << "Quantidade de folhas: " << arvore.folhas() << "\n";
    std::cout << "Altura da árvore: " << arvore.altura() << "\n\n";

    std::cout << "Removendo nó folha: 10\n";
    arvore.retira(10);
    std::cout << "Ordem crescente após remover 10:\n";
    std::cout << arvore.toString() << "\n\n";

    std::cout << "Removendo nó com apenas um filho: 20\n";
    arvore.retira(20);
    std::cout << "Ordem crescente após remover 20:\n";
    std::cout << arvore.toString() << "\n\n";

    std::cout << "Removendo nó com dois filhos: 70\n";
    arvore.retira(70);
    std::cout << "Ordem crescente após remover 70:\n";
    std::cout << arvore.toString() << "\n\n";

    std::cout << "Dados finais da árvore:\n";
    std::cout << "Número total de nós: " << arvore.numNos() << "\n";
    std::cout << "Quantidade de folhas: " << arvore.folhas() << "\n";
    std::cout << "Altura da árvore: " << arvore.altura() << "\n";

    return 0;
}