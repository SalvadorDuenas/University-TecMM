#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 20

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

// Estructura o registro nodo de la lista
struct nodo {
              struct nodo *LigaIzq;
 	          TipoDato Info;
              struct nodo *LigaDer;
       };

// Se define alias tipo Lista
typedef struct nodo *Lista;

void InicializarLista( Lista &P, Lista &F )
{
  P= NULL;
  F= NULL;
}

bool ListaVacia( Lista P, Lista F )
{
  if ( P == NULL && F== NULL )
     return true;
  else
     return false;
}

void RecorrerLista( Lista P )
{
  Lista Q;

  Q= P;
  while ( Q != NULL) {
  	cout << Q->Info << " ";
  	Q= Q->LigaDer;
  }

}

void RecorrerListaAlrevez( Lista F )
{
  Lista Q;

  Q= F;
  while ( Q != NULL) {
  	cout << Q->Info << " ";
  	Q= Q->LigaIzq;
  }

}

void InsertarInicio( Lista &P, Lista &F, TipoDato Dato )
{
  Lista Q;

  Q= new nodo;
  Q->Info= Dato;
  Q->LigaIzq= NULL;

  if (ListaVacia(P, F)==true)
    {
     Q->LigaDer= P;
	 P= Q;
	 F= Q;
	}
  else
    {
     Q->LigaDer= P;
	 P->LigaIzq= Q;
	 P= Q;
    }
}

void InsertarFinal( Lista &P, Lista &F, TipoDato Dato )
{
  Lista Q;

  Q= new nodo;
  Q->Info= Dato;
  Q->LigaDer= NULL;

  if (ListaVacia(P, F)==true)
    {
     Q->LigaIzq= F;
	 P= Q;
	 F= Q;
	}
  else
    {
     Q->LigaIzq= F;
	 F->LigaDer= Q;
	 F= Q;
    }
}

void InsertarDespuesX( Lista &P, Lista &F, TipoDato Dato, TipoDato Ref )
{
  Lista Q, X, T;
  int Band;

  if ( ListaVacia( P, F )!= true )
	{
     Q= P; // Q comienza la busqueda de Ref desde P
	 Band= 1;

	 while ( ( Q->Info != Ref ) && ( Band == 1 ) )
	   if ( Q->LigaDer != NULL )
	      Q= Q->LigaDer;
	   else
		  Band= 0;

	 if ( Band == 1 ) // Se encontro la referencia
	   {
	   	X= new nodo;
		X->Info= Dato;
		if ( F == Q ) // La referencia esta en el 1er nodo
		  {
		   Q->LigaDer= X;
		   X->LigaIzq= Q;
		   X->LigaDer= NULL;
		   F= X;
	      }
	    else
		  {
		   T= Q->LigaDer; // Se posiciona T
		   Q->LigaDer= X;
		   X->LigaIzq= Q;
		   X->LigaDer= T;
		   T->LigaIzq= X;
		  }
	   }
	 else
	   {
	   	printf("La referencia no fue encontrada!");
		system("pause");
	   }
    }
   else
     {
      printf("La lista esta vacia!");
	  system("pause");
     }
}

void EliminarPrimero( Lista &P, Lista &F )
{
  Lista Q;

  if ( ListaVacia( P, F )!= true )
    {
     if ( P==F ) // hay un unico nodo
	   {
	  	P= NULL;
		F= NULL;
	   }
	 else
	   {
	   	Q= P;
	   	P= Q->LigaDer;
	   	P->LigaIzq= NULL;
       }
     delete Q;
	}
  else
    {
     printf("La lista esta vacia!");
	 system("pause");
	}
}

void EliminarUltimo( Lista &P, Lista &F )
{
  Lista Q;

  if ( ListaVacia( P, F )!= true )
    {
     if ( P == F ) // hay un unico nodo
	   {
	  	P= NULL;
		F= NULL;
	   }
	 else
	   {
	   	Q= F;
	   	F= Q->LigaIzq;
	   	F->LigaDer= NULL;
       }
     delete Q;
	}
  else
    {
     printf("La lista esta vacia!");
	 system("pause");
	}
}


