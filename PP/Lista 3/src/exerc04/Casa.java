package exerc04;
import exerc03.Porta;

public class Casa {
    private Porta porta1;
    private Porta porta2;
    private Porta porta3;
    private String cor;

    public Casa(Porta porta1, Porta porta2, Porta porta3, String cor) {
        this.porta1 = porta1;
        this.porta2 = porta2;
        this.porta3 = porta3;
        this.cor = cor;
    }

    public void pinta(String cor){
        this.cor = cor;
    }

    public int quantasPortasEstaoAbertas(){
        int c = 0;
        if (porta1.estaAberta()) {
            c++;
        }
        if (porta2.estaAberta()) {
            c++;
        }
        if (porta3.estaAberta()) {
            c++;
        }
        return c;
    }

    public String getCor(){
        return cor;
    }

    public Porta getPorta1(){
        return porta1;
    }

    public Porta getPorta2(){
        return porta2;
    }

    public Porta getPorta3(){
        return porta3;
    }
}
