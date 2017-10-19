/* 
*	Nombre: PROYECTO 2
*	Fecha: 18-10-2017
*	Elaborado por: CAMILA ANDREA BORJA SANCHEZ Y KELIN ALEJANDRA ARBOLEDA DAVILA.
*/

//Librerias;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))
#define COLA 1
#define PILA 2

//Estructura para un siguiente dato;
struct Nodo{
	int dato;
	Nodo *sig;
};

//Prototipo de las funciones de las listas;
void insertar(Nodo *&inicio, int dato);
void eliminar(Nodo *&inicio, int tipo);
void editar(Nodo *&inicio, int dato);
void imprimir(Nodo *inicio, int tipo);
void ordenar(Nodo *&inicio);
void vaciar(Nodo *&inicio);
void buscar(Nodo *inicio, int dato);
void generar(Nodo *&inicio, int tipo);
void cargar(Nodo *&inicio, int tipo);
void salvar(Nodo *inicio, int tipo);

//prototipos de los Menus
void menuPrincipal();
void menuPila();
void menuCola();

//variables globales
Nodo *Pila = NULL;
Nodo *Cola = NULL;

//para calcular el tiempo
clock_t tiempo;

//funcion principal
int main(){
	menuPrincipal();
	
	return 0;
}

//funcion Menu principal
void menuPrincipal(){
	int opcion;
	do{
		printf("\n.............................");
		printf("\n.    BIENVENIDO             .");
		printf("\n.............................");
		printf("\n.    1. Pila                .");
		printf("\n.    2. Cola                .");
		printf("\n.    0. Salir               .");
		printf("\n.............................\n");
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: menuPila();
				break;
			case 2: menuCola();
				break;
			case 0: exit(0);
				break;
			default: printf("\nOpcion No Valida");	
		}
		system("pause");
		system("cls");
	}while(opcion != 0);
}

//funcion para el menu de pila
void menuPila(){
	int opcion, dato;
	do{
		printf("\n.............................");
		printf("\n.           PILA            .");
		printf("\n.............................");
		printf("\n.    1. Generar Datos       .");
		printf("\n.    2. Cargar Datos        .");
		printf("\n.    3. Ver Pila            .");
		printf("\n.    4. Eliminar Elemento   .");
		printf("\n.    5. Buscar Dato         .");
		printf("\n.    6. Editar              .");
		printf("\n.    7. Vaciar Pila         .");
		printf("\n.    8. Salvar Datos        .");
		printf("\n.    9. Ordenar Pila        .");
		printf("\n.    0. Salir               .");
		printf("\n.............................\n");
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1: generar( Pila, PILA ); 
					break;
			case 2: cargar( Pila, PILA ); 
					break;
			case 3: imprimir( Pila, PILA );
					break;
			case 4: eliminar( Pila, PILA ); 
					break;
			case 5: printf("Ingrese valor a buscar: ");
					scanf("%d", &dato);
					buscar( Pila, dato); 
					break;
			case 6: printf("Ingrese valor a editar: ");
					scanf("%d", &dato);
					editar( Pila, dato); 
					break;
			case 7: vaciar( Pila ); 
					break;
			case 8: salvar( Pila, PILA ); 
					break;
			case 9: ordenar( Pila ); 
					break;
			case 0: menuPrincipal(); 
					break;
			default: printf("\nOpcion No Valida");	
		}
	}while(opcion != 0);
}

//funcion para el menu de cola
void menuCola(){
	int opcion, dato;
	do{
		printf("\n.............................");
		printf("\n.           COLA            .");
		printf("\n.............................");
		printf("\n.    1. Generar Datos       .");
		printf("\n.    2. Cargar Datos        .");
		printf("\n.    3. Ver Cola            .");
		printf("\n.    4. Eliminar Elemento   .");
		printf("\n.    5. Buscar Dato         .");
		printf("\n.    6. Editar              .");
		printf("\n.    7. Vaciar Cola         .");
		printf("\n.    8. Salvar Datos        .");
		printf("\n.    9. Ordenar Cola        .");
		printf("\n.    0. Salir               .");
		printf("\n.............................\n");
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1: generar(Cola, COLA); 
					break;
			case 2: cargar(Cola, COLA); 
					break;
			case 3: imprimir(Cola, COLA); 
					break;
			case 4: eliminar(Cola, COLA); 
					break;
			case 5: printf("Ingrese valor a buscar: ");
					scanf("%d", &dato);
					buscar(Cola, dato); 
					break;
			case 6: printf("Ingrese valor a editar: ");
					scanf("%d", &dato);
					editar(Cola, dato); 
					break;
			case 7: vaciar(Cola); 
					break;
			case 8: salvar(Cola, COLA); 
					break;
			case 9: ordenar(Cola); 
					break;
			case 0: menuPrincipal(); 
					break;
			default: printf("\nOpcion No Valida");	
		}
	}while(opcion != 0);
}

