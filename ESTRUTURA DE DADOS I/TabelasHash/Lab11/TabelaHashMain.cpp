#include <iostream>
#include <string>
#include "TabelaHash.hpp"

using namespace std;

// Função auxiliar para imprimir o resultado das buscas
void imprimirBusca(TabelaHash& tabela, int matricula) {
    Aluno* aluno = tabela.get(matricula);
    if (aluno != nullptr) {
        cout << aluno->toString() << endl; 
    } else {
        cout << "  -> Aluno com matrícula " << matricula << " não encontrado." << endl;
    }
}

int main() {
    cout << "=== INICIANDO TESTES DA TABELA HASH ===" << endl;

    // 1. Criar uma tabela hash vazia com tamanho primo (127)
    TabelaHash tabela(127);

    // 2 e 3. Inserir pelo menos 15 estudantes (incluindo colisões intencionais)
    cout << "\nInserindo estudantes (incluindo colisões de propósito)..." << endl;
    
    // Colisões 
    tabela.set(1001, "aluno1", "aluno1@email.com", 8.5);
    tabela.set(1128, "aluno2", "aluno2@email.com", 7.2);
    tabela.set(1255, "aluno3", "aluno3@email.com", 9.1);
    tabela.set(1382, "aluno4", "aluno4@email.com", 6.8);

    tabela.set(2002, "aluno5", "aluno5@email.com", 8.0);
    tabela.set(2129, "aluno6", "aluno6@email.com", 7.5);
    tabela.set(2256, "aluno7",  "aluno7@email.com",  9.5);

    tabela.set(3003, "aluno8",  "aluno8@email.com",  6.0);
    tabela.set(3130, "aluno9",  "aluno9@email.com",  8.8);

    // Sem colisões intencionais entre si
    tabela.set(4010, "aluno10", "aluno10@email.com", 9.0);
    tabela.set(5020, "aluno11",  "aluno11@email.com",  7.9);
    tabela.set(6030, "aluno12",  "aluno12@email.com",  8.2);
    tabela.set(7040, "aluno13","aluno13@email.com",6.5);
    tabela.set(8050, "aluno14",  "aluno14@email.com",  9.8);
    tabela.set(9060, "aluno15","aluno15@email.com",7.1);

    // 4. Buscar pelo menos três matrículas existentes
    cout << "\nBuscando matrículas EXISTENTES:" << endl;
    imprimirBusca(tabela, 1001);
    imprimirBusca(tabela, 2129);
    imprimirBusca(tabela, 6030);

    // 5. Buscar pelo menos três matrículas inexistentes
    cout << "\nBuscando matrículas INEXISTENTES:" << endl;
    imprimirBusca(tabela, 9999);
    imprimirBusca(tabela, 1234);
    imprimirBusca(tabela, 5555);

    // 6. Atualizar os dados de um estudante já cadastrado
    cout << "\nAtualizando dados da matrícula 1001 (aluno1)..." << endl;
    tabela.set(1001, "aluno1 atualizado", "aluno1.nova@email.com", 10.0);
    imprimirBusca(tabela, 1001);

    // 7. Remover um estudante que esteja no início de uma lista de colisão
    // Como a inserção é no início da lista, o último inserido no bloco (1382) está na cabeça
    cout << "\nRemovendo matrícula 1382 (Inicio da lista de colisão)..." << endl;
    tabela.remove(1382);
    imprimirBusca(tabela, 1382);

    // 8. Remover um estudante que esteja no meio/final de uma lista de colisão
    cout << "\nRemovendo matrícula 1128 (Meio/Final da lista de colisão)..." << endl;
    tabela.remove(1128);
    imprimirBusca(tabela, 1128);

    // 9. Tentar remover uma matrícula inexistente
    cout << "\nTentando remover matrícula inexistente (9999)..." << endl;
    tabela.remove(9999); 

    // 10. Imprimir a tabela hash completa
    cout << "\n=== IMPRIMINDO TABELA HASH COMPLETA ===" << endl;
    string impressaoCompleta = tabela.toString();
    cout << impressaoCompleta << endl;

    // 11, 12 e 13. Informações da tabela
    cout << "\n=== INFORMAÇÕES DA TABELA ===" << endl;
    cout << "Total de estudantes cadastrados: " << tabela.quantidade() << endl;
    cout << "Quantidade de colisões: " << tabela.colisoes() << endl;
    cout << "Tamanho da maior lista: " << tabela.maiorLista() << endl;

    return 0;
}



