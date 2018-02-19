//Escrito por Noé Reyes Guerra
//
//ProgramadorPlus.com

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

struct Pila{
	int tope;
	int capacidad;
	int* arreglo;
	};

struct Pila* crearPila(int capacidad){
	struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila)); //Reserva del bloque de memoria
	pila->capacidad = capacidad; //Asignamos el tamaño de la pila
	pila->tope = -1; //Inicializamos el valor en el tope de la pila
	pila->arreglo = (int*)malloc(pila->capacidad*sizeof(int)); //Creamos un arreglo que almacenara los datos
	return pila;
	}

int estaLlena(struct Pila* pila){
	return pila->tope == pila->capacidad-1;
	}

int estaVacia (struct Pila* pila){
	return pila->tope == -1;
	}

void PUSH(struct Pila* pila, int elemento){
	if (estaLlena(pila))
		return;
	pila->arreglo[++pila->tope] = elemento;
	printf("Agregado a la pila: %i\n", elemento);
	}

int POP(struct Pila* pila){
	if (estaVacia(pila))
		return INT_MIN;
	return pila->arreglo[pila->tope--];
	}

int PEEK(struct Pila* pila){
	int val = POP(pila);
	PUSH(pila,val);
	return val;
	}

void imprimir(struct Pila* pila){
	printf("____\n");
	for (int i = 0; i <= pila->tope; i++)
		printf("%i\n", pila->arreglo[i]);	
	printf("____\n");
	}

int buscar(struct Pila* pila, int valor){
	for (int i = 0; i <= pila->tope; i++)
		if (pila->arreglo[i] == valor)
			return i;
	return -1;
	}

int numElementos(struct Pila* pila){
	return pila->tope+1;
	}

int main(){
	struct Pila* pila = crearPila(5); //Creamos la pila con 5 espacios
	PUSH(pila, 100); // [100,-,-,-,-]
	PUSH(pila, 200); // [100, 200, -,-,-]
	PUSH(pila, 300); // [100, 200, 300, ,- ,-]
	PUSH(pila, 400); // [100, 200, 300, 400, -]
	PUSH(pila, 500); // [100, 200, 300, 400, 500]
	printf("Eliminado de la pila: %i\n", POP(pila)); // [100, 200, 300, 400,-]
	printf("Eliminado de la pila: %i\n", POP(pila)); // [100, 200, 300, -, -]
	PUSH(pila, 600); // [100, 200, 300, 600]
	PUSH(pila, 700); // [100, 200, 300, 600, 700]
	imprimir(pila);
	printf("La pila tiene %i elementos\n",numElementos(pila));
	if (estaLlena(pila))
		printf("La pila esta llena");
	}
