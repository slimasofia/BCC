package exerc05;
public class CalculadoraCientifica extends Calculadora {

    public double potencia(double b, double e) {
        return Math.pow(b, e);
    /*
    Tentei fazer dessa forma também para usar o método multiplicar
    já que era pra usar herança mas aí "e" deveria ser int

    double resultado = 1.0;
    for (int i = 0; i < e; i++) {
    resultado = multiplicar(resultado, b);
    }
    */
    }
}


