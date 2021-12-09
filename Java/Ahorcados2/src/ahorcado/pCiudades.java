package ahorcado;
/**
 * Archivo: Palabras.java
 * @author BelloCerecero
 * @since 14-03-2013
 */

public class pCiudades
{
    private String[] arreglo;
    private String elegida;
    private String[] palabraFormada;
    private int bandera;
    
    
    public pCiudades()
    {
        arreglo = new String[10];
        arreglo[0] = "tokio";
        arreglo[1] = "osaka";
        arreglo[2] = "ecatepec";
        arreglo[3] = "guadalajara";
        arreglo[4] = "leon";
        arreglo[5] = "zapopan";
        arreglo[6] = "hermosillo";
        arreglo[7] = "monterrey";
        arreglo[8] = "cancun";
        arreglo[9] = "merida";
        elegida = escogerPalabra();
        palabraFormada = new String[elegida.length()];
        llenarPalabraFormada();
        bandera = 0;
    }
    
    public String escogerPalabra()
    {
        int aleatorio=(int)((Math.random()*10));
        return arreglo[aleatorio];
        
    }
    
    public void llenarPalabraFormada()
    {
        for(int i = 0; i < palabraFormada.length; i++)
        {
            palabraFormada[i] = "*";
        }
    }
    
    public String comparar(char letra)
    {
        System.out.println(elegida);
        String aux="";
        String nuevaPalabra ="";
        int contador = 0;
        bandera =0;
        
        while(contador < elegida.length())
        {
            if((letra == elegida.charAt(contador)) && (palabraFormada[contador].equals("*")))
            {
                aux += letra;
                palabraFormada[contador] = aux;
                aux="";
                contador++;
                bandera=1;
            }
            else
            {
                contador++;
            }
            
        }
        
        for(int i = 0; i < palabraFormada.length;i++)
        {
            nuevaPalabra += palabraFormada[i];
            
        }
        return nuevaPalabra;
    }
    
    public String getElegida()
    {
        return elegida;
    }
    
    public int getBandera()
    {
        return bandera;
    }
    
//    public static void main(String[] args)
//    {
//        
//        Palabras p = new Palabras();
//        System.out.println(p.comparar('a'));
//        System.out.println(p.comparar('b'));
//        System.out.println(p.comparar('c'));
//        System.out.println(p.comparar('d'));
//        System.out.println(p.comparar('e'));
//        System.out.println(p.comparar('l'));
//        System.out.println(p.comparar('f'));
//        System.out.println(p.comparar('n'));
//        System.out.println(p.comparar('t'));
//    }
}
