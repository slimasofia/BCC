#pragma once
#include "Aluno.hpp"
#include <string>
#include <vector>

class TabelaHash {
    private:
    std::vector<Aluno*> tabela; // vetor de ponteiros para alunos
    int tamanho;

    int hash(int matricula); // função de hash para calcular o índice a partir da matrícula
        
    public:
        TabelaHash(int tamanho);

        Aluno* get(int matricula);      // função para obter um aluno a partir da matrícula, retornando um ponteiro para o aluno ou nullptr se não encontrado
        void set(int matricula, std::string nome, std::string email, double mediaGeral); // inserir ou atualizar um aluno 
        void remove(int matricula);     // função para remover um aluno a partir da matrícula, se ele existir
        bool contem(int matricula);     // função para verificar se um aluno com a matrícula existe na tabela
        int colisoes();
        int quantidade();
        int maiorLista();               // retorna o tamanho da maior lista encadeada da tabela
        std::string toString(); 

        ~TabelaHash();
    };

