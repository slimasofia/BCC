#include <iostream>
using namespace std;

/*
Seja A() uma função chamadora e B() uma função receptora. 
Os argumentos que A envia para B são argumentos reais,
e os parâmetros de B são argumentos formais.
*/

int multiplicar(int X, int Y)
{
    // Modifica o X para 2
    X = 2;
    return X*Y;
}


void swapNums(int &x, int &y) {
  //quando essa função é executada:
  int z = x;  // x vale 10, y vale 20
  x = y; // z vale 10
  y = z; //x vale 20
  // y vale 10
}

int main() {
  cout << "Exemplo de passagem por referência " << endl;

  int firstNum = 10;
  int secondNum = 20;

  cout << "Before swap: ";
  cout << firstNum << secondNum << "\n";

  swapNums(firstNum, secondNum);

  cout << "After swap: ";
  cout << firstNum << secondNum << "\n";


  /* 
  
  nesse exemplo, uma váriavel "valor" é declarada e passada como parâmetro para a função multiplicar()
  e a função é chamada, mas ao imprimir a variável valor, ela ainda é 3, pois na passagem por valor, apenas
  uma CÓPIA DO VALOR da variável foi mandada para função quando ela foi chamada, e isso não afetou a variável original
  (a variável que é passada como argumento).

  */

  cout << "Exemplo de passagem por valor " << endl;
  int valor = 3;
  int resultado = multiplicar(valor, 3);
  cout << valor << endl; 
  cout << resultado << endl;
  return 0;
}


/*USAR PASSAGEM POR REFERÊNCIA QUANDO: 
Quero que a função altere o valor original do argumento,
Preciso que a função retorne mais de um valor,
Evitar a cópia desnecessária de dados grandes.