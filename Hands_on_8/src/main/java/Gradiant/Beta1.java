
package Gradiant;

public class Beta1 {
   public double Be1(int n,int x[],int y[],double b0,double b1){
    double beta1=0;
    for(int i=0;i<n;i++){
        beta1+=(x[i]*(y[i]-(b0+(b1*x[i]))));
    }
    beta1= (-2*beta1)/n;
       return beta1; 
}
    
}
