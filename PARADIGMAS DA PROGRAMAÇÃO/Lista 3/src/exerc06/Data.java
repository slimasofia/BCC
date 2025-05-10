package exerc06;
public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int _dia, int _mes, int _ano) {
        this.dia = _dia;
        this.mes = _mes;
        this.ano = _ano;
    }

    int[] diasMes = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    public boolean dataValida() {
        if (mes < 1 || mes > 12 || dia < 1 || ano < 1) {
            return false;
        } else if (mes == 2 && anoBissexto() && dia <= 29) {
            return true;
        } else if (dia > diasMes[mes]) {
            return false;
        }
        return true;
    }

    private boolean anoBissexto() {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            return true;
        } else {
            return false;
        }
    }

    public void imprimirData() {
        if (!dataValida()) {
            System.out.println("Data inválida");
        } else {
            System.out.println(dia + "/" + mes + "/" + ano);
        }
    }

    public void proximoDia() {
        if (dataValida()) {
            dia += 1;

            if ((mes == 2 && dia > 28 && !anoBissexto()) || (mes == 2 && dia > 29 && anoBissexto()) || (dia > diasMes[mes])) {
                dia = 1;
                mes += 1;

                if (mes > 12) {
                    mes = 1;
                    ano += 1;
                }
            }
            imprimirData();
        }
    }
}