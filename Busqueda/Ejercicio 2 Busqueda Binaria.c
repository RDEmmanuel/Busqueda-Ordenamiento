#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 4

typedef float tVector[max];
tVector vector;

void CargarVector();
int BusquedaBinaria(tVector, float);

int main()
{
	float nro;
	CargarVector();
	printf("Ingrese el Numero que desea buscar: ");
	scanf("%f", &nro);
	printf("Posicion: %d", BusquedaBinaria(vector, nro));
	
	return 0;
}

void CargarVector()
{
	int i;
	for(i=0; i<max; i++)
	{
		printf("ingrese valores flotantes de forma ascendente: ");
		scanf("%f", &vector[i]);
	}
	printf("\n");
	printf("Vector Lleno!\n");
	system("pause");
	system("cls");
}

int BusquedaBinaria(tVector vector, float nro)
{
	int extInf, extSup;
	int posMed;
	int result = -1;
	bool encontrado = false;
	extInf = -1;
	extSup = max;
	
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
	printf("Encontrado: true\n");
}
else
	printf("Encontrado: false\n");
	
return result;

}



















