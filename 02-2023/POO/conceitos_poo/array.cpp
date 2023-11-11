#include <iostream>

class DynamicArray {
private:
    int* arr; // ponteiro para o array
    int size; // tamanho do array

public:
    // Construtor para inicializar o array
    DynamicArray(int s) : size(s) {
        arr = new int[size]; // alocação de memória dinâmica
    }

    // Destrutor para liberar a memória alocada
    ~DynamicArray() {
        delete[] arr; // desalocação de memória dinâmica
    }

    // Outros métodos para manipular o array dinâmico
    void setValue(int index, int value) {
        arr[index] = value;
    }

    int getValue(int index) {
        return arr[index];
    }
};

int main() {
    // Criando um objeto da classe DynamicArray
    DynamicArray array(5);

    // Usando métodos da classe
    array.setValue(0, 1);
    array.setValue(1, 2);
    array.setValue(2, 3);
    array.setValue(3, 4);
    array.setValue(4, 5);

    // Acessando valores do array dinâmico
    for (int i = 0; i < 5; i++) {
        std::cout << "Valor no índice " << i << " é " << array.getValue(i) << std::endl;
    }

    return 0;
}
