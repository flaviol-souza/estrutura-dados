#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
/* ALGORITMOS DE ORDENAÇÃO INTERNA (por ARRANJADORES) --- Created on Mar 22 2022
 *  AUTHOR : Flavio Souza
 *  DESCRIPTION :
 *       Implementação de algortimos de ordenação interna, por meio de arranjadores (array).
 */
#define MAXTAM 6

struct timeb tmb;

void startWatch()
{
     ftime(&tmb);
}

void stoptWatch(char *txt)
{
    printf("\t");
    printf(txt);
    printf(" - Time (ms): %d\n", tmb.millitm);
}

void selectionSort(int arr[])
{
    int i, j, min, aux;
    startWatch();
    for (i = 0; i < (MAXTAM - 1); i++)
    {
        min = i;
        for (j = i + 1; j < MAXTAM; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
        {
            aux = arr[i];
            arr[i] = arr[min];
            arr[min] = aux;
        }
    }
    stoptWatch("Selection Sort");
}

void bubbleSort(int arr[])
{
    int k, j, aux;
    startWatch();
    for (k = 1; k < MAXTAM; k++)
    {
        for (j = 0; j < MAXTAM - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
    stoptWatch("Bubble Sort");
}

void insertionSort(int arr[])
{
    int i, k, j;
    startWatch();
    for (i = 1; i < MAXTAM; i++)
    {
        k = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
    stoptWatch("Insertion Sort");
}

void mergeSort(int arr[])
{
}

void shellSort(int arr[])
{
}

void quickSort(int arr[])
{
}

void printArray(int arr[])
{
    int i;
    printf("\t");
    for (i = 0; i < MAXTAM; i++)
    {
        printf("%i ", arr[i]);
    }

    printf("\n");
}

int main()
{
    int vetor[MAXTAM] = {64, 7, 25, 12, 22, 11};
    printArray(vetor);
    insertionSort(vetor);
    printf("Sorted array: \n");
    printArray(vetor);

    return 0;
}