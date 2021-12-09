package SimpleRegresion;


import java.util.Scanner;

import jade.core.Agent;
import jade.core.behaviours.OneShotBehaviour;

public class Valores extends Agent {

    @Override
    protected void setup() {
        System.out.println("Inica el agente " + getLocalName());
        addBehaviour(new MyOneShotBehaviour());
    }

    private class MyOneShotBehaviour extends OneShotBehaviour {
            
        @Override
        public void action(){
            System.out.println("-Agente activado-");
            Operaciones o = new Operaciones();
            o.Operandos();
        }
        @Override
        public int onEnd(){
             System.out.println("-Agente muriendo-");
             myAgent.doDelete();
             return super.onEnd();
        }

    }

}
