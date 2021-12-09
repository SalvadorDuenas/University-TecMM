
package com.mycompany.hilos;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Hilos {
    
    public static void  main(String[] args){
        
        Hilo1 hilo1= new Hilo1();
        Hilo2 hilo2= new Hilo2();
        hilo1.start();
        try {
            hilo1.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Hilos.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        hilo2.start();
        try {
            hilo2.join();
        } catch (InterruptedException ex) {
            Logger.getLogger(Hilos.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Tareas Terminadas");
    }
    
}

class Hilo1 extends Thread{
    public void run(){
           System.out.println("Minusculas");
        for(char car='A';car <='z';car++){
            System.out.println(car);
            
            try {
                Thread.sleep(400);
            } catch (InterruptedException ex) {
                Logger.getLogger(Hilo1.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }
}
    
class Hilo2 extends Thread{
    public void run(){
        System.out.println("Mayusculas");
        for(char car='A';car <='Z';car++){
            System.out.println(car);
            
            try {
                Thread.sleep(400);
            } catch (InterruptedException ex) {
                Logger.getLogger(Hilo1.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

    }
    
}
