
package PolymonialRegression;

public class DataSet {
private int n;
    private double[] x, y;
    
    //Constructor
    public DataSet(){
        this.x = new double[]{1,2,3.5,4,5.5,6,6.5,8,8.5,10};
        this.y = new double[]{5.8,9,13,15,16.5,17.5,18,19,19.5,20};
        this.n = x.length;
    }
    
    //Setters y Getters de variables
    public int getN() { return n;   }
    
    public double[] getX(){ return this.x;   }
    public void setX(double[] aux){ this.x = aux;   }
    
    public double[] getY(){ return this.y;   }
    public void setY(double[] aux){ this.y = aux;   }
}
