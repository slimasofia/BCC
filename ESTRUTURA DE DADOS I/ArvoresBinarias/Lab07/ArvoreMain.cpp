#include <iostream>
#include "ArvoreBinaria.hpp"
#include "NoArvoreBinaria.hpp"

int main() {
    std::cout << "=================================================" << std::endl;
    std::cout << "          CHAVEAMENTO - COPA DO MUNDO     " << std::endl;
    std::cout << "=================================================\n" << std::endl;

    // 1. montar manualmente uma árvore binária (4 seleções e 3 partidas)
    // criação das Folhas (Seleções)
    NoArvoreBinaria* brasil = new NoArvoreBinaria("Brasil", nullptr, nullptr);
    NoArvoreBinaria* argentina = new NoArvoreBinaria("Argentina", nullptr, nullptr);
    NoArvoreBinaria* franca = new NoArvoreBinaria("França", nullptr, nullptr);
    NoArvoreBinaria* alemanha = new NoArvoreBinaria("Alemanha", nullptr, nullptr);

    // criação dos nós internos (partidas) ligando as seleções
    NoArvoreBinaria* semi1 = new NoArvoreBinaria("Semifinal 1", brasil, argentina);
    NoArvoreBinaria* semi2 = new NoArvoreBinaria("Semifinal 2", franca, alemanha);
    
    // criação da raiz (final) ligando as semifinais
    NoArvoreBinaria* finalCopa = new NoArvoreBinaria("Final", semi1, semi2);

    // instancia a árvore e define a raiz
    ArvoreBinaria chaveamento1;
    chaveamento1.defineRaiz(finalCopa);

    std::cout << "[1] Árvore de chaveamento principal criada!\n\n";

    // 2. imprimir a árvore nas três ordens de visitação
    std::cout << "[2] IMPRESSÃO DAS TRAVESSIAS:" << std::endl;
    std::cout << " - Pré-ordem (Raiz, Esq, Dir): " << chaveamento1.imprimePreOrdem() << std::endl;
    std::cout << " - Simétrica (Esq, Raiz, Dir): " << chaveamento1.imprimeSimetrica() << std::endl;
    std::cout << " - Pós-ordem (Esq, Dir, Raiz): " << chaveamento1.imprimePosOrdem() << std::endl;
    std::cout << std::endl;

    // 3. informar o número total de nós do chaveamento
    std::cout << "INFORMAÇÕES DA ÁRVORE:" << std::endl;
    std::cout << " - [3] Número total de nós: " << chaveamento1.numNos() << std::endl;

    // 4. informar a quantidade de folhas do chaveamento
    std::cout << " - [4] Quantidade de folhas (Seleções): " << chaveamento1.folhas() << std::endl;

    // 5. informar a altura da árvore
    std::cout << " - [5] Altura da árvore: " << chaveamento1.altura() << std::endl;
    std::cout << std::endl;

    // 6. verificar se determinada seleção ou partida pertence à árvore
    std::cout << "[6] BUSCA NO CHAVEAMENTO:" << std::endl;
    std::string busca1 = "Brasil";
    std::string busca2 = "Itália"; // Time que não está na árvore
    
    std::cout << " - A seleção '" << busca1 << "' pertence ao chaveamento? " 
              << (chaveamento1.pertence(busca1) ? "Sim" : "Não") << std::endl;
              
    std::cout << " - A seleção '" << busca2 << "' pertence ao chaveamento? " 
              << (chaveamento1.pertence(busca2) ? "Sim" : "Não") << std::endl;
    std::cout << std::endl;

    // 7. criar uma segunda árvore e testar se os dois chaveamentos são iguais
    std::cout << "[7] COMPARAÇÃO DE ÁRVORES:" << std::endl;
    
    // criando uma segunda árvore idêntica
    NoArvoreBinaria* b2 = new NoArvoreBinaria("Brasil", nullptr, nullptr);
    NoArvoreBinaria* a2 = new NoArvoreBinaria("Argentina", nullptr, nullptr);
    NoArvoreBinaria* f2 = new NoArvoreBinaria("França", nullptr, nullptr);
    NoArvoreBinaria* al2 = new NoArvoreBinaria("Alemanha", nullptr, nullptr);

    NoArvoreBinaria* s1_2 = new NoArvoreBinaria("Semifinal 1", b2, a2);
    NoArvoreBinaria* s2_2 = new NoArvoreBinaria("Semifinal 2", f2, al2);
    NoArvoreBinaria* fin2 = new NoArvoreBinaria("Final", s1_2, s2_2);

    ArvoreBinaria chaveamento2;
    chaveamento2.defineRaiz(fin2);

    // exibindo o segundo chaveamento para conferir 
    std::cout << " - Chaveamento 2 criado para teste da função 'igual()'." << std::endl;
    std::cout << " - Conteúdo do Chaveamento 2 (Pré-ordem): " << std::endl;
    std::cout << "   " << chaveamento2.imprimePreOrdem() << std::endl;

    std::cout << "\n - O chaveamento 1 é igual ao chaveamento 2? " 
              << (chaveamento1.igual(chaveamento2) ? "Sim" : "Não") << std::endl;

    std::cout << "\n=================================================" << std::endl;
    std::cout << " Encerrando o programa e limpando a memória...   " << std::endl;
    std::cout << "=================================================\n" << std::endl;

    return 0;
}