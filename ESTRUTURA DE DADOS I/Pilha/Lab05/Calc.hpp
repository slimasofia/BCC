#include <iostream>
#include "Pilha.hpp"

class Calc {

    private:
        std::string formato;
        Pilha p;

    public:
        Calc();

        void operando(float v);
        void operador(char op);
        void libera();

        ~Calc();
};
