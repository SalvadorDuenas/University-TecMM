#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int fact(int N)
{
    if(N==0)
        return(1);
    else
        return(N*fact(N-1));

}

int factIter(int N)
{
    int Res=1;
    for(int i=1; i<=N; i++)
        Res=Res*i;
    return Res;
}

int Fibonacci_Rec(int N)
{
    if ((N==0) || (N==1))
        return N;
    else
        return (Fibonacci_Rec(N-1)+ Fibonacci_Rec(N-2));

}

int Fibonacci_Iter(int N)
{
    int FIBO,FIBA,FIBB,i;
    if ((N==0) || (N==1))
        FIBO=N;
    else
    {
        FIBA=0;
        FIBB=1;
        i=2;
    }
    while(i<=N)
    {
        FIBO=FIBB+FIBA;
        FIBA=FIBB;
        FIBB=FIBO;
        i=i+1;
    }
    return FIBO;
}

int Euclides(int M, int N)
{
    if(N==0)
    {
        return (M);
    }
    else
        return (Euclides(N,M%N));

}

int Euclides_Ite(int M, int N)
{
    int residuo=1;
    while(residuo<=0)
    {
        if (M>N)
        {
            residuo=(M%N);
        }
        else
        {
            residuo=0;
        }
    }
    return residuo;
}

int Ackermann(int M, int N)
{
    if(M==0)
    {
        return (N+1);
    }
    else
    {
        if (N==0)
        {
            return (Ackermann(M-1,1));
        }
        else
        {
            return(Ackermann(M-1,Ackermann(M,N-1)));
        }
    }
}

int Hanoi(int N, int ORIGEN, int DESTINO, int AUXILIAR)
{

    if(N==1)
    {
        printf("Mover un disco de origen ORIGEN a DESTINO\n");
    }
    else
    {
        Hanoi(N-1,ORIGEN,AUXILIAR,DESTINO);
        printf("Mover un disco de ORIGEN a DESTINO\n");
        return(Hanoi(N-1,AUXILIAR,DESTINO,ORIGEN));
    }
}

int Hanoi_ite(int N,int ORIGEN,int DESTINO,int AUXILIAR )
{
    int TOPE(0);
    bool BAND= false;
    int PILAN[N];
    int PILAO[N];
    int PILAD[N];
    int PILAX[N];
    char VARAUX;
    while((N>0) && (BAND==false))
    {
        while(N>1)
        {
            TOPE++;
            PILAN[TOPE]=N;
            PILAO[TOPE]=ORIGEN;
            PILAD[TOPE]=DESTINO;
            PILAX[TOPE]=AUXILIAR;
            N--;
            VARAUX=DESTINO;
            DESTINO=AUXILIAR;
            AUXILIAR=VARAUX;
            printf("Mover un disco de ORIGEN a DESTINO");
            BAND=true;
            if(TOPE>0)
            {
                N=PILAN[TOPE];
                ORIGEN=PILAO[TOPE];
                DESTINO=PILAD[TOPE];
                AUXILIAR=PILAX[TOPE];
                TOPE--;
                printf("Mover un disco de ORIGEN a DESTINO");
                N--;
                VARAUX=ORIGEN;
                ORIGEN=AUXILIAR;
                AUXILIAR=VARAUX;
                BAND=false;

            }
        }
    }
}




void MenuPrincipal()
{
    int Opc,Num1,Num2,Num3,Num4;
    do
    {
        system("cls");
        printf("Algoritmos Recursivos...\n");
        printf("1. Factorial Recursivo de un numero.\n");
        printf("2. Factorial Iterasivo de un numero.\n");
        printf("3. Fibonacci Recursivo de un numero.\n");
        printf("4. Fibonacci Iterasivo de un numero.\n");
        printf("5. Euclides de un numero.\n");
        printf("6. Euclides iterativo de un numero.\n");
        printf("7. Ackermann de un numero.\n");
        printf("8. Hanoi de un numero\n");
        printf("9. Hanoi recursivo de un numero\n");
        printf("10. Salir.\n");

        printf("Opcion: ");
        scanf("%i",&Opc);

        switch(Opc)
        {
        case 1://Factorial Recursivo
            printf("Escribe una numero\n");
            scanf("%i",&Num1);
            printf("El factorial de %i es igual a:  %i  \n", Num1, fact(Num1));
            system("  pause");
            break;
        case 2://Factorial Iterasivo
            printf("Escribe un numero\n");
            scanf("%i",&Num1);
            printf("El factorial de %i es igual a:  %i  \n", Num1, factIter(Num1));
            system("  pause");
            break;
        case 3://Fibonacci
            printf("Escribe un numero\n");
            scanf("%i",&Num1);
            printf("El Fibonacci de %i es igual a:  %i  \n", Num1, Fibonacci_Rec(Num1));
            system("  pause");
            break;
        case 4://Fibonacci Iterasivo
            printf("Escribe un numero\n");
            scanf("%i",&Num1);
            printf("El Fibonacci de %i es igual a:  %i  \n", Num1, Fibonacci_Rec(Num1));
            system("  pause");
            break;
        case 5://Euclides
            printf("Escribe primer numero\n");
            scanf("%i",&Num1);
            printf("Escribe segundo numero\n");
            scanf("%i",&Num2);
            printf("El euclides de %i y %i es igual a : %i \n",Num1,Num2,Euclides(Num1,Num2));
            system("  pause");
            break;
        case 6://Euclides Iterasivo
            printf("Escribe primer numero\n");
            scanf("%i",&Num1);
            printf("Escribe segundo numero\n");
            scanf("%i",&Num2);
            printf("El euclides de %i y %i es igual a : %i \n",Num1,Num2,Euclides_Ite(Num1,Num2));
            system("  pause");
            break;
        case 7://Ackermann
            printf("Escriba M\n");
            scanf("%i",&Num1);
            printf("Escriba N\n");
            scanf("%i",&Num2);
            printf("El ackermann de %i y %i es igual a: %i \n",Num1,Num2,Ackermann(Num1,Num2));
            system("  pause");
            break;
        case 8://Hanoi
            printf("Escribe una numero\n");
            scanf("%i",&Num1);
            printf("El total de movimientos fue de : %.0f \n",pow(2,Num1)-1);
            Hanoi(Num1,Num2,Num3,Num4);
            system("  pause");
            break;
        case 9://Hanoi Iterativo
            printf("Escribe una numero\n");
            scanf("%i",&Num1);
            printf("El total de movimientos fue de : %.0f \n",pow(2,Num1)-1);
            Hanoi(Num1,Num2,Num3,Num4);
            system("  pause");
            break;
        }
    }
    while(Opc<10);
}
int main()
{
    MenuPrincipal();
    return(0);
}
