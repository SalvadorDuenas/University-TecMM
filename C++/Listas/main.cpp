#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int TipoDato;

//Estructura o registro
struct nodo
{
    TipoDato Info;
    struct nodo *Liga;
};

// Definir alias tipo Lista
typedef struct nodo *Lista;

void InicializarLista (Lista &P)
{
    P=NULL;
}

bool ListaVacia (Lista P)
{
    if (P==NULL)
        return true;
    else
        return false;
}
/*
void CrearInicio(Lista &P) {
	Lista Q;
	int RES;

	//Se crea o asigna espacio a la variable P
	P= new nodo;
	//Se inserta el campo info en P
	cout<< "Escriba un dato: ";
	cin>> P->Info;
	P->Liga=NULL;

	//Se pregunta si se dessea agregar mas nodos a P
	cout<< "Desea inresar mas nodos a la lista? Si:1, No:0";
	cin>> RES;

	while (RES==1) {
		//Crea o asigna espacio a Q
		Q= new nodo;
		cout<<"Escriba un dato: ";
		cin>> Q->Info;
		Q->Liga=P;
		P=Q;

		cout << "Desea inresar mas nodos a la lista? Si:1, No:0	";
		cin >> RES;
	}

}*/

void CrearFinal(Lista &P)
{
    Lista Q, T;
    int RES;

    //Se crea o asigna espacio a la variable P
    P= new nodo;
    //Se inserta el campo info en P
    cout<< "Escriba un dato: ";
    cin>> P->Info;
    P->Liga=NULL;
    T=P;

    //Se pregunta si se dessea agregar mas nodos a P
    cout<< "Desea inresar mas nodos a la lista? Si:1, No:0";
    cin>> RES;

    while (RES==1)
    {
        //Crea o asigna espacio a Q
        Q= new nodo;
        cout<<"Escriba un dato: ";
        cin>> Q->Info;
        Q->Liga=NULL;
        T->Liga=Q;
        T=Q;

        cout << "Desea inresar mas nodos a la lista? Si:1, No:0	\t";
        cin >> RES;
    }

}

void RecorrerLista(Lista P)
{
    Lista Q;
    int Nodo=1;
    Q= P;

    while(Q!=NULL)
    {
        cout << "Nodo_"<<Nodo<<": "<<Q->Info<<endl;
        Q=Q->Liga;
        Nodo ++;
    }

}

void InsertarInicio (Lista &P, TipoDato Dato)
{
    Lista Q;
    Q= new nodo;
    Q->Info= Dato;
    Q->Liga= P;
    P= Q;
}

void InsertarFinal (Lista &P, TipoDato Dato)
{
    Lista Q, T;
    if (ListaVacia(P) != true)
    {
        T= P;
        while (T->Liga != NULL)
            T= T->Liga;

        Q= new nodo;
        Q->Info= Dato;
        Q->Liga= NULL;
        T->Liga= Q;
    }
    else
    {
        printf("La lista está vacía");
        system("pause");
    }

}
/*
void InsertarAntesX(Lista &P, TipoDato Dato, TipoDato Ref ) {
	Lista Q, X, T;
	int Band;

	if (ListaVacia(P) != true) {
		Q= P;	//Q comienza la busqueda de Ref desde P
		Band= 1;

		while ( (Q->Info != Ref) && (Band == 1) )
			if (Q->Liga != NULL) {
				T= Q;
				Q= Q->Liga;
			} else
				Band = 0;
		//Se encontro la ref
		if (Band==1) {
			X= new nodo;
			X->Info= Dato;
			//La ref esta en el primer nodo
			if (P==Q) {
				X->Liga= P;
				P= X;
			} else {
				T->Liga= X;
				X->Liga= Q;
			}
		} else {
			printf("La referencia no fue encontrada");
			system("pause");
		}

	} else {
		printf("La lista esta vacia");
		system("pause");
	}
}*/

void InsertarDespuesX(Lista &P, TipoDato Dato, TipoDato Ref )
{
    Lista Q, X, T;
    int Band;

    if (ListaVacia(P) != true)
    {
        Q= P;	//Q comienza la busqueda de Ref desde P
        Band= 1;

        while ( (Q->Info != Ref) && (Band == 1) )
            if (Q->Liga != NULL)
            {
                Q= Q->Liga;
            }
            else
                Band = 0;
        //Se encontro la ref
        if (Band==1)
        {
            X= new nodo;
            X->Info= Dato;
            //La ref esta en el primer nodo
            X->Liga= Q->Liga;
            Q->Liga= X;

        }
        else
        {
            printf("La referencia no fue encontrada");
            system("pause");
        }

    }
    else
    {
        printf("La lista esta vacia");
        system("pause");
    }
}

void Impresion()

int main()
{
    Lista P;
    //CrearInicio(P);

    //CrearFinal(P);

    InicializarLista(P);
    InsertarInicio(P, 8);
    InsertarFinal(P, 7);
    InsertarFinal(P, 3);
    InsertarFinal(P, 11);

    RecorrerLista(P);

    system("pause");

    //InsertarAntesX(P, 22, 3);
    InsertarDespuesX(P, 22, 7);

    RecorrerLista(P);
    system("pause");

    return 1;
}
