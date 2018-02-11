// 2018/02/11 - 04:30
// Escrito por Noé Reyes Guerra para ProgramadorPlus.com

#include "stdio.h"
#include "stdlib.h"

struct Nodo{
	int dato;
	struct Nodo* sig;
	};

int numElementos = 0;

void imprimir (struct Nodo* inicio);
int buscar(struct Nodo* inicio, int valor);
void insertarFrente(struct Nodo** frente, int valor);
void insertarDespues(struct Nodo* frente, int indice, int valor);
void insertarUltimo(struct Nodo** frente, int valor);

void imprimir(struct Nodo* inicio){
	if (numElementos == 0){
		printf ("Lista vacia");
		return;
		}
	for (struct Nodo* n=inicio;n!=NULL;n=n->sig)
		printf("%i ",n->dato);
	printf("\n");
	return;
	}
	
int buscar(struct Nodo* inicio, int valor){
	int i = 0;
	for (struct Nodo* n=inicio;n!=NULL;n=n->sig, i++){
		if (valor == n->dato)
			return i;
			}
	return -1;
	}

void insertarFrente(struct Nodo** frente, int valor){
	// 1. Inicializar un nuevo nodo y reservar un bloque de memoria
	struct Nodo* nuevo = NULL;
	nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	// 2. Asignar el valor al nodo
	nuevo->dato = valor;
	
	// 3. Hacer que el actual frente de la lista sea el nodo siguiente al nuevo
	nuevo->sig = (*frente);
	
	// 4. Hacer del nuevo nodo el nuevo frente de la lista
	(*frente) = nuevo;
	
	numElementos++;
	return;
	}

void insertarDespues(struct Nodo* frente, int indice, int valor){
	// 1. Iniciamos el nodo previo en el frente de la lista
	struct Nodo* previo = frente;
	
	// 2. Colocamos el nodo en la posicion previa al nuevo nodo
	for (int i = 0; i<indice;i++){
		previo = previo->sig;
		}
	
	// 3. Comprobamos que el nodo previo existe
	if (previo == NULL){
		printf("Nodo previo inexistente. Operacion no realizada.");
		return;
		}
	
	// 4. Reservamos espacio en memoria para el nuevo nodo
	struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	// 5. Almacenamos el valor deseado en el nuevo nodo
	nuevo->dato = valor;
	
	// 6. Apuntamos el nuevo nodo hacia el que le seguia al previo
	nuevo->sig = previo->sig;
	
	// 7. Apuntamos nuestro nodo previo hacia el nuevo
	previo->sig = nuevo;
	
	// 8. Aumentamos el contador de elementos
	numElementos++;
	return;
	}

void insertarUltimo(struct Nodo** frente, int valor){
	// 1. Inicializacion del nuevo nodo y reserva de espacio de memoria
	struct Nodo* nuevo = NULL;
	nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	// 2. Almacenamos el valor en el nuevo nodo
	nuevo->dato = valor;
	
	// 3. Al ser el ultimo nodo de la lista, hacemos que apunte a NULL
	nuevo->sig = NULL;
	
	// 4. Si el frente de la lista es NULL (No existe), entonces el nuevo nodo es el frente y terminamos la funcion
	if (*frente == NULL){
		*frente = nuevo;
		numElementos++;
		return;
	}
	
	// 5. Inicializamos un nodo "ultimo" que toma el valor del frente de la lista
	struct Nodo* ultimo = *frente;
	
	// 6. Utilizamos "ultimo->sig" para recorrer la lista hasta llegar al final
	while (ultimo->sig != NULL)
		ultimo = ultimo->sig;
	
	// 7. Apuntamos el ultimo elemento de la lista hacia el nuevo nodo
	ultimo->sig = nuevo;
	
	numElementos++;
	return;
	}

struct Nodo* obtenerNodo (struct Nodo* frente, int indice){
	// Si el indice es menor a 0 o mayor/igual al numero de elementos
	// entonces no hay ningun elemento con ese índice, y se retorna NULL
	if (indice >= numElementos || indice < 0){
		printf("Error");
		return NULL;
		}
	
	// El nodo "n" comienza por el frente de la lista...
	struct Nodo* n = frente;
	
	// ...y utilizando el ciclo for recorremos la lista.
	// n tomara el valor de cada nodo hasta llegar a la posicion deseada
	for (int i = 0; i<indice;i++){
		n = n->sig;
		}
	
	return n;
	}

int eliminarNodo (struct Nodo** frente, int indice){
	// Almacena el puntero inicial de la lista
	struct Nodo* n = *frente;
	
	// Declaramos variable donde almacenaremos el valor del nodo
	int val;
	
	// Si el primer nodo sera eliminado...
	if (indice == 0){
		*frente = n->sig; // Cambia el frente de la lista
		val = n->dato;    // Almacena el valor del nodo
		free(n);          // Libera la memoria reservada por el nodo
		numElementos--;
		return val;       // Retorna el valor almacenado
		}
	
	// Ciclo para encontrar el nodo anterior al que sera eliminado
	for (int i=0; i<indice-1; i++)
		n = n->sig;
	
	// Almacena el puntero del nodo siguiente al que sera eliminado
	struct Nodo* siguiente = n->sig->sig;
	val = n->sig->dato; // Almacena el valor del nodo
	free(n->sig); // Libera la memoria reservada por el nodo
	n->sig = siguiente; // Desenlaza el nodo eliminado de la lista
	numElementos--;
	return val;
	}

int main(){
	struct Nodo* frente = NULL;
	insertarUltimo(&frente, 8);		//8
	insertarUltimo(&frente, 12);	//8->12
	insertarFrente(&frente, 24);	//24->8->12
	insertarDespues(frente, 1, 26);	//24->8->26->12
	
	printf("Lista enlazada:\n");
	imprimir(frente);
	
	eliminarNodo(&frente, 1); //24->26->12
	eliminarNodo(&frente, 1); //24->12
	eliminarNodo(&frente, 1); //24
	eliminarNodo(&frente, 0); //NULL
	
	imprimir(frente);
	return 0;
	}


//int main(){
	
	////Creación de tres nodos de la lista enlazada
	//struct Nodo* frente = NULL;
	//struct Nodo* segundo = NULL;
	//struct Nodo* tercero = NULL;
	
	////Reservamos un bloque de memoria para cada nodo
	//frente = (struct Nodo*)malloc(sizeof(struct Nodo));
	//segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
	//tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	////Asignamos valores enteros a cada nodo
	//frente->dato = 2;
	//segundo->dato = 4;
	//tercero->dato = 6;
	
	////Enlazamos los nodos
	//frente->sig = segundo;
	//segundo->sig = tercero;
	//tercero->sig = NULL;
	
	////Imprimimos sus valores en pantalla
	//struct Nodo* n = frente;
	//while (n != NULL){
		//printf("%i\t", n->dato);
		//n = n->sig;
		//}
  
  ////Fin de la función main()
	//return 0;
//}
