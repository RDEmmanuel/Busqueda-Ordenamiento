#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int	max;
typedef float tVector[1];
tVector vector;

void CargarVector(tVector);
float Mayor(tVector);
float Menor(tVector);
void Visualizar();
float Media(tVector);
float SemiSuma(tVector);

int main()
{
	CargarVector(vector);
	Visualizar();
	printf("El valor Maximo es: %.2f\n", Mayor(vector));
	printf("El valor Minimo es: %.2f\n", Menor(vector));
	printf("La media de todos los valores es: %.2f\n", Media(vector));
	printf("La semisuma de los valores (mayor y menor) es: %.2f\n", SemiSuma(vector));
	
	return 0;
}

void CargarVector(tVector vector)
{	
	int i;	
	printf("Ingrese la cantidad de elementos del vector(tamanio): ");
	scanf("%d", &max);
	for(i=0; i<max; i++)
	{
		printf("Ingrese valores para el vector: ");
		scanf("%f", &vector[i]);
	}
	printf("\n");
	printf("Vector Lleno!\n");
	system("pause");
	system("cls");
}

float Mayor(tVector vector)
{
	int i;
	float aux=0;
	for(i=0; i<max; i++)
	{
		if(vector[i] > aux)
		{
			aux = vector[i];
		}
	}	
	return aux;
}

float Menor(tVector vector)
{
	int i;
	float aux=9999;
	for(i=0; i<max; i++)
	{
		if(vector[i] < aux)
		{
			aux = vector[i];
		}
	}	
	return aux;
}

void Visualizar()
{
	int i;
	printf("Elementos del vector: \n");
	for(i=0; i<max; i++)
	{
		printf("%.2f\n", vector[i]);
	}
}

float Media(tVector vector)
{
	int i;
	float sumaTotal=0;
	float aux;
	for(i=0; i<max; i++)
	{
		sumaTotal = sumaTotal + vector[i];
	}
	aux = (sumaTotal / max);
	return aux;
}

float SemiSuma(tVector vector)
{
	int i;
	float maximo=0; 
	float minimo=9999;
	float aux;
	for(i=0; i<max; i++)
	{
		if(vector[i] < minimo)
		{
			minimo = vector[i];
		}
		else 
		{
			if(vector[i] > maximo)
		{
			maximo = vector[i];
		}
		}
	}
	aux = (maximo + minimo) / 2;
	return aux;
}







