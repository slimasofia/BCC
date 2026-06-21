#include "TabelaHash.hpp"

TabelaHash::TabelaHash(int tamanho) {
    this->tamanho = tamanho;
    tabela.resize(tamanho, nullptr); // inicializa o vetor com nullptrs
}

int TabelaHash::hash(int matricula) {
    return matricula % tamanho; // retorna o índice da tabela para a matrícula dada
} 

Aluno* TabelaHash::get(int matricula) {
    int indice = hash(matricula);
    Aluno* atual = tabela[indice];

    // percorre a lista encadeada procurando a matrícula correspondente
    while (atual != nullptr) {
        if (atual->getMatricula() == matricula) {
            return atual; // encontrou o aluno retorna o ponteiro dele
        }
        atual = atual->getProx(); // avança para o próximo nó
    }

    // se o while terminar e não entrar no if nenhuma vez, o aluno não existe
    return nullptr;
}

void TabelaHash::set(int matricula, std::string nome, std::string email, double mediaGeral) {
    // primeiro verifica se a matricula já existe na tabela
    if (contem(matricula)) {
        // se existir, atualiza os dados do aluno
        Aluno* aluno = get(matricula);
        aluno->setNome(nome);
        aluno->setEmail(email);
        aluno->setMediaGeral(mediaGeral);
    } else {
        // se não existir, cria um novo aluno e insere na lista correpondente ao índice calculado pela função hash
        Aluno* novoAluno = new Aluno(matricula, nome, email, mediaGeral);
        int indice = hash(matricula);
        if (tabela[indice] == nullptr) {
            tabela[indice] = novoAluno; // insere o novo aluno diretamente se a posição estiver vazia
        } else {
            // se a posição já estiver ocupada, insere o novo aluno no início da lista encadeada
            novoAluno->setProx(tabela[indice]);
            tabela[indice] = novoAluno; // atualiza o ponteiro da tabela para apontar para o novo aluno, que agora é o primeiro da lista
        }
    }
}

void TabelaHash::remove(int matricula) {

    int indice = hash(matricula);   // índice da matrícula do aluno procurado
    Aluno* atual = tabela[indice];  // aponta para o da lista encadeada
    Aluno* anterior = nullptr;

    // Caso 1: A lista não está vazia e o aluno procurado é o primeiro
    if(atual != nullptr && atual->getMatricula() == matricula) {
        tabela[indice] = atual->getProx();  // o início da lista passa a ser o segundo elemento
        delete atual;                       // libera a memória do aluno removido
        return;                             
    }

    // Caso 2: o aluno não é o primeiro, pode estar no meio ou no final
    while(atual != nullptr && atual->getMatricula() != matricula) {
        // para ir avançando na lista, o anterior guarda a posição atual e o atual avança para o próximo nó
        anterior = atual;
        atual = atual->getProx();
    }

    // o laço para porque a lista terminou ou porque a matricula foi encontrada
    // se o atual não for nulo, a matrícula foi encontrada
    if (atual != nullptr) {
        // atualiza o ponteiro anterior para apontar para o próximo do atual antes de remover
        anterior->setProx(atual->getProx());
        delete atual;
    }
}    

bool TabelaHash::contem(int matricula) {
    // retorna true se a matricula existe
    return get(matricula) != nullptr; 
}    

// retorna a quantidade de estudantes cadastrados
int TabelaHash::quantidade() {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        Aluno* atual = tabela[i];     

        while (atual != nullptr) {
            total++;
            atual = atual->getProx(); 
        } 
    }
    return total;
}


// retorna a quantidade de elementos que estão em posições com colisão
int TabelaHash::colisoes() {

    int colisoes = 0;
    // cada tabela[i] é um ponteiro para o início de uma lista encadeada, que pode estar vazia, ter um aluno ou vários
    for (int i = 0; i < tamanho; i++) {
        int tamanhoLista = 0;
        Aluno* atual = tabela[i];      // ponteiro auxiliar para percorrer a lista

        // conta o numero de elementos da lista desta posição
        while (atual != nullptr) {
            tamanhoLista++;  
            atual = atual->getProx(); 
        } 

        if(tamanhoLista > 0) {
            colisoes = colisoes + (tamanhoLista - 1);
        }
    }
    return colisoes;
}

// retorna o tamanho maior da lista encadeada da tabela
int TabelaHash::maiorLista() {

    int maior = 0;

    for (int i = 0; i < tamanho; i++) {
    
        int tamanhoLista = 0;
        Aluno* atual = tabela[i];     

        // conta o numero de elementos da lista
        while (atual != nullptr) {
            tamanhoLista++;  
            atual = atual->getProx(); 
        } 

        if(tamanhoLista > maior) {
            maior = tamanhoLista;
        }
    }
    return maior;
}

// retorna uma representação textual do conteúdo completo da tabela hash
std::string TabelaHash::toString() {
    std::string saida = ""; // Começamos com uma string vazia

    // percorre todas as posições do vetor da tabela
    for (int i = 0; i < tamanho; i++) {

        saida += "[" + std::to_string(i) + "] -> ";
        
        Aluno* atual = tabela[i]; // pega o primeiro aluno daquela posição
        
        // percorre a lista encadeada (se houver colisões, vai imprimir todos)
        while (atual != nullptr) {
            // concatena a matrícula
            saida += std::to_string(atual->getMatricula()) + " -> ";
            atual = atual->getProx();
        }
        
        saida += "null\n"; 
    }
    return saida;
}

TabelaHash::~TabelaHash() {
    // percorre todas as posições do vetor da tabela
    for (int i = 0; i < tamanho; i++) {
        Aluno* atual = tabela[i];
        
        // limpa a lista encadeada dessa posição
        while (atual != nullptr) {
            Aluno* proximo = atual->getProx(); // salva o caminho para o próximo
            delete atual;                      // libera a memória do nó atual
            atual = proximo;                   // avança para o próximo nó
        }
        
        tabela[i] = nullptr; 
    }
}