#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define fila 5
#define columna 4

typedef int tMatriz[fila][columna];
tMatriz matriz;

void CargarMatriz(tMatriz);
void Visualizar();
int Maximo(tMatriz);
int Minimo(tMatriz);

int main()
{
	CargarMatriz(matriz);
	Visualizar();
	Maximo(matriz);
	Minimo(matriz);
	return 0;
}


void CargarMatriz(tMatriz matriz)
{
	int i, j;
	/*se cargan los datos primero por columna y luego por fila*/
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna; j++)
		{
			printf("Ingrese valor para la posicion: %d,%d\n", i+1, j+1);
			scanf("%d", &matriz[i][j]);			
		}
	}
	printf("\n");
	printf("Matriz Llena!\n\n");
	system("pause");
	system("cls");
}

void Visualizar()
{
	int i, j;
	printf("Elementos de la matriz: \n");
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna-1; j++)
		{
			printf("%d\t", matriz[i][j]);			
		}
		printf("%d\n", matriz[i][j]);
	}
	printf("\n");
}

int Maximo(tMatriz matriz)
{
	int i, j;
	int aux=0;
	int posicionF, posicionC;
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna; j++)
		{
			if(matriz[i][j] > aux)
			{
				aux = matriz[i][j];
				posicionF = i+1;
				posicionC = j+1;
			}						
		}
	}
	printf("El valor maximo de la matriz es: %d\t", aux);
	printf("En la posicion %d,%d\n", posicionF, posicionC);
	return aux;
}

int Minimo(tMatriz matriz)
{
	int i, j;
	int aux=999999;
	int posicionF, posicionC;
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna; j++)
		{
			if(matriz[i][j] < aux)
			{
				aux = matriz[i][j];
				posicionF = i+1;
				posicionC = j+1;
			}						
		}
	}
	printf("El valor minimo de la matriz es: %d\t", aux);
	printf("En la posicion %d,%d", posicionF, posicionC);
	return aux;
}




