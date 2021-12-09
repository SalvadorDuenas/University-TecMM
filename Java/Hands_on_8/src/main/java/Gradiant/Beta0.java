
package Gradiant;

public class Beta0 {
    public double Be0(int n,int x[],int y[],double b0,double b1){
    double beta0 = 0;
    for(int i=0;i<n;i++){
        beta0+=(y[i]-(b0+(b1*x[i])));
    }
    beta0= (-2*beta0)/n;
       return beta0; 
} 
}
