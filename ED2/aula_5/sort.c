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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeParticionSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeParticionSort(arr, l, m);
        mergeParticionSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void mergeSort(int arr[])
{
    startWatch();
    mergeParticionSort(arr, 0, MAXTAM-1);
    stoptWatch("Merge Sort");
}

void shellSort(int arr[])
{
    int i, j, value, h = 1;
    startWatch();
    while (h < MAXTAM)
    {
        h = (3 * h) + 1;
    }
    while (h > 0)
    {
        for (i = h; i < MAXTAM; i++)
        {
            value = arr[i];
            j = i;
            while (j > h - 1 && value <= arr[j - h])
            {
                arr[j] = arr[j - h];
                j = j - h;
            }
            arr[j] = value;
        }
        h = h / 3;
    }
    stoptWatch("Shell Sort");
}

void quickSortRecursive(int arr[], int left, int right)
{
    int i, j, x, y;

    i = left;
    j = right;
    x = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < x && i < right)
        {
            i++;
        }
        while (arr[j] > x && j > left)
        {
            j--;
        }
        if (i <= j)
        {
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        quickSortRecursive(arr, left, j);
    }
    if (i < right)
    {
        quickSortRecursive(arr, i, right);
    }
}

void quickSort(int arr[])
{
    startWatch();
    quickSortRecursive(arr, 0, MAXTAM);
    stoptWatch("Quick Sort");
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
    mergeSort(vetor);
    printf("Sorted array: \n");
    printArray(vetor);
    return 0;
}