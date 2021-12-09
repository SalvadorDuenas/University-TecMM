/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package PolymonialRegression;
import jade.core.Agent;
import jade.core.behaviours.OneShotBehaviour;

public class PolymonialRegression extends Agent{
   
    @Override
    protected void setup(){
        System.out.println("Inicio del agente " + getLocalName());
        addBehaviour(new MyOneShotBehaviour());
    }
    
    private class MyOneShotBehaviour extends OneShotBehaviour {

    @Override
    public void action() {
        System.out.println("-Agente en accion-");
        Metodos res = new Metodos();
        res.Metodo();
    } 
    
    @Override
    public int onEnd() {
      System.out.println("-Agente muriendo-");
      myAgent.doDelete();   
      return super.onEnd();
    } 
  } 
    
}
