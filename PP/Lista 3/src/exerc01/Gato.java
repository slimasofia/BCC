package exerc01;
public class Gato implements Animal{

    @Override
    public void andar() {
        System.out.print("Andando...");
    }

    @Override
    public void comer() {
        System.out.print("Comendo...");
    }

    @Override
    public void correr() {
        System.out.print("Correndo...");
    }
}
