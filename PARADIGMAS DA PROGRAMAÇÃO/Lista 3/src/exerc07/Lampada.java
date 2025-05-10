package exerc07;
public class Lampada {

    public static void main(String[] args){
        Lampada lamp1 = new Lampada();
        Lampada lamp2 = lamp1;
        int i = 10;
        if (lamp1 == lamp2){
            System.out.println(i++); // 10
            System.out.println(i); // 11
        }
    }
}


