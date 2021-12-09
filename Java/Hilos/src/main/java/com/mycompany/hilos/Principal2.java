package com.mycompany.hilos;

public class Principal2 {

    public static void main(String[] args) {
        //Ejemplo1 interfaz
        (new Thread(new HelloRunnable())).start();
        
        //Ejemplo herencia
        (new HelloThread()).start();
        
        
        //Thread 1 del ejemplo 3
        RunnableDemo R1 = new RunnableDemo(  "Thread-1"); 
        R1.start(); 
  
        //Thread 2 del ejemplo 3
        RunnableDemo R2 = new RunnableDemo(  "Thread-2"); 
        R2.start(); 
        
    }
}