#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef int tVector[max];
tVector vector;

void CargarVector(tVector);
void Visualizar(tVector);
void OrdenacionPorIntercambio(tVector);
int BusquedaBinaria(tVector, int);
void Menu();

int main()
{
	Menu();
	return 0;
}

void CargarVector(tVector vector)
{
	int i;
	for(i=0; i<max; i++)
	{
		printf("Ingrese un valor entero: ");
		scanf("%d", &vector[i]); fflush(stdin);
	}
	printf("Vector Lleno!\n");
}

void Visualizar(tVector vector)
{
	int i;
	printf("Contenido del vector:\n");
	for (i=0; i<max; i++)
	{
		printf("%d\t", vector[i]);
	}
	printf("\n");
}

void OrdenacionPorIntercambio(tVector vector)
{
	int i, j;
	int aux;
	for(i=0; i<max-1; i++)
	{
		for(j=0; j<max-1; j++)
		{
			if(vector[j] > vector[j+1])
			{
				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;
			}
		}
	}
}

int BusquedaBinaria(tVector vector, int nro)
{
	int extSup = max;
	int extInf = -1;
	int posMed;
	int result = -1;
	bool encontrado = false;
	
	while((!encontrado) && (extSup >= extInf))
	{
		posMed = (extInf + extSup) / 2;
		if(nro == vector[posMed])
			encontrado = true;
		else
		{
			if(nro > vector[posMed])
			extInf = posMed + 1;
		else
			extSup = posMed - 1;
		}
	}
	
	if(encontrado)
	{
		result = posMed;
		printf("Se ha encontrado el elemento buscado en el vector!\n");
	}
	else
		printf("No se ha encontrado el elemento buscado en el vector!\n");
		
	return result;
}

void Menu()
{
	int menu;
	printf("Ejercicio 2 Ordenamiento\n");
	printf("1-Cargar Vector\n");
	printf("2-Visualizar Vector\n");
	printf("3-Ordenar Vector\n");
	printf("4-Buscar un elemento en el vector\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &menu);
	printf("\n");
	
	while(menu != 0)
	{
		switch(menu)
		{
			case 1:
				{
					CargarVector(vector);
					system("pause");
					system("cls");
					Menu();
				}break;
			
			case 2:
				{
					Visualizar(vector);
					system("pause");
					system("cls");
					Menu();
				}break;
				
			case 3:
				{
					OrdenacionPorIntercambio(vector);
					printf("Vector luego de la ordenacion por intercambio directo: \n");
					Visualizar(vector);
					system("pause");
					system("cls");
					Menu();
				}break;
				
			case 4:
				{
					int nro;
					printf("Ingrese el Numero que desea buscar en el vector: ");
					scanf("%d", &nro);
					printf("Posicion: %d\n", BusquedaBinaria(vector, nro));
					system("pause");
					system("cls");
					Menu();
				}break;
		}
	printf("Ejercicio 2 Ordenamiento\n");
	printf("1-Cargar Vector\n");
	printf("2-Visualizar Vector\n");
	printf("3-Ordenar Vector\n");
	printf("4-Buscar un elemento en el vector\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &menu);
	printf("\n");
	}
}






