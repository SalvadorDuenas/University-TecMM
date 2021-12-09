#include <iostream>
using namespace std;

void Maxima_Capacidad(int a[], int i, int n)
{
    //definimos la variables
    int l,r,largo,loc;
    //Se pone por los nodos que se estan definiendo
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
        largo=l;
    else
        largo=i;
    //aqui comparamos cada nodo
    if((r<=n)&&(a[r]>a[largo]))
        largo=r;
    if(largo!=i)
    {
        loc=a[i];
        a[i]=a[largo];
        a[largo]=loc;
        Maxima_Capacidad(a,largo,n);
    }
}

    //esta define la construccion del nodo con un for
    //de ahi el divido entre 2 para que se creen las divisiones de los nodos
void Construccion(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        Maxima_Capacidad(a, k, n);
    }
}

    //por ultimo definimos la operacion que va realizar creando el arbol y comparandolo
    //entre sus ramas para ir desaciendo los nodos que se van generando
void HEAPSORT(int a[], int n)
{
    Construccion(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        Maxima_Capacidad(a, 1, i -1);
    }
}

int main()
{
    int n;
    printf("Introducir el tamaño de la serie:\n");
    scanf("%i",&n);
    int a[n];
    printf("Introducir los elementos de la serie \n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%i",&a[i]);
    }
    HEAPSORT(a, n);
    cout<<":-:FORMA CLASIFICADA:-:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<a[i]<<endl;
    }
}
