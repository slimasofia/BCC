#include <iostream>
using namespace std;

class pointers {
private:
    int* x; // um ponteiro para um inteiro (armazena o endereço do inteiro)
    double *array; // um ponteiro para armazenar o enderço de um array de doubles   

public:
    pointers();
    ~pointers();
};

pointers::pointers() {
    x = new int; // aloca memória para esse inteiro
    array = new double[5];
}

pointers::~pointers() {
    delete x;
    delete[] array;
}

int main(){
    int valor = 10;
    array[0] = valor;
    cout << "array[0] = 10 " << array[0] << endl;
}