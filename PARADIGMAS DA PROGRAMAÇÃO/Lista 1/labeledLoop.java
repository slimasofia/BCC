/*
Considere o exemplo: Em uma sala, há 3 armários com 4 caixas cada um,
e precisamos procurar por um único livro que pode estar em qualquer ciaxa de qualquer armário.
o código abaixo demonstra o exemplo utilizando o conceito de Labeled Loop.

0 = caixa vazia
1 = livro na caixa

*/

public class labeledLoop {
    public static void main(String[] args) {
    int [][] sala = {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 1}
    };

    loop_m:
    for (int m = 0; m < sala.length; m++){
        loop_n:
        for (int n = 0; n < sala[m].length; n++) {
            if (sala[m][n] == 1) {
                System.out.print("Você encontrou o livro! Armário " + m + ", Caixa " + n);
                break loop_m;
            } else {
            System.out.println("Armário " + m + ", Caixa " + n + ": O livro não está aqui!");
        }
        }
    }
    }

}

