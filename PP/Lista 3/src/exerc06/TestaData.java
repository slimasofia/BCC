package exerc06;
import java.util.Scanner;

public class TestaData {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o dia: ");
        int dia = scanner.nextInt();

        System.out.print("Digite o mês: ");
        int mes = scanner.nextInt();

        System.out.print("Digite o ano: ");
        int ano = scanner.nextInt();

        Data d = new Data(dia, mes, ano);

        d.imprimirData();
        d.proximoDia();
    }
}
