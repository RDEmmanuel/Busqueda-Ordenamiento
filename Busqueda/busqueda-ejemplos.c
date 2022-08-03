#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define max 5
typedef int tVectorInt [max];
int busquedaSecuencial(tVectorInt, int);
int busquedaSecuencialOrdenada(tVectorInt, int);
int busquedaBinaria(tVectorInt, int);
int buscarMayor(tVectorInt);
int buscarMenor(tVectorInt);

void cargarVectorOrdenado();
void cargarVectorDesordenado();
void mostrarElementos();

tVectorInt v;

int main() {		
	cargarVectorDesordenado();
	mostrarElementos();
	printf("Posicion del elemento buscado segun busquedaSecuencial: %d\n\n", busquedaSecuencial(v, 50));
 	
 	cargarVectorOrdenado();
	mostrarElementos();
	printf("Posicion del elemento buscado segun busquedaSecuencialOrdenada: %d\n", busquedaSecuencialOrdenada(v, 50));
	printf("Posicion del elemento buscado segun busquedaBinaria: %d\n\n", busquedaBinaria(v, 50));
	
	cargarVectorDesordenado();
	mostrarElementos();
	printf("Posicion del mayor elemento segun supuesto o prepo: %d\n", buscarMayor(v));
	printf("Posicion del menor elemento segun supuesto o prepo: %d\n\n", buscarMenor(v));

 	return 0;
 }

void cargarVectorOrdenado() {
	v[0]= 10;
	v[1]= 20;
	v[2]= 30;
	v[3]= 40;
	v[4]= 50;	
}

void cargarVectorDesordenado() {
	int i;
	/*  la función srand recibe como parámetro un número que se utilizará 
		como semilla del inicial para las cuentas de los números aleatorios. 
		A esta función sólo debemos llamarla una vez en nuestro programa. */
	srand(time(NULL));
	for (i = 0; i<max; i++) {
		/*  numeros aleatorios entre M y N: 
			M + (N+1-M) ó dicho de otra manera:
			limite_inferior + rand() % (limite_superior + 1 - limite_inferior)*/
		v[i] = 0 + rand() % (100+1-0); 
	}
}

void mostrarElementos() {
	int i;
	for (i=0; i<max; i++) {
 		printf("%d\t", v[i]);
 	}
 	printf("\n");
}

int busquedaSecuencial(tVectorInt p_v, int elem){
	int result = -1; // result se usará para guardar la posición del valor encontrado ó -1 en caso contrario
	int i = 0; // se inicia el contador
	while((p_v[i] != elem) && (i != max)){
		i = i + 1;	
	}	
	if(p_v[i] == elem){ 
		/* significa que se ha encontrado el elemento elem, 
			entonces se devuelve la posición del elemento en el vector */
		result = i;
	} 
	return result;
}

int busquedaSecuencialOrdenada(tVectorInt p_v, int elem) {	
	/* Pre-Condicion: p_v ordenado crecientemente */
	int result = -1; // result se usará para guardar la posición del valor encontrado ó -1 en caso contrario
	int i = 0; // se inicia el contador
	while ((p_v[i] < elem) && (i <= max)){
		i = i + 1;
	}
	if (p_v[i] == elem) {
		// se ha encontrado el elemento elem
		result = i;
	}
}

int busquedaBinaria(tVectorInt p_v, int elem) {	
	/* 	Pre-Condicion: p_v ordenado crecientemente 
		Devuelve -1 (si elem no esta en p_v) ó la posición i (si p_v[i] = elem) */
	int extInf, extSup; // extremos del intervalo
	int posMed; // posicion central del intervalo
	bool encontrado;

	int result = -1; // result se usará para guardar la posición del valor encontrado ó -1 en caso contrario
	
	extInf = 1;
	extSup = max;
	encontrado = false;
	while ((!encontrado) && (extSup >= extInf)) {
		posMed = (extSup + extInf) / 2;
		if (elem == p_v[posMed]) {
			encontrado = true;
		} 
		else {
			if (elem > p_v[posMed]) {
				/* se actualizan los extremos del intervalo */
				extInf = posMed + 1;
			} else {
				extSup= posMed - 1;
			}			
		}	
	} 
	
	if (encontrado) {
		result = posMed;
	}
	return result;
}

/* Busca el mayor valor y devuelve la posición en la cual se encuentra - Supuesto o prepo */
int buscarMayor(tVectorInt p_v)  {
	int i, va_mayor, va_indMayor;
	va_mayor = 0;
	va_indMayor = -1;
	for (i = 0; i<max; i++) {
		if (p_v[i] > va_mayor) {
			va_mayor = p_v[i];
			va_indMayor = i;
		}
	}
	return va_indMayor;
} 

/* Busca el menor valor y devuelve la posición en la cual se encuentra - Supuesto o prepo */
int buscarMenor(tVectorInt p_v)  {
	int i, va_menor, va_indMenor;
	va_menor = 99999;
	va_indMenor = -1;
	for (i = 0; i<max; i++) {
		if (p_v[i] < va_menor) {
			va_menor = p_v[i];
			va_indMenor = i;
		}
	}
	return va_indMenor;
} 





