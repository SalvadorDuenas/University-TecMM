package PolymonialRegression;

public class DataSet3 {
private int n;
    private double[] x, y;
    
    //Constructor
    public DataSet3(){
        this.x = new double[]{0,20,40,60,80,100};
        this.y = new double[]{0.0002,0.0012,0.0060,0.0300,0.0900,0.2700};
        this.n = x.length;
    }
    
    //Setters y Getters de variables
    public int getN() { return n;   }
    
    public double[] getX(){ return this.x;   }
    public void setX(double[] aux){ this.x = aux;   }
    
    public double[] getY(){ return this.y;   }
    public void setY(double[] aux){ this.y = aux;   }
}
