#include <iostream>
#include <string>
#include "Calc.hpp"
#include "Pilha.hpp"

int main() {

    // TESTES
    
    std::cout << "---- PARTE 1: Implementação da Pilha ----\n" << std::endl;
    Pilha pilha;
        
        std::cout << "- Empilhando 10, 20 e 30..." << std::endl;
        pilha.push(10);
        pilha.push(20);
        pilha.push(30);
        
        std::cout << "\nTestando a função top():" << std::endl;
        std::cout << "- Valor no topo: " << pilha.top() << std::endl;
        
        std::cout << "\nTestando a função pop():" << std::endl;
        std::cout << "- Desempilhando o topo: " << pilha.pop() << std::endl;
        
        std::cout << "\nA pilha está vazia? ";
        if (pilha.vazia()) {
            std::cout << "Sim." << std::endl;
        } else {
            std::cout << "Não.\n" << std::endl;
        }
        
        pilha.libera();
        std::cout << "=============================================\n" << std::endl;


    std::cout << "---- PARTE 2: Calculadora Pós-Fixada ----\n" << std::endl;

    Calc calculadora;
    std::string entrada;

    std::cout << "Digite números, operadores ou 'q' para sair:" << std::endl;

    while (true) {
        std::cin >> entrada;

        // verifica se o usuário quer sair 
        if (entrada == "q") {
            break;
        }

        // verifica se a entrada é um operador
        if (entrada == "+" || entrada == "-" || entrada == "*" || entrada == "/") {
            calculadora.operador(entrada[0]);
        } 
        else {
            // se não for operador nem 'q', tenta ler como número (operando) 
            try {
                float valor = std::stof(entrada); // converte string para float
                calculadora.operando(valor);
            } catch (const std::invalid_argument& e) {
                std::cout << "Entrada invalida." << std::endl;
            }
        }
    }

    // libera os recursos antes de terminar 
    calculadora.libera();
    
    return 0;
}