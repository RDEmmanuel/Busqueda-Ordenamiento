#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 10

typedef int tVector[max];
tVector vector;

void CargarVector(tVector);
void Visualizar();
int Busqueda(tVector, int);
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
		printf("Ingrese un numero: ");
		scanf("%d", &vector[i]);
	}
	system("pause");
	system("cls");
	Menu();
}

void Visualizar()
{
	int i;
	for(i=0; i<max; i++)
	{
		printf("%d\t", vector[i]);
	}
}

int Busqueda(tVector vector, int numero)
{
	int result = -1;
	int i=0;
	while((vector[i] != numero) && (i != max))
	{
		i = i + 1;
	}
	if(vector[i] == numero)
	{
		result = i;
	}
	return result;
}

void Menu()
{
	int menu;
	printf("---------Busqueda---------\n");
	printf("1-Cargar datos en el vector\n");
	printf("2-Visualizar Vector\n");
	printf("3-Buscar un elemento en el vector\n");
	printf("0-Salir\n");
	printf("Elija una opcion: ");
	scanf("%d", &menu);
	
	while(menu != 0)
	{
		switch(menu)
		{
			case 1:
				{
					CargarVector(vector);
				}break;
				
			case 2:
				{
					Visualizar();
				}break;
				
			case 3:
				{
					int nro;
					printf("Ingrese el numero que desea buscar: ");
					scanf("%d", &nro);
					printf("La posicion del elemento buscado es: %d", Busqueda(vector, nro));
				}break;
		}
		printf("\n\n");
		system("pause\n");
		system("cls\n");
		printf("---------Busqueda---------\n");
		printf("1-Cargar datos en el vector\n");
		printf("2-Visualizar Vector\n");
		printf("3-Buscar un elemento en el vector\n");
		printf("0-Salir\n");
		printf("Elija una opcion: ");
		scanf("%d", &menu);
	}
}































