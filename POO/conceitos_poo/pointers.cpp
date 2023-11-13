#include <iostream>
using namespace std;

// utilizado para retornar múltiplos valores,
// acessar elementos de um array,
// alocar memória dinamicamente

//um ponteiro armazena um endereço de memória

int main(){
    int n = 10;
    int *ptr;
    ptr = &n; 
    *ptr = 5; // manipulando o valor da variável n através do ponteiro. 'no enderço apontado por ptr adicione o valor 5'

    int arr[] = {10, 20, 30, 40};
    cout << arr[2] << endl;
    cout << *(arr + 2) << endl; // essa expressão é equivalente a primeira, mas utiliza a 
                                //aritmética de ponteiros: (arr + 2) indica a posição do 
                                //terceiro elemento e '*' é usado para acessar o valor nesse endereço.

    cout << "ptr: endereço da variável n na memória: " << ptr << endl; // retorna o endereço da variável n na memória, que está armazenada em ptr
    cout << "&n: endereço de n: " << &n << endl; // retorna o endereço da variável n na memória
    cout << "valor de n: " << n << endl;
    return 0;
}