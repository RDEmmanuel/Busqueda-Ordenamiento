#include <stdlib.h>
#include <stdio.h>

/*funcion para intercambiar los valores de dos elementos*/
void intercambio(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*funcion recursiva quicksort para ordenar el arreglo*/
void quicksort(int* izq, int* der) {
    if (der < izq)
        return;
    int pivote = *izq;
    int* ult = der;
    int* pri = izq;
    while (izq < der) {
        while (*izq <= pivote && izq < der+1)
            izq++;
        while (*der > pivote && der > izq-1)
            der--;
        if (izq < der)
            intercambio(izq, der);
    }
    intercambio(pri, der);
    quicksort(pri, der-1);
    quicksort(der+1, ult);
}

int main(void) {
    int i;
    int tam;

    /*definimos el tama?o del arreglo*/
    printf("Ingrese el tama?o del arreglo:\n");
    scanf("%d", &tam);
    int arreglo[tam];

    /*llenamos el arreglo*/
    printf("Ingrese valores para el arreglo:\n");
    for (i = 0; i < tam; i++)
        scanf("%d", &arreglo[i]);
    printf("\n");

    /*mostramos el arreglo original*/
    printf("Arreglo Original \n");
    for (i = 0; i < tam; i++)
        printf("%d ", arreglo[i]);
    printf("\n");

    /*hacemos el llamado a la funcion quicksort
      para que ordene el arreglo*/
    quicksort(&arreglo[0], &arreglo[tam-1]);

    /*mostramos el arreglo ordenado*/
    printf("Arreglo Ordenado \n");
    for (i = 0; i < tam; i++)
        printf("%d ", arreglo[i]);
    printf("\n\n");
}
