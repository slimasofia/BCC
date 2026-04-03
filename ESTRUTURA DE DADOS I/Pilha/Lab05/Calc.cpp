#include "Calc.hpp"

Calc::Calc() {
    this->formato = "%.2f\n";
}

void Calc::operando(float v) {

    p.push(v); // empilha o operando

    // Imprime usando o formato armazenado no atributo da classe
    // .c_str() converte a string do c++ para o formato que o printf entende
    printf(this->formato.c_str(), v);
}

void Calc::operador(char op) {

    float v1, v2, resultado;

    // retira os dois valores do topo a pilha
    // se a pilha estiver vazia, assume zero
    v2 = (p.vazia()) ? 0 : p.pop();
    v1 = (p.vazia()) ? 0 : p.pop();

    switch (op) {

        case '+':
        resultado = v1 + v2;
        break;
    
        case '-':
        resultado = v1 - v2;
        break;

        case '*':
        resultado = v1 * v2;
        break;

        case '/':
        if(v2 == 0) {
            std::cerr << "Erro: Divisão por zero." << std::endl;
            return;
        }
        resultado = v1 / v2;
        break;

    default:
        std::cerr << "Operador inválido!" << std::endl;
        break;
    }

    // empilha o resultao e imprime
    p.push(resultado);
    printf(this->formato.c_str(), resultado);
}

void Calc::libera() {
    p.libera();
} 

Calc::~Calc() {}
