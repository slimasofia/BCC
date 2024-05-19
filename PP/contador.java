import java.util.Scanner;

public class contador{
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Digite um número: ");
            int n = scanner.nextInt();

            if (n < 0){
                System.out.print("Inválido. Digite um número positivo. ");
            } else{
                contador(n);
            }
        }

        public static int contador(int n) {
            System.out.println(n);
            if (n == 0){
                System.out.println("BOOM!");
                return n;
            }
            return contador(n-1);
        }
    }


