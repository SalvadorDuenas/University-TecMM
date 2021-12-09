#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Declaración de Constantes
#define MAX 50


typedef int TipoDato;

// Declaración de Pila
struct Pila {
	   int Tope;
	   TipoDato Elementos[ MAX ];
};


typedef struct Pila TipoPila;

// funciones auxiliares de Pila
void IniciarPila( TipoPila &P )
{
  P.Tope= -1;
}

bool PilaVacia( TipoPila P )
{
  if ( P.Tope == -1 )
     return true;
  else
     return false;
}

bool PilaLlena( TipoPila P )
{
  if ( P.Tope == MAX-1 )
     return true;
  else
     return false;
}

typedef int TipoDato;

// Declaración de Cola
struct Cola
{
    int Frente;
    int Final;
    TipoDato Elementos[ MAX ];
};



typedef struct Cola TipoCola;

bool ColaVacia( TipoCola C );
void IniciarCola( TipoCola &C );
bool ColaLlena( TipoCola C );
void InsertarCola( TipoCola &C, TipoDato Dato );
TipoDato EliminarCola( TipoCola &C );
void Ejemplo();
void VerColas(TipoCola C);

// Operaciones auxiliares de Cola
void IniciarCola( TipoCola &C )
{
    C.Frente= -1;
    C.Final= -1;
}

bool ColaVacia( TipoCola C )
{
    if ( C.Frente == -1 && C.Final == -1 )
        return true;
    else
        return false;
}

bool ColaLlena( TipoCola C )
{
    if ( ( C.Frente == 1 && C.Final == MAX-1 ) || ( C.Final == C.Frente-1) )
        return true;
    else
        return false;
}

// Operaciones basicas de Cola
void InsertarCola( TipoCola &C, TipoDato Dato )
{
    if ( ColaLlena(C) == true ) // Esta llena
    {
        printf("Desbordamiento - La Cola esta llena...");
        system("pause");
    }
    else
    {
        if ( ColaVacia(C) == true)	// Esta Vacia - Es el primer elemento a insertar
        {
            C.Frente++;
            C.Final++;
        }
        else if ( C.Final == MAX-1) // Estamos en el borde del arrreglo
            C.Final= 0;
        else
            C.Final++;


        C.Elementos[ C.Final ]= Dato;
    }
}

TipoDato EliminarCola( TipoCola &C )
{
    TipoDato Dato;

    Dato=NULL;
    if ( ColaVacia( C ) == true  )
    {
        printf("Subdesbordamiento en la Cola - Cola Vacia");
        system("Pause");
    }
    else
    {
        Dato= C.Elementos[ C.Frente ];
        if ( C.Frente == C.Final ) // Es el unico elemento
            IniciarCola( C );
        else if ( C.Frente == MAX-1 )
            C.Frente= 0;
        else
            C.Frente++;
    }
    return Dato;
}

void invertir(Cola &C)
{
     while(! PilaVacia())
        S.Push(C.Extraer());

     while(! S.Empty())
        C.Agregar(S.Pop());


void Ejemplo()
{
    TipoCola X;

    // Inicializa la Cola en cero elementos
    IniciarCola( X );

    InsertarCola( X, 5 );
    VerColas(X);

    InsertarCola( X, 8 );
    VerColas(X);

    InsertarCola( X, 4 );
    VerColas(X);

    InsertarCola( X, 11 );
    VerColas(X);
    EliminarCola( X );
    InsertarCola( X, 7 );
    VerColas(X);


    EliminarCola( X );

    InsertarCola( X, 6);
    VerColas(X);


    while ( ColaVacia( X )!= true )
    {
        cout << EliminarCola( X );
        system("pause");
    }

}

void VerColas(TipoCola C)
{
    int Frente, Final;

//se obtiene frente y final de cola
    Frente=C.Frente;
    Final= C.Final;

    do
    {
        cout<<C.Elementos[Frente]<<",";
        if (Frente == MAX -1)
            Frente = 0;
        else
            Frente = Frente + 1;
    }
    while((Frente <= Final));
    cout<<endl;
    cout<<"frente: "<<C.Frente<<endl;
    cout<<"final: "<<C.Final<<endl;
    system("pause");

}

void Spooler() {
    TipoCola X;
    IniciarCola(X);

    for (int i=1; i<61; i++){
        printf("Han pasado %i segundos...\n", i);

        if ( i%5==0){
            InsertarCola( X, 1 );
            printf("CPU 1 mando a imprimir \n");
            system("pause");
        }
        if ( i%10==0){
            InsertarCola( X, 2 );
            printf("CPU 2 mando a imprimir \n");
            //VerCola(X);
            system("pause");
        }
        if ( i%15==0){
            InsertarCola( X, 3 );
            printf("CPU 3 mando a imprimir \n");
            //VerCola(X);
            system("pause");
        }

        system("cls");
    }

    printf("\nCola de impresion actual \n");
    for (int j=1; j<23; j++){
        cout <<""<<EliminarCola(X)<<". ";

    }

}


int main()
{
    Spooler();
    return 0;
}
