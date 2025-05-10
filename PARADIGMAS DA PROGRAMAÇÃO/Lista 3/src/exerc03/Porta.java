package exerc03;

public class Porta {
    private boolean aberta;
    private String cor;
    private double dimensaoX, dimensaoY, dimensaoZ;

    public Porta(String _cor, boolean _aberta, double _dimensaoX, double _dimensaoY, double _dimensaoZ) {
        this.cor = _cor;
        this.aberta = _aberta;
        this.dimensaoX = _dimensaoX;
        this.dimensaoY = _dimensaoY;
        this.dimensaoZ = _dimensaoZ;
    }

    public void abre() {
        this.aberta = true;
    }
    public void fecha(){
        this.aberta = false;
    }

    public void pinta(String cor){
        this.cor = cor;
    }

    public boolean estaAberta() {
        return this.aberta;
    }
}