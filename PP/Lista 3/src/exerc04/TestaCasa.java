package exerc04;
import exerc03.Porta;

public class TestaCasa {
    public static void main(String[] args) {
        Porta porta1 = new Porta("Marrom",false,0.76,2.10,0.74);
        Porta porta2 = new Porta("Branca",true,0.78,2.00,0.71);
        Porta porta3 = new Porta("Preta",false,0.77,1.90,0.70);

        Casa casa = new Casa(porta1, porta2, porta3,"Azul");

        System.out.println("A cor da casa é: " + casa.getCor());
        casa.pinta(("Laranja"));
        System.out.println("A nova cor da casa é: " + casa.getCor());

        System.out.println("A quantidade de portas abertas é: " + casa.quantasPortasEstaoAbertas());

        casa.getPorta1();
        casa.getPorta2();
        casa.getPorta3();
    }
}
