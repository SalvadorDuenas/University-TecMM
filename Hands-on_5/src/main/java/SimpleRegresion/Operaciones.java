package SimpleRegresion;

import java.util.Scanner;
//SE DEFINES
public class Operaciones implements Interfaz {

   
    private double[] x;
    private double[] y;

    public Operaciones() {

    
        this.x = new double[9];
        this.y = new double[9];

    }



    public void Inicio() {
        y[0]=651; y[1]=762; y[2]=856; y[3]=1063; y[4]=1190; y[5]=1298; y[6]=1421; y[7]=1440; y[8]=1518;
        x[0]=23; x[1]=26; x[2]=30; x[3]=34; x[4]=43; x[5]=48; x[6]=52; x[7]=57; x[8]=58;
    }

    @Override
    public void Operandos() {
        Scanner sc = new Scanner(System.in);
        double[] xy = new double[9];
        double[] x2 = new double[9];
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

        for (int i = 0; i < 9; i++) {
            xy[i] = (y[i] * x[i]);
            x2[i] = (x[i] * x[i]);
            Sumxi += x[i];
            Sumyi += y[i];
            Sumxy += xy[i];
            Sumx2 += x2[i];
        }
        
        Promy = Sumyi / 9;
        Promx = Sumxi / 9;

        Beta1 = (((9 * Sumxy) - (Sumxi * Sumyi)) / ((9 * Sumx2) - (Sumxi * Sumxi)));
        Beta0 = (Promy - (Beta1 * Promx));
        
        System.out.println("Beta 1 es igual a:"+ Beta1 +"\n");
        System.out.println("Beta 0 es igual a:"+ Beta0 +"\n");
        
        System.out.println("Favor de ingresar un valor de X a calcular");
        f=sc.nextDouble();
        resultado=((Beta1*f)+Beta0);
        System.out.println("\nEl valor de Y en relacion a X es :"+resultado+"\n"); 
    }

}