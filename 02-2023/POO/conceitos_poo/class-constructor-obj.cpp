#include <iostream>
using namespace std;

class calculadora{
    public:

    /*usando essa sintaxe para inicializar os membros da classe
    diretamente no construtor. Isso significa que o valor de x será
    substituído pelo valor de a, e o valor de y pelo valor de b. Devo 
    fazer isso quando quero inicializar os membros da classe com valores
    específicos.
    */
    calculadora(double a, double b) : x(a), y(b){
    }

     /*calculadora(double a, double b){
        x = a;
        y = b;
    } */

    double x, y;
    double somar(); // function declaration
    double mult();
    double sub();
    double div();
};

double calculadora::somar(){ // function definition
    return x + y;
}

double calculadora::mult(){
    return x * y;
}

double calculadora::sub(){
    return x - y;
}

double calculadora::div(){
    return x / y;
}

int main(){
    // calculadora calcular; não preciso declarar esse obj pq agora tenho um construtor
    
    /* para valores não específicos 
    double a, b;
    cout << "Digite o valor de x: " << endl;
    cin >> a;
    cout << "Digite o valor de y: " << endl;
    cin >> b;
    */

    //chamando o construtor
    calculadora calcular(1.0, 2.0); // agora aqui coloco os valores específicos com os quais quero inicializar o a e b
    //calculadora calcular(a, b); se eu não quisesse valores específicos

    cout << "Soma: " << calcular.somar() << endl;  //function calling
    cout << "Multiplicação: " << calcular.mult() << endl;
    cout << "Divisão: " << calcular.div() << endl;
    cout << "Subtração: " << calcular.sub() << endl;
    return 0;
}