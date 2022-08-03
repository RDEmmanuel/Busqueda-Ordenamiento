#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 10

typedef int tVector[max];
tVector A, B;

void CargarVectorAleatorio(tVector);
void Visualizar(tVector);
void Shell(tVector);
void QuickSort(int*, int*);
void Intercambio(int* a, int* b);

int main()
{
	CargarVectorAleatorio(A);
	Visualizar(A);
	Shell(A);
	printf("\n");
	printf("Vector luego del ordenamiento por el metodo de Shell:\n");
	Visualizar(A);
	system("pause");
	printf("\n");
	
	CargarVectorAleatorio(B);
	Visualizar(B);
	QuickSort(&B[0], &B[max-1]);
	printf("\n");
	printf("Vector luego del ordenamiento por el metodo de QuickSort:\n");
	Visualizar(B);
	system("pause");
	
	return 0;
}

void CargarVectorAleatorio(tVector vector)
{
	int i;
	srand(time(NULL));
	for(i=0; i<max; i++)
	{
		vector[i] = 0 + rand() % (100+1-0);
	}
}

void Visualizar(tVector vector)
{
	int i;
	printf("Contenido del vector\n");
	for(i=0; i<max; i++)
	{
		printf("%d\t", vector[i]);
	}
	printf("\n");
}

void Shell(tVector vector)
{
	int inter = (max/2);
	int i=0, j=0, k=0, aux;
	
	while(inter > 0)
	{
		for(i=inter; i<max; i++)
		{
			j=i-inter;
			while(j>=0)
			{
				k=j+inter;
				if(vector[j]<=vector[k])
				{
					j--;
				}
				else
				{
					aux=vector[j];
					vector[j]= vector[k];
					vector[k] = aux;
					j=j-inter;
				}
			}
		}
		inter=inter/2;
	}
}

void Intercambio(int* a, int* b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void QuickSort(int* izq, int* der)
{
	if(der < izq)
	return;
	int pivote = *izq;
	int* ult = der;
	int* pri = izq;
	while(izq < der)
	{
	while(*izq <= pivote && izq < der+1)
		izq ++;
	while(*der > pivote && der >izq-1)
		der --;
	
	if(izq < der)
		Intercambio(izq, der);
	}
	Intercambio(pri, der);
	QuickSort(pri, der-1);
	QuickSort(der+1, ult);
}





