package ahorcado;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * Archivo: Ahorcado.java
 * @author BelloCerecero
 * @since 13-03-2013
 * @version 1.0
 */
public class Ahorcado extends JFrame implements ActionListener
{
    private Pintar panelGrafico;
    private JPanel panelComponentes;
    private JButton botonReIniciar;
    private JButton botonValidarLetra;
    private JButton botonSalir;
    private JLabel etiqueta;
    private JTextField letra;
    private JTextField palabra;
    private Palabras p;
    private pVegetales v;
    private pCiudades ci;
    private pColores col;
    private int vidas;
    
    private JButton Animales;
    private JButton Vegetales;
    private JButton Ciudades;
    private JButton Colores;
    
    public Ahorcado()
    {
        super("Juego del ahorcado version 1.0");
        setLayout(new BorderLayout(1,1));
        setSize(600,600);
        agregarElementos();
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
        vidas = 0;
    }
    
    public void agregarElementos()
    {
        //Panel donde se dibujara 
        panelGrafico = new Pintar();
        panelGrafico.setBackground(Color.WHITE);
        add(panelGrafico,BorderLayout.CENTER);
        
        //Panel donde estaran los elementos
        panelComponentes = new JPanel();
        panelComponentes.setBackground(Color.BLUE);
        panelComponentes.setLayout(null);
        
        botonReIniciar = new JButton("Reinicar Juego");
        Animales = new JButton("Animales");
        Ciudades = new JButton("Ciudades");
        Vegetales = new JButton("Vegetales");
        Colores = new JButton("Colores");
        botonValidarLetra = new JButton("Validar Letra");
        botonSalir = new JButton("SALIR");
        
        etiqueta = new JLabel("Palabra");
        
        palabra = new JTextField("");
        letra = new JTextField("");
        
        //Colocando elementos en el panel
        botonReIniciar.setBounds(30,350,150,30);
        etiqueta.setBounds(250,400,100,30);
        palabra.setBounds(300,400,150,30);
         Animales.setBounds(30, 470, 150, 30);
        Vegetales.setBounds(30, 440, 150, 30);
        Colores.setBounds(30, 410, 150, 30);
        Ciudades.setBounds(30, 380, 150, 30);
        botonValidarLetra.setBounds(30,500,150,30);
        letra.setBounds(200,500,50,30);
        botonSalir.setBounds(430,500,150,30);
        
        botonReIniciar.addActionListener(this);
        Animales.addActionListener(this);
        Vegetales.addActionListener(this);
        Colores.addActionListener(this);
        Ciudades.addActionListener(this);
        botonValidarLetra.addActionListener(this);
        botonSalir.addActionListener(this);
        
        panelComponentes.add(botonReIniciar);
        panelComponentes.add(Animales);
        panelComponentes.add(Vegetales);
        panelComponentes.add(Ciudades);
        panelComponentes.add(Colores);
        panelComponentes.add(botonValidarLetra);
        panelComponentes.add(botonSalir);
        panelComponentes.add(letra);
        panelComponentes.add(etiqueta);
        panelComponentes.add(palabra);
        
        add(panelComponentes,BorderLayout.CENTER);
        
        
    }
    

    public void actionPerformed(ActionEvent evento) 
    {
        if(evento.getSource() == botonReIniciar)
        {
            panelGrafico.error(0);
            palabra.setText("");
            letra.setText("");
            vidas = 0;
        }
        else if(evento.getSource() == Animales)
        {
            panelGrafico.error(1);
            p = new Palabras();
            String aux="";
            int contador =0;
            while(contador < p.getElegida().length())
            {
                aux+="*";
                contador++;
            }
            palabra.setText(aux);
        }
        
        
        else if(evento.getSource() == Vegetales)
        {
            panelGrafico.error(1);
            v = new pVegetales();
            String aux="";
            int contador =0;
            while(contador < v.getElegida().length())
            {
                aux+="*";
                contador++;
            }
            palabra.setText(aux);
        }
        
        else if(evento.getSource() == Ciudades)
        {
            panelGrafico.error(1);
            v = new pVegetales();
            String aux="";
            int contador =0;
            while(contador < v.getElegida().length())
            {
                aux+="*";
                contador++;
            }
            palabra.setText(aux);
        }
        
        
        else if(evento.getSource() == Colores)
        {
            panelGrafico.error(1);
            v = new pVegetales();
            String aux="";
            int contador =0;
            while(contador < v.getElegida().length())
            {
                aux+="*";
                contador++;
            }
            palabra.setText(aux);
        }
        
        
        
        else if(evento.getSource() == botonValidarLetra)
        {
            String l="";
            l = letra.getText();
            char c = l.charAt(0);
            
            while(p.comparar(c).equals(p.getElegida()))
            {
                palabra.setText(p.comparar(c));
                JOptionPane.showMessageDialog(null,"Ganaste");
            }
            if(vidas == 5)
            {
                JOptionPane.showMessageDialog(null,"Has perdido");
            }
            else if(p.getBandera() == 1)
            {
                palabra.setText(p.comparar(c));
            }
            else if(p.getBandera() == 0)
            {
                vidas = vidas + 1;
                panelGrafico.error(vidas);
            }  
            
            
            while(ci.comparar(c).equals(ci.getElegida()))
            {
                palabra.setText(ci.comparar(c));
                JOptionPane.showMessageDialog(null,"Ganaste");
            }
            if(vidas == 5)
            {
                JOptionPane.showMessageDialog(null,"Has perdido");
            }
            else if(ci.getBandera() == 1)
            {
                palabra.setText(ci.comparar(c));
            }
            else if(ci.getBandera() == 0)
            {
                vidas = vidas + 1;
                panelGrafico.error(vidas);
            }
            
            
            while(v.comparar(c).equals(v.getElegida()))
            {
                palabra.setText(v.comparar(c));
                JOptionPane.showMessageDialog(null,"Ganaste");
            }
            if(vidas == 5)
            {
                JOptionPane.showMessageDialog(null,"Has perdido");
            }
            else if(v.getBandera() == 1)
            {
                palabra.setText(v.comparar(c));
            }
            else if(v.getBandera() == 0)
            {
                vidas = vidas + 1;
                panelGrafico.error(vidas);
            }
            
            
            while(col.comparar(c).equals(col.getElegida()))
            {
                palabra.setText(col.comparar(c));
                JOptionPane.showMessageDialog(null,"Ganaste");
            }
            if(vidas == 5)
            {
                JOptionPane.showMessageDialog(null,"Has perdido");
            }
            else if(col.getBandera() == 1)
            {
                palabra.setText(col.comparar(c));
            }
            else if(col.getBandera() == 0)
            {
                vidas = vidas + 1;
                panelGrafico.error(vidas);
            }
            
            
        }
        else if(evento.getSource() == botonSalir)
        {
            System.exit(0);
        }
    }
    
    
    public static void main(String[] args) 
    {
        Ahorcado a = new Ahorcado();
    }

}