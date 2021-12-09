#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void iterativo()
{
    float m,anual;
    int anos;
    printf("Ingrese el monto total a recibir\n");
    cin>>m;
    printf("Ingrese el interes anual\n");
    cin>>anual;
    printf("Cantidad de años a evaluar\n");
    cin>>anos;

    anual=anual/100;
    float interes;
    float total=m;
    for(int i=anos; i>0; i--)
    {

        interes=total*anual;

        total=total+interes;

        cout<<"\nEl monto actual es: "<<total<<endl;
    }
    cout<<"\n";
}

float Recursivo(int anos,float m,float anual)
{


    if (anos==0)
    {
        return (m);
    }
    else

        return((1+(anual/100))*Recursivo((anos-1), m, anual) );


}

int main()
{
    int opcion;
    do
    {
        system("cls");
        int anos;
        float m,anual;
        printf("\nBienvenido\nQue desea hacer?\n\n1)Iterativo\n\n2)Recursivo\n\n0)Salir\n\n");
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 0:
            printf("\nGracias por su visita, excelente dia\n");
            break;
        case 1:
            iterativo();
            system("pause");
            break;
        case 2:
            printf("Ingrese el monto total a recibir\n");
            cin>>m;
            printf("Ingrese el interes anual en decimal\n");
            cin>>anual;
            printf("Cantidad de años a evaluar\n");
            cin>>anos;
            cout<<Recursivo(anos,m,anual)<<endl;
            system("pause");
            break;
        default:
            cout<<"\nFavor de ingresar una opcion valida\n\n";
            system("pause");
            break;
        }
    }
    while(opcion!=0);
}
