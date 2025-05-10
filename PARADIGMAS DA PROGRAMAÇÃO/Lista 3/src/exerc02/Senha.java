package exerc02;

public class Senha {
    private String senha;
    private int tentativas = 0;
    private boolean bloq = false;

    public Senha(String senhaInicial) {
        this.senha = senhaInicial;
    }

    private boolean verificaSenha(String s) {
        return senha.equals(s);
    }

    public boolean estaBloqueada() {
        return bloq;
    }

    public boolean entraSenha(String s) {
        if (bloq) {
            System.out.println("A senha está bloqueada.");
            return false;
        }

        if (verificaSenha(s)) {
            System.out.println("Senha correta.");
            tentativas = 0;
            return true;
        } else {
            tentativas++;
            if (tentativas < 3) {
                System.out.println("Senha incorreta. Restam " + (3 - tentativas) + " tentativas.");
            } else {
                System.out.println("Senha incorreta. Você atingiu o limite de tentativas.");
                bloq = true;
            }
            return false;
        }
    }

    public void trocaSenha(String senhaAntiga, String senhaNova) {
        if (estaBloqueada()) {
            System.out.println("A senha está bloqueada, não é possível alterá-la.");
        } else {
            if (entraSenha(senhaAntiga)) {
                senha = senhaNova;
                tentativas = 0;
                System.out.println("Senha alterada com sucesso.");
            } else{
                System.out.println("Senha antiga incorreta. Não foi possível alterar a senha.");
                tentativas++;
                if (tentativas >= 3) {
                    bloq = true;
                    System.out.println("Você atingiu o limite de tentativas e a senha foi bloqueada.");
                }
            }
        }
    }
}