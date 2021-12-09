package SimpleRegresion;

import java.text.DecimalFormat;
import java.util.Scanner;
//SE DEFINES
public class Operaciones implements Interfaz {

    private int n;
    private double[] x;
    private double[] y;

    public Operaciones(int n) {

        this.n = n;
        this.x = new double[n];
        this.y = new double[n];

    }

    public int getN() {
        return n;
    }

    public void Inicio() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese los " + n + " valores de Yi \nde forma ordenada");
        for (int i = 0; i < n; i++) {
            y[i] = sc.nextDouble();
        }
        System.out.println("\n");

        System.out.println("Ingrese los " + n + " valores de Xi \nde forma ordenada");
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
        }
        System.out.println("\n");

    }

    @Override
    public void Operandos() {
        Scanner sc = new Scanner(System.in);
        double[] xy = new double[n];
        double[] x2 = new double[n];
        double Sumxi = 0.0;
        double Sumyi = 0.0;
        double Sumxy = 0.0;
        double Sumx2 = 0.0;
        double Promy = 0.0;
        double Promx = 0.0;
        double Beta0;
        double Beta1;
        double resultado;
        double f;

        for (int i = 0; i < n; i++) {
            xy[i] = (y[i] * x[i]);
            x2[i] = (x[i] * x[i]);
            Sumxi += x[i];
            Sumyi += y[i];
            Sumxy += xy[i];
            Sumx2 += x2[i];
        }
        
        Promy = Sumyi / n;
        Promx = Sumxi / n;

        Beta1 = (((n * Sumxy) - (Sumxi * Sumyi)) / ((n * Sumx2) - (Sumxi * Sumxi)));
        Beta0 = (Promy - (Beta1 * Promx));
        
        System.out.println("Beta 1 es igual a:"+ Beta1 +"\n");
        System.out.println("Beta 0 es igual a:"+ Beta0 +"\n");
        
        System.out.println("Favor de ingresar un valor de X a calcular");
        f=sc.nextDouble();
        resultado=((Beta1*f)+Beta0);
        System.out.println("\nEl valor de Y en relacion a X es :"+resultado+"\n"); 
    }

}