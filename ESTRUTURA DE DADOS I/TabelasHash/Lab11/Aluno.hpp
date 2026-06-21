#pragma once
#include <iostream>
#include <string>

class Aluno {
    private:
        int matricula;
        std::string nome;
        std::string email;
        double mediaGeral;
        Aluno* prox;

    public:
        Aluno(int matricula, std::string nome, std::string email, double mediaGeral);

        int getMatricula();
        std::string getNome();  
        std::string getEmail();
        double getMediaGeral();
        Aluno* getProx();

        std::string toString();

        void setMatricula(int matricula);
        void setNome(std::string nome);
        void setEmail(std::string email);
        void setMediaGeral(double mediaGeral);
        void setProx(Aluno* prox);

        ~Aluno();
    };