//funcion de las operaciones de las listas

//esta funcion permite insertar datos a la pila o a la cola segun sea requerido 
void insertar(Nodo *&inicio, int dato){
	Nodo *nuevo = reservar_memoria;
	nuevo->dato = dato;
	nuevo->sig = NULL;
	if(inicio == NULL){
		inicio = nuevo;
	}else{
		Nodo *tmp = inicio;
		while( tmp->sig != NULL ){
			tmp = tmp->sig;
		}
		tmp->sig = nuevo;
	}
}

//esta funcion permite mostrar los datos en pantalla de la pila o de la cola segun sea requerido
void imprimir(Nodo *inicio, int tipo){
	tiempo = clock();

	if( inicio == NULL ){
		printf("\nLista vacia.\n");
	}else{
		Nodo *tmp = inicio;
		int cont = 0;
		switch(tipo){
			case PILA:  printf("\nPILA: \n");
						break;
			case COLA:	printf("\nCOLA: \n");
						break;
			default: 	printf("Tipo de estructura invalida.\n");
		}
		while(tmp != NULL){
			printf("%d\t", tmp -> dato);
			tmp = tmp->sig;
			if( ++cont%10 == 0)
			printf("\n");
		}
		printf("\n");
	}

	tiempo = clock() - tiempo;
	printf("Imprimir lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite eliminar datos de la pila o de la cola segun sea requerido
void eliminar(Nodo *&inicio, int tipo){
	tiempo = clock();	

	switch(tipo){
		case COLA: 	if(inicio == NULL){
						printf("\nCOLA VACIA\n");
					}else{
						Nodo *aux = inicio;
						inicio = aux->sig;
						free(aux);
					}
					break;

		case PILA: 	if(inicio == NULL){
						printf("\nPILA VACIA\n");
					}else{
						if(inicio->sig == NULL){
							Nodo *aux = inicio;
							inicio = NULL;
							free(aux);
						}else{
							Nodo *aux = inicio;
							Nodo *tmp;
							while( aux->sig->sig != NULL){
								aux = aux->sig;
							}
							tmp = aux->sig;
							aux->sig = NULL;
							free(tmp);
						}
					}
					break;	

		default: printf("\nTipo de estructura invalida.\n");
	}

	tiempo = clock() - tiempo;
	printf("Eliminar elemento tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite editar los datos de la pila o de la cola segun sea requerido
void editar(Nodo *&inicio, int dato){
	tiempo = clock();

	if(inicio == NULL){
		printf("\nLista vacia.\n");
	}else{
		Nodo *aux = inicio;
		while( aux->sig != NULL){
			if( aux->dato == dato){
				int newDato;
				printf("ingrese nuevo valor: ");
				scanf("%d",&newDato);
				aux->dato = newDato;
				break;
			}
			aux = aux->sig;
		}
		if( aux == NULL ) printf("\nDato no encontrado.\n");
	}

	tiempo = clock() - tiempo;
	printf("Editar elemento tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite ordenar los datos de la pila o de la cola segun sea requerido
void ordenar(Nodo *&inicio){
	tiempo = clock();

	if( inicio == NULL ){
		printf("\nLista vacia.\n");
	}else{
		Nodo *aux;
		Nodo *tmp;
		int x;
		aux = inicio;
		while( aux != NULL){
			tmp = aux->sig;
			while( tmp != NULL){
				if( aux->dato > tmp->dato ){
					x = aux->dato;
					aux->dato = tmp->dato;
					tmp->dato = x;
				}
				tmp = tmp->sig;
			}
			aux = aux->sig;
		}
	}

	tiempo = clock() - tiempo;
	printf("Ordenar lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite insertar datos a la pila y a la cola segun sea requerido
void vaciar(Nodo *&inicio){
	tiempo = clock();

	Nodo *aux = inicio;
	inicio = NULL;
	free(aux);

	tiempo = clock() - tiempo;
	printf("Vaciar lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite buscar datos en la pila o en la cola segun sea requerido
void buscar(Nodo *inicio,int dato){
	tiempo = clock();

	if( inicio == NULL ){
		printf("\nLista vacia.\n");
	}else{
		int cont = 0;
		Nodo *aux = inicio;
		while( aux != NULL ){
			if( aux->dato == dato) 
			cont++;
			aux = aux->sig;
		}
		if( cont == 0){
			printf("\nDato no encontrado.\n");
		}else{
			printf("\nDato encontrado. %d coincidencias.\n",cont);
		}
	}

	tiempo = clock() - tiempo;
	printf("Buscar elemento tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite generar datos para ser insertados en la pila o en la cola segun sea requerido
void generar(Nodo *&inicio, int tipo){
	int opcion, cantidad, aleatorio;
	do{
		printf("\n.............................");
		printf("\n.       CANTIDAD DATOS      .");
		printf("\n.............................");
		printf("\n.   1. 1 Millon             .");
		printf("\n.   2. 2 Millones           .");
		printf("\n.   3. 5 Millones           .");
		printf("\n.   4. 10 Millones          .");
		printf("\n.   5. 20 Millones          .");
		printf("\n.   0. Salir                .");
		printf("\n.............................");
		printf("\nOpcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1: cantidad = 1; 
				break;
			case 2: cantidad = 2; 
				break;
			case 3: cantidad = 5; 
				break;
			case 4: cantidad = 10;
				break;
			case 5: cantidad = 20; 
				break;
			case 0: menuPrincipal(); 
				break;
			default: printf("\nOpcion no valida. ");
		}
	}while(opcion < 0 || opcion > 5);
	cantidad *= 100000; //cambiar a 1000000
	srand(time(NULL));

	tiempo = clock();
	for(int i=0; i<cantidad; i++){
		aleatorio = (rand()%1999 - 999)*1000 + (rand()%1999 - 999);
		insertar( inicio, aleatorio );
	}
	tiempo = clock() - tiempo;
	printf("Generar lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);

	switch(tipo){
		case PILA:  menuPila();
			break;
		case COLA:	menuCola();
			break;
		default: 	printf("Tipo de estructura invalida.\n");
	}
}

//esta funcion permite cargar datos a la pila o a la cola segun sea requerido
void cargar(Nodo *&inicio, int tipo){
	tiempo = clock(); 

	FILE *entrada;
	int dato;
	switch(tipo){
		case PILA:  printf("Asegurese que su archivo se llama datosPILA.txt.\n");
					system("pause");
					if ((entrada = fopen("datosPILA.txt", "r")) == NULL){
						printf("Problemas con el archivo.\n");
						return ;
					}
					break;
		case COLA:	printf("Asegurese que su archivo se llama datosCOLA.txt.\n");
					system("pause");
					if ((entrada = fopen("datosCOLA.txt", "r")) == NULL){
						printf("Problemas con el archivo.\n");
						return ;
					}
					break;
		default: 	printf("Tipo de estructura invalida.\n");
					return;
	}
	while( fscanf(entrada, "%d", &dato) == 1 ){
		insertar(inicio, dato);
	}
    fclose(entrada);

    tiempo = clock() - tiempo;
	printf("Cargar lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}

//esta funcion permite salvar los datos de la pila o de la cola segun sea requerido
void salvar(Nodo *inicio, int tipo){
	tiempo = clock();

	FILE *salida;
	switch(tipo){
		case PILA:  salida = fopen("salvarPILA.txt", "w+");
					break;
		case COLA:	salida = fopen("salvarCOLA.txt", "w+");
					break;
		default: 	printf("Tipo de estructura invalida.\n");
					return;
	}
	if( inicio == NULL ){
		fprintf(salida, "\nLista vacia.\n");
	}else{
		Nodo *tmp = inicio;
		int cont = 0;
		while(tmp != NULL){
			fprintf(salida, "%d\t", tmp -> dato);
			tmp = tmp->sig;
			if( ++cont%10 == 0) fprintf(salida, "\n");
		}printf("\n");
	}
    fclose(salida);

    tiempo = clock() - tiempo;
	printf("Salvar lista tomo %f segundos.\n", (float)tiempo/CLOCKS_PER_SEC);
}