void EliminarX( Lista &P, Lista &F, TipoDato Ref )
{
  Lista Q, T, R;
  int Band;

  if ( ListaVacia( P, F )!= true )
	{
     Q= P; // Q comienza la busqueda de Ref desde P
	 Band= 1;

	 while ( ( Q->Info != Ref ) && ( Band == 1 ) )
	   if ( Q->LigaDer != NULL )
		  Q= Q->LigaDer;
	   else
		  Band= 0;

	 if ( Band == 1 ) // Se encontro la referencia
	   {
	   	if ( P == F ) // Es el unico nodo
	   	  {
	   	   P= NULL;
		   F= NULL;
		  }
		else
		   if ( P == Q ) // Es el primer nodo
	   	     {
		      P= Q->LigaDer;
	   	      P->LigaIzq= NULL;
	         }
	   	   else
	   	     {
	   	      if ( F == Q ) // Es el ultimo nodo
	   	        {
	   	  	     F= Q->LigaIzq;
			     F->LigaDer= NULL;
		        }
		      else
		        {
		         T= Q->LigaIzq;
			     R= Q->LigaDer;
		         T->LigaDer= R;
			     R->LigaIzq= T;
			    }
		     }

	   	delete Q;
       }
    }
}

void MenuPrincipal()
{
  int Opc;
  int x, y;
  Lista A, B;

  InicializarLista( A, B );

  do {
  	   //Despliegue de Menu
	   system("cls");
  	   printf("LISTAS SIMPLEMENTE LIGADAS....\n");
  	   printf("1. Insertar un nodo al principio.\n");
  	   printf("2. Insertar un nodo al final de la lista.\n");
  	   printf("3. Insertar un nodo antes de un referencia.\n");
  	   printf("4. Insertar un nodo despues de un referencia.\n");
  	   printf("5. Eliminar el primer nodo de la lista.\n");
  	   printf("6. Eliminar el ultimo nodo de la lista.\n");
  	   printf("7. Eliminar un nodo X.\n");
  	   printf("8. Eliminar un nodo antes de un nodo referencia.\n");
  	   printf("9. Eliminar el nodo despues de un nodo referencia.\n");
  	   printf("10. Mostrar lista.\n");
  	   printf("0. Salir.\n");


		 // El usuario indica la opcion correspondiente
	   printf("Opcion: "); scanf("%i", &Opc);

  	   switch (Opc){
		 case 1: // Insertar al inicio
		         printf("Escriba valor a insertar: ");
		         scanf("%i", &x);
		         InsertarInicio( A, B, x );
				 break;
		 case 2: // Insertar al final
		         printf("Escriba valor a insertar: ");
		         scanf("%i", &x);
		         InsertarFinal(A, B, x);
				 break;

		 case 3: // Insertar antes de referencia
		         printf("Escriba valor a Insertar: ");
		         scanf("%i", &x);
   		         printf("Escriba la referencia: ");
		         scanf("%i", &y);
		         //InsertarAntesX( A, B, x, y);
				 break;

		 case 4: // Insertar despues de referencia
		         printf("Escriba valor a Insertar: ");
		         scanf("%i", &x);
   		         printf("Escriba la referencia: ");
		         scanf("%i", &y);
		         InsertarDespuesX( A, B, x, y );
				 break;
		 case 5: // Eliminar el primero
		         EliminarPrimero( A, B );
				 break;

		 case 6: // Eliminar el ultimo
		         EliminarUltimo( A, B );
				 break;

		 case 7: // Eliminar nodo X
		         printf("Escriba valor del nodo referencia: ");
		         scanf("%i", &x);
  		         EliminarX( A, B, x );
				 break;

		 case 8: // Eliminar nodo antes de Referencia
		         printf("Escriba valor del nodo (referencia) a eliminar antes: ");
		         scanf("%i", &x);
  		         //EliminarAntesX( A, x );
				 break;

		 case 9: // Eliminar nodo despues de Referencia
		         printf("Escriba valor del nodo (referencia) a eliminar despues: ");
		         scanf("%i", &x);
  		         //EliminarDespuesX( A, x );
				 break;

		 case 10: // Recorrer lista - Consultar
		         RecorrerLista( A );
		         system("pause");
				 break;
		 }
  } while( Opc != 0 );

}

int main()
{
  MenuPrincipal();

  return 1;
}

