
package PolymonialRegression;

import java.util.Scanner;

public class Metodos {
    
Aritmetica arit = new Aritmetica();
    DataSet data = new DataSet();
    Betas c = new Betas();
    Scanner sc = new Scanner(System.in);
    float x=0;
    public Metodos() {}
    
    public void Metodo() {
        
        double sumax = 0, sumay = 0, sumaxy = 0, sumax2 = 0, sumax3 = 0, sumax4 = 0, sumax2y = 0;
        int n = data.getN();
        
        sumax = arit.sumatoria(data.getX());
        sumax2 = arit.sumatoria(data.getX(), 2);
        sumax3 = arit.sumatoria(data.getX(), 3);
        sumax4 = arit.sumatoria(data.getX(), 4);
        sumay = arit.sumatoria(data.getY());
        sumaxy = arit.sumatoria(data.getX(), data.getY());
        sumax2y = arit.sumatoria(data.getX(), 2, data.getY());
        
        double Ds = (n*sumax2*sumax4)+(sumax*sumax3*sumax2)+(sumax2*sumax*sumax3)-(sumax*sumax*sumax4)-(n*sumax3*sumax3)-(sumax2*sumax2*sumax2);
        double Db0 = (sumay*sumax2*sumax4)+(sumax*sumax3*sumax2y)+(sumaxy*sumax3*sumax2)-(sumax2*sumax2*sumax2y)-(sumax3*sumax3*sumay)-(sumaxy*sumax*sumax4);
        double Db1 = (n*sumaxy*sumax4)+(sumay*sumax3*sumax2)+(sumax*sumax2y*sumax2)-(sumax2*sumaxy*sumax2)-(sumax3*sumax2y*n)-(sumax*sumay*sumax4);
        double Db2 = (n*sumax2*sumax2y)+(sumax*sumaxy*sumax2)+(sumax*sumax3*sumay)-(sumay*sumax2*sumax2)-(sumaxy*sumax3*n)-(sumax*sumax*sumax2y);
        
        c.setBeta0(Db0 / Ds);
        c.setBeta1(Db1 / Ds);
        c.setBeta2(Db2 / Ds);
        
        System.out.println("f(x) = " + c.getBeta0() + " + " + c.getBeta1() + "x " + c.getBeta2() + " x^2"); 
        
    }
}
