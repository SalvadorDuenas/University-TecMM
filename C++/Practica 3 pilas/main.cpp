#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

// Declaración de Constantes
#define MAX 20

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

// Operacion basicas de Pila
void PonerPila( TipoPila &P, TipoDato Dato )
{
  if ( PilaLlena(P)== true )
    {
     printf("Desbordamiento - La pila esta llena...");
	 system("pause");
	}
  else
    {
     P.Tope++;
	 P.Elementos[ P.Tope]= Dato;
    }
}

TipoDato QuitarPila( TipoPila &P )
{ TipoDato Dato;

  Dato=NULL;
  if ( PilaVacia( P ) == true  )
    {
     printf("Subdesbordamiento en la Pila - Pila Vacia");
	 system("Pause");
    }
  else
    {
     Dato= P.Elementos[ P.Tope ];
	 P.Tope--;
    }
  return Dato;
}

void Ejemplo()
{
  TipoPila X;

  // Inicializa la Pila en cero elementos
  IniciarPila( X );

  PonerPila( X, 5 );
  PonerPila( X, 8 );
  PonerPila( X, 4 );

  cout << QuitarPila( X );
  system("pause");

  cout << QuitarPila( X );
  system("pause");

  cout << QuitarPila( X );
  system("pause");

}

void CadenaInversa()
{
  char Cadena[MAX];
  TipoPila A;

  IniciarPila( A );

  cout << "Escribe una cadena: ";
  cin >> Cadena;

  // Se almacena el contenido de la cadena, caracter x caracter dentro de la Pila
  for ( int i=0; i < strlen(Cadena); i++ )
      PonerPila( A, Cadena[i] );

  // Vacias contenido de la Pila
  while ( PilaVacia( A)!= true )
    cout << QuitarPila( A ) << " ";

  system("pause");
}

void DecToBin()
{
  TipoPila B;
  int Dividendo, Residuo, Cociente, Divisor=2;

  IniciarPila( B );

  cout << "Escriba numero decimal a convertir -> ";
  cin >> Dividendo;

  while ( Dividendo >= 2 ) {
  	Cociente= Dividendo / Divisor;
  	Residuo= Dividendo % Divisor;

  	// Guardar Residuo en Pila
	PonerPila( B, Residuo );
  	// Actualizamos dividendo
  	Dividendo= Cociente;
  }
  PonerPila( B, Cociente );

  // Vaciar contenido de la Pila, para visualizar numero binario
  while ( PilaVacia( B )!= true )
    cout << QuitarPila( B ) << " ";

  system("pause");
}







int main()
{
  CadenaInversa();
  return 0;
}
