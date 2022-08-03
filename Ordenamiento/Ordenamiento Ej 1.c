#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max 5

typedef float tVector[max];
tVector A, B, C;

void GenerarVector(tVector);
void OrdenarBurbuja(tVector);
void VisualizarVector(tVector);
void SeleccionDirecta(tVector);
void InsercionDirecta(tVector);

int main()
{
	printf("Cargar Datos en el vector A: \n");
	GenerarVector(A);
	VisualizarVector(A);
	OrdenarBurbuja(A);
	printf("\nVector luego de la ordenacion por el metodo de Burbuja: ");
	VisualizarVector(A);
	
	printf("\nCargar Datos en el vector B: \n");
	GenerarVector(B);
	VisualizarVector(B);
	SeleccionDirecta(B);
	printf("\nVector luego de la ordenacion por el metodo de Seleccion Directa: ");
	VisualizarVector(B);
	
	printf("\nCargar Datos en el vector C: \n");
	GenerarVector(C);
	VisualizarVector(C);
	InsercionDirecta(C);
	printf("\nVector luego de la ordenacion por el metodo de Insercion Directa: ");
	VisualizarVector(C);
	
	return 0;
}

void GenerarVector(tVector pVector)
{
	int i;
	for(i=0; i<max; i++)
	{
		printf("Ingrese un valor flotante: ");
		scanf("%f", &pVector[i]); fflush(stdin);
	}
}

void OrdenarBurbuja(tVector pVector)
{
	int i, j;
	float aux;
	bool bandera;
	
	bandera = false;
	i = 0;
	while((bandera == false) && (i<max))
	{
		bandera = true;
		for(j=0; j<max-1; j++)
		{
			if(pVector[j] > pVector[j+1])
			{
				aux = pVector[j];
				pVector[j] = pVector[j+1];
				pVector[j+1] = aux;
				bandera = false;
			}
		}
		i = i + 1;
	}
}

void VisualizarVector(tVector pVector)
{
	int i;
	printf("\nContenido del vector:\n");
	for(i=0; i<max; i++)
	{
		printf("%.2f\t", pVector[i]);
	}
	printf("\n");
}

void SeleccionDirecta(tVector pVector)
{
	int i, j, posMenor;
	float valMenor, aux;
	
	for(i=0; i<max-1; i++)
	{
		valMenor = pVector[i];
		posMenor = i;
		
		for(j = i+1; j<max; j++)
		{
			if(pVector[j] < valMenor)
			{
				valMenor = pVector[j];
				posMenor = j;
			}
		}
		if (posMenor != i)
		{
			aux = pVector[i];
			pVector[i] = pVector[posMenor];
			pVector[posMenor] = aux;
		}
	}
}

void InsercionDirecta(tVector pVector)
{
	int i, j;
	float aux;
	
	for(i=1; i<max; i++)
	{
		aux = pVector[i];
		j = i - 1;
		while((j>=0) && (pVector[j] > aux))
		{
			pVector[j+1] = pVector[j];
			j = j - 1;
		}
		pVector[j+1] = aux;
	}
}





















