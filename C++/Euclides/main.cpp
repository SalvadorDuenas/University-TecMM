#include <cmath>
#include <iostream>
using namespace std;

int Euclides_Iter (int X, int Z)
{
    int Resta=1, tem;
    if (X>Z)
    {
        tem = X;
        X = Z;
        Z = tem;
    }
    while (X>=Z)
    {
        if (Z==0)
        {
            return X;
        }
        else
        {
            while (Resta != 0)
            {
                Resta = X%Z;
                X = Z;
                Z = Resta;
            }
            return (X);
        }
    }
}

void MenuPrincipal()
{
    int Opcion, Numero, Mayor;

    do
    {
        system("cls");
        printf("Bienvenido\n1)Euclides Iterativo\n0)Salir\n");
        scanf("%i",&Opcion);

        switch (Opcion)
        {
        case 1:
            printf("Escriba un numero: ");
            scanf("%i", &Mayor);
            printf("Escriba un numero: ");
            scanf("%i", &Numero);
            printf("El Maximo Comun Divisor entre %i y %i es igual a : %i \n", Mayor, Numero, Euclides_Iter(Mayor, Numero));
            system("pause");
            break;
        }

    }
    while(Opcion!=0);

}

int main()
{
    MenuPrincipal();
    return 0;
}
