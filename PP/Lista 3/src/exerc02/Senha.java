package exerc02;
import java.util.Scanner;

public class Senha {
    private final String senhaCorreta = "123";
    private int tentativas = 0;
    private boolean bloq;

    public void entraSenha() {
        Scanner scan = new Scanner(System.in);

        while (tentativas < 3) {
            System.out.println("Digite a senha: ");
            String senha = scan.next();

            if (senha.equals(senhaCorreta)) {
                System.out.print("Senha correta.");
                break;
            } else {
                tentativas++;
                if (tentativas < 3) {
                    System.out.println("Senha incorreta. Restam " + (3 - tentativas) + " tentativas.");
                } else {
                    System.out.println("Senha incorreta. Você atingiu o limite de tentativas.");
                    bloq = true;
                    break;
                }
            }
        }
        scan.close();
    }

////    public void trocaSenha(String senha, String senhaNova){
////        if (estaBloqueada()){
////            System.out.println("A senha está bloqueada, não é possível alterá-la.");
////        } else {
////            entraSenha();
////        }
////    }
//
//
//    public boolean estaBloqueada(){
//        return bloq;
//    }
//
//
////    public static void trocaSenha(){
////        Scanner scan = new Scanner(System.in);
////        System.out.println("Deseja trocar a senha? S/N");
////
////    }
}