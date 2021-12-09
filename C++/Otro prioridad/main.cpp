#include <iostream>

#include "PRIORITY/Priority.hpp"


Priority::Priority(int Capacity)
{
    n = Capacity;
    s = 0;

    start = nullptr;
}

Priority::~Priority()
{

}

//Insercion de datos(se organizan conforme vayan entrando)
bool Priority::ins(const char TheID, int TheTime, int ThePriority)
{
    if(full())
    {
        printf("INS DENIED: ");
        return false;
    }

    if(empty())
    {
        start = new Node(TheID, TheTime, ThePriority);
    }
    else
    {

        Node *p = start;
        Node *q = nullptr;

        while( p != nullptr && p -> priority() > ThePriority)
        {

            q = p;
            p = p -> next();

        }
        if( p != nullptr && p -> id() == TheID )
        {
            printf("Dato ya existente\n");
            return false;
        }

        Node *aux = new Node(TheID, TheTime, ThePriority);

        if( p == nullptr)
        {
            q -> next(aux);
        }
        else if(p == start)
        {
            aux -> next(start);
            start = aux;
        }
        else
        {
            q -> next(aux);
            aux -> next(p);
        }
    }
    s++;
    return true;
}

void Priority::Algorithm()
{

    float tr = 0;
    float trp = 0;
    float resultado = 0;

    float quantum = 0;

    Node *p = start;
    Node *q = start;

    //ciclo para obtener el quantum
    while( p != nullptr )
    {
        quantum += p -> time();
        p = p -> next();
    }
    quantum = (quantum) / (n);

    p = start;

//ciclo del algoritmo
    while( q != nullptr)
    {

        //ciclo de impresion
        while( p != nullptr )
        {
            cout << "[" << p -> id() << "]<--";
            p = p -> next();
        }
        printf("\n");

        if( q -> time() > quantum)
        {

            tr += quantum;

            float t = q -> time() - quantum;

            int pr = q -> priority();
            pr = pr - 1;

            Node *aux = new Node( q -> id(), t, pr);

            Node *i = start;
            Node *j = nullptr;
            //ciclo de reubicacion
            while( i != nullptr && i -> priority() >= pr )
            {
                j = i;
                i = i -> next();
            }
            if( i == nullptr)
            {
                j -> next(aux);
            }
            j -> next(aux);
            aux -> next(i);

            q = q -> next();
            p = q;
            printf("\n");

        }
        else if( q -> time() == quantum )
        {

            tr += quantum;
            trp += tr;

            cout << "TR" << q -> id() << " = " << tr;
            printf("\n");

            q = q -> next();
            p = q;

        }
        else
        {

            tr += q -> time();
            trp += tr;

            cout << "TR" << q -> id() << " = " << tr;
            printf("\n");

            q = q -> next();
            p = q;
        }
    }
    resultado = (trp) / (n);
    printf("TRPromedio = %f\n", resultado);
}

int main()
{

    char id[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
                };
    int time;
    int priority;
    //Node *p;

    int n;

//introduccion de #procesos
    cout << "Introduzca el numero de procesos: ";
    cin >> n;
    printf("\n");

//Construccion
    Fifo fifo(n);
    Sjf sjf(n);
    Round rr(n);
    Priority prio(n);

//Insercion de datos
    for(int i = 0; i < n; i++)
    {

        cout << "Introduzca el Tiempo del proceso " << id[i]  << ": ";
        cin >> time;
        printf("\n");

        cout << "Introduzca la Prioridad del proceso " << id[i]  << ": ";
        cin >> priority;
        printf("\n");

        fifo.ins(id[i],time,priority);
        sjf.ins(id[i],time,priority);
        rr.ins(id[i],time,priority);
        prio.ins(id[i],time,priority);
    }

    int opcion;
    do
    {
        cout <<"\n Algoritmo a elegir\n";
        cout <<" 1:FIFO\n 2:SJF\n 3:R-R\n 4:PRIORIDAD\n 0:Salir\n";
        cin >> opcion;

        if( opcion == 1)
        {

            fifo.Algorithm(n);
            printf("\n\n");

        }
        else if( opcion == 2)
        {

            sjf.Algorithm(n);
            printf("\n\n");

        }
        else if( opcion == 3)
        {

            rr.Algorithm();
            printf("\n\n");

        }
        else if( opcion == 4)
        {

            prio.Algorithm();
            printf("\n\n");

        }
    }
    while( opcion != 0 );
    return 0;
}

