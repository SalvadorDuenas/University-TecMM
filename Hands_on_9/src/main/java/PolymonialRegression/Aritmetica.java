
package PolymonialRegression;

public class Aritmetica {
    
    public double sumatoria(double[] aux){
        double suma = 0;
        int n = aux.length;
        
        for(int i = 0; i < n; i++){ 
            suma += aux[i];
        }
        return suma;
    }
    
    public double sumatoria(double[] aux, int potencia){
        double suma = 0;
        int n = aux.length;
        
        for(int i = 0; i < n; i++){ 
            suma += Math.pow(aux[i],potencia);
        }
        return suma;
    }
    
    public double sumatoria(double[] aux, double[] aux2){
        double suma = 0;
        int n = aux.length;
        
        for(int i = 0; i < n; i++){ 
            suma += (aux[i] * aux2[i]);
        }
        return suma;
    }
    
    public double sumatoria(double[] aux, int potencia ,double[] aux2){
        double suma = 0;
        int n = aux.length;
        
        for(int i = 0; i < n; i++){ 
            suma += (Math.pow(aux[i],potencia) * aux2[i]);
        }
        return suma;
    }
    
    
}
