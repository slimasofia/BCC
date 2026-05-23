#include <iostream>
#include "ArvoreNaria.hpp"

int main() {

    ArvoreNaria arvore;

    // --- raiz ---
    NoArvoreNaria* ifc = new NoArvoreNaria("IFC");
    arvore.defineRaiz(ifc);

    // --- campi (filhos da raiz) ---
    NoArvoreNaria* blumenau  = new NoArvoreNaria("Campus Blumenau");
    NoArvoreNaria* camboriu  = new NoArvoreNaria("Campus Camboriú");
    NoArvoreNaria* araquari  = new NoArvoreNaria("Campus Araquari");

    arvore.insereFilho(ifc, araquari);
    arvore.insereFilho(ifc, camboriu);
    arvore.insereFilho(ifc, blumenau);

    // --- cursos do campus Blumenau ---
    NoArvoreNaria* bcc        = new NoArvoreNaria("BCC");
    NoArvoreNaria* pedagogia  = new NoArvoreNaria("Pedagogia");
    NoArvoreNaria* adminis    = new NoArvoreNaria("Administração");

    arvore.insereFilho(blumenau, adminis);
    arvore.insereFilho(blumenau, pedagogia);
    arvore.insereFilho(blumenau, bcc);

    // --- disciplinas do BCC ---
    NoArvoreNaria* ed1    = new NoArvoreNaria("Estruturas de Dados I");
    NoArvoreNaria* prog2  = new NoArvoreNaria("Programação II");
    NoArvoreNaria* bd     = new NoArvoreNaria("Banco de Dados");

    arvore.insereFilho(bcc, bd);
    arvore.insereFilho(bcc, prog2);
    arvore.insereFilho(bcc, ed1);

    // --- setores do Campus Blumenau ---
    NoArvoreNaria* coordEnsino = new NoArvoreNaria("Coordenação de Ensino");
    NoArvoreNaria* biblioteca  = new NoArvoreNaria("Biblioteca");

    arvore.insereFilho(blumenau, biblioteca);
    arvore.insereFilho(blumenau, coordEnsino);

    // 5. imprimir a árvore em formato textual hierárquico
    std::cout << "--- Representação textual da árvore ---" << std::endl;
    std::cout << arvore.toString() << std::endl << std::endl;

    // 6. número total de nós
    std::cout << "--- Número total de nós ---" << std::endl;
    std::cout << arvore.numNos() << " nós" << std::endl << std::endl;

    // 7. quantidade de folhas
    std::cout << "--- Quantidade de folhas ---" << std::endl;
    std::cout << arvore.folhas() << " folhas" << std::endl << std::endl;

    // 8. altura da árvore
    std::cout << "--- Altura da árvore ---" << std::endl;
    std::cout << arvore.altura() << std::endl << std::endl;

    // 9. verificar se determinados nomes pertencem à árvore
    std::cout << "--- Verificação de pertencimento ---" << std::endl;

    std::string buscas[] = {
        "IFC",
        "Campus Blumenau",
        "BCC",
        "Estruturas de Dados I",
        "Campus Joinville"   // não existe
    };

    for (const std::string& s : buscas) {
        std::cout << "\"" << s << "\": "
                  << (arvore.pertence(s) ? "pertence" : "não pertence")
                  << std::endl;
    }
    std::cout << std::endl;

    // 10. criar uma segunda árvore e testar se as duas são iguais
    ArvoreNaria arvore2;

    NoArvoreNaria* ifc2        = new NoArvoreNaria("IFC");
    NoArvoreNaria* blumenau2   = new NoArvoreNaria("Campus Blumenau");
    NoArvoreNaria* camboriu2   = new NoArvoreNaria("Campus Camboriú");
    NoArvoreNaria* araquari2   = new NoArvoreNaria("Campus Araquari");
    NoArvoreNaria* bcc2        = new NoArvoreNaria("BCC");
    NoArvoreNaria* pedagogia2  = new NoArvoreNaria("Pedagogia");
    NoArvoreNaria* adminis2    = new NoArvoreNaria("Administração");
    NoArvoreNaria* ed1_2       = new NoArvoreNaria("Estruturas de Dados I");
    NoArvoreNaria* prog2_2     = new NoArvoreNaria("Programação II");
    NoArvoreNaria* bd2         = new NoArvoreNaria("Banco de Dados");
    NoArvoreNaria* coordEnsino2= new NoArvoreNaria("Coordenação de Ensino");
    NoArvoreNaria* biblioteca2 = new NoArvoreNaria("Biblioteca");

    arvore2.defineRaiz(ifc2);
    arvore2.insereFilho(ifc2, araquari2);
    arvore2.insereFilho(ifc2, camboriu2);
    arvore2.insereFilho(ifc2, blumenau2);
    arvore2.insereFilho(blumenau2, adminis2);
    arvore2.insereFilho(blumenau2, pedagogia2);
    arvore2.insereFilho(blumenau2, bcc2);
    arvore2.insereFilho(bcc2, bd2);
    arvore2.insereFilho(bcc2, prog2_2);
    arvore2.insereFilho(bcc2, ed1_2);
    arvore2.insereFilho(blumenau2, biblioteca2);
    arvore2.insereFilho(blumenau2, coordEnsino2);

    std::cout << "--- Comparação entre arvore1 e arvore2 (devem ser iguais) ---" << std::endl;
    std::cout << "São iguais: " << (arvore.igual(&arvore2) ? "sim" : "não") << std::endl << std::endl;

    // 11. alterar a segunda árvore e testar novamente
    NoArvoreNaria* novoNo = new NoArvoreNaria("Engenharia de Software");
    arvore2.insereFilho(bcc2, novoNo);

    std::cout << "--- Após alterar arvore2 (adicionar \"Engenharia de Software\" em BCC) ---" << std::endl;
    std::cout << "São iguais: " << (arvore.igual(&arvore2) ? "sim" : "não") << std::endl << std::endl;

    return 0;
}
