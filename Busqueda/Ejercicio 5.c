#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define fila 2
#define columna 4

typedef float tMatriz[fila][columna];
tMatriz matriz;
float mayor;
float menor;

void CargarMatriz(tMatriz);
void Visualizar();
float Ganador(tMatriz);

int main()
{
	CargarMatriz(matriz);
	Visualizar();
	Ganador(matriz);
	return 0;
}

void CargarMatriz(tMatriz matriz)
{
	int i, j;
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna; j++)
		{
			printf("Ingrese la puntuacion para el participante %d, baile %d: ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
		}
	}
	printf("\n");
	printf("Se cargaron todos las puntuaciones!\n\n");
	system("pause");
	system("cls");
}

void Visualizar()
{
	int i, j;
	for(i=0; i<fila; i++)
	{
		for(j=0; j<columna-1; j++)
		{
			printf("%.1f\t", matriz[i][j]);
		}
		printf("%.1f\n", matriz[i][j]);
	}
	printf("\n");
}

float Ganador(tMatriz matriz)
{
	int i, j;
	float aux, notaFinal, nota, aux2;
	/*mayor=-1;
	menor=9999;*/
	for(i=0; i<fila; i++)
	{
		aux2=0.0;
		aux=0.0;
		mayor=-1;
		menor=9999;
		notaFinal=0.0;
		nota=0.0;
		
		for(j=0; j<columna; j++)
		{
			if(matriz[i][j] > mayor)
			{
				mayor = matriz[i][j];
			}
			else
			{
				if(matriz[i][j] < menor)
				{
					menor = matriz[i][j];
				}
			}
			aux = (aux + matriz[i][j]);
			aux2 = (mayor + menor);
			/*sumaParcial2 = sumaParcial2 + matriz[i][j];*/
			/*nota = aux;*/
			nota = (aux - aux2);
		
		/*if(nota > notaFinal)
			{
				notaFinal = nota;
			}*/
	/*	sumaFinal = sumaParcial;
		sumaFinal2 = sumaParcial2;*/
			
		}
			printf("mayor: %.2f\n", mayor);
			printf("menor: %.2f\n", menor);
			printf("total %.2f\n",aux );
			printf("suma mayor y menor: %.2f\n", aux2);
			printf("Nota final %.2f\n", nota);
			
	}
}
















