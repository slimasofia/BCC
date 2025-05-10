package exerc05;
import java.util.Scanner;

public class TestaCalculadoras {
    public static void main(String[] args){
        double a, b;

        Scanner scan = new Scanner(System.in);
        System.out.println("Digite o primeiro número: ");
        a = scan.nextDouble();
        System.out.println("Digite o segundo número: ");
        b = scan.nextDouble();

        CalculadoraCientifica c = new CalculadoraCientifica();
        System.out.println(a + " + " + b + " = " + c.somar(a, b));
        System.out.println(a + " - " + b + "= " + c.subtrair(a, b));
        System.out.println(a + " x " + b + "= " + c.multiplicar(a, b));
        System.out.println(a + " / " + b + "= " + c.dividir(a, b));
        System.out.println(a + "^" + b + "=" + c.potencia(a, b));
    }
}
