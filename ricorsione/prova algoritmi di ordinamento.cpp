/************** PROVA ALGORITMI DI ORDINAMENTO **************/
//This is NOT coded by Helias
#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 10

using namespace std;

/**INSERTION SORT**/
void insertionSort(int a[])
{
    int tmp;
    int j;

    for(int i = 1; i < MAX; i++ )
    {
        tmp = a[i];
        j = i-1;

        while(j >= 0 && a[j] > tmp)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = tmp;
    }
}

/**SELECTION SORT**/
void selectionSort(int a[])
{
    int min;
    int temp;

    for( int i = 0; i < MAX-1; i++)
    {
     min = i;
     for( int j = i+1; j < MAX; j++)
         if(a[j] < a[min])
             min = j;

    temp = a[min];
    a[min] = a[i];
    a[i] = temp;
    }
}

/**BUBBLE SORT**/
void bubbleSort(int a[])
{
    int tmp;

    for(int i = 0; i < MAX-1; i++)
    {
        for(int j = 0; j < MAX-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
              tmp = a[j];
              a[j] = a[j+1];
              a[j+1] = tmp;
            }
        }
    }
}

/**MERGE SORT**/
void merge(int a[], int left, int center, int right)
{
    int b[MAX];
    int i = left, j = center+1, k = left;

    while(i <= center && j <= right)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= center)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j <= right)
    {
        b[k] =a [j];
        j++;
        k++;
    }
    for(k = left; k <= right; k++)
        a[k] = b[k];
}

void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int center = (left + right)/2;
        mergeSort(a, left, center);
        mergeSort(a, center+1, right);
        merge(a, left, center, right);
    }
}

/**QUICK SORT**/
void quickSort(int a[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = a[(left+right)/2];

    /*partition*/
    while( i <= j)
    {
        while(a[i] < pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i <= j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    if(left < j)
        quickSort(a, left, j);
    if(right > i)
        quickSort(a, i, right);
}

int main()
{
    int a[MAX] = { 0 };
    srand(time(NULL));

    for(int i = 0; i < MAX; i++)
        a[i] = (rand() % 100 + 1)*-1;

    int scelta;

    cout << "Array da ordinare: ";
    for (int i = 0; i < MAX; i++)
        cout << a[i] << " ";

    cout << "\n\nScegli l'algoritmo di ordinamento:\n";
    cout << "1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Merge Sort\n5.Quick Sort\n\n";

    do
        cin >> scelta;
    while(scelta < 1 || scelta > 5);

    switch(scelta)
    {
    case 1:
        cout << "\nINSERTION SORT\n";
        insertionSort(a);

        for (int i = 0; i < MAX; i++)
            cout << a[i] << " ";

        break;
    case 2:
        cout << "\nSELECTION SORT\n";
        selectionSort(a);

        for (int i = 0; i < MAX; i++)
            cout << a[i] << " ";

        break;
    case 3:
        cout << "\nBUBBLE SORT\n";
        bubbleSort(a);

        for (int i = 0; i < MAX; i++)
            cout << a[i] << " ";

        break;
    case 4:
        cout << "\nMERGE SORT\n";
        mergeSort(a, 0, MAX-1);

        for (int i = 0; i < MAX; i++)
            cout << a[i] << " ";

        break;
    case 5:
        cout << "\nQUICK SORT\n";
        quickSort(a, 0, MAX-1);

        for (int i = 0; i < MAX; i++)
            cout << a[i] << " ";

        break;
    }

    cout << "\nVuoi riprovare? 1 = si, 0 = no\n";

    do
        cin >> scelta;
    while(scelta < 0 || scelta > 1);

    if(scelta == 1)
        main();

    return 0;
}
