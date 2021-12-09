package PolymonialRegression;

public class DataSet2 {
private int n;
    private double[] x, y;
    
    //Constructor
    public DataSet2(){
        this.x = new double[]{50,50,50,70,70,70,80,80,80,90,90,90,100,100,100};
        this.y = new double[]{3.3,2.8,2.9,2.3,2.6,2.1,2.5,2.9,2.4,3.0,3.1,2.8,3.3,3.5,3.0};
        this.n = x.length;
    }
    
    //Setters y Getters de variables
    public int getN() { return n;   }
    
    public double[] getX(){ return this.x;   }
    public void setX(double[] aux){ this.x = aux;   }
    
    public double[] getY(){ return this.y;   }
    public void setY(double[] aux){ this.y = aux;   }
}
