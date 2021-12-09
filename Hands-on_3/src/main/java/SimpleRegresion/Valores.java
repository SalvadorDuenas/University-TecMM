package SimpleRegresion;
import java.util.Scanner;

public class Valores {
    
    public static void main(String args[]) {
        
    Scanner sc = new Scanner(System.in);
    System.out.println("Ingrese numero de valores");
    
    int n = sc.nextInt();
    
    Operaciones o = new Operaciones(n);
    
    o.Inicio();
    o.Operandos();
    }
}