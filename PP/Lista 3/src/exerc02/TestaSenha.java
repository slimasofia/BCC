package exerc02;
import java.util.Scanner;

public class TestaSenha {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Defina a senha: ");
        String senhaInicial = scanner.nextLine();
        Senha senha = new Senha(senhaInicial);

        boolean continuar = true;

        while (continuar) {
            System.out.println("\nMenu:");
            System.out.println("1. Entrar com senha");
            System.out.println("2. Trocar senha");
            System.out.println("3. Verificar se a senha está bloqueada");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");
            int opcao = scanner.nextInt();
            scanner.nextLine();  // Consome a nova linha

            switch (opcao) {
                case 1:
                    System.out.print("Digite a senha: ");
                    String tentativaSenha = scanner.nextLine();
                    senha.entraSenha(tentativaSenha);
                    break;
                case 2:
                    System.out.print("Digite a senha antiga: ");
                    String senhaAntiga = scanner.nextLine();
                    System.out.print("Digite a nova senha: ");
                    String senhaNova = scanner.nextLine();
                    senha.trocaSenha(senhaAntiga, senhaNova);
                    break;
                case 3:
                    System.out.println("A senha está bloqueada? " + senha.estaBloqueada());
                    break;
                case 4:
                    continuar = false;
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        }

        scanner.close();
    }
}
