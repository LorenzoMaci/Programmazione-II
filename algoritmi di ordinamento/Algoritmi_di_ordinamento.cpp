#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;
//Selection Sort

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int arr[], int n){
    int indiceMin;

    for(int i=0; i<n; i++){
        indiceMin = i;
        for(int j= i + 1: j<n; j++){
            if(arr[j] < arr[indiceMin]){
                indiceMin = j;
            }           
        }
        swap(arr[i], arr[indiceMin]);
    }
}


//Insertion Sort
void InsertionSort(int arr[], int n){
    int temp, j;
    for(int i = 1; i<n; i++){
        temp = arr[i];
        for(j = i; j > 0; j--){ //for che controlla il sottoarray
            if(temp < arr[j - 1]){//scorriamo tutti gli elementi > i verso sinistra
                arr[j] = arr[j - 1];
            }else{
                break;
            }
        }
        arr[j] = temp;
    }
}

//BubleSort

void bubbleSort(int arr[], int n) {
    bool found = true;
    for (int i = 0; i < n -1 && found; i++) {
        found = false //perchè non è stato effettuato alcuno scambio
        for (int j = 0; j < n - i -1; j++) {
            if (arr[i] > arr[i + 1]) { //confronto gli elementi e scambio quello > con quello <
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


//MergeSort
void merge(int arr[], int p, int q, int r){
    // p <= q <= r
    int n1 = q-p+1; //sottoarray sinistra
    int n2 = r-q; //sottoarray di destra
    cout << "Indici: " << p << " "<< q << " " << r << endl;
    //creo i sottoarray
    int* L = new int[n1+1]; 
    int* R = new int[n2+1];

    for(int i=0; i<n1; i++){
        L[i] = arr[p+i];
    }
    for(int j=0; j < n2; j++){
		R[j] = arr[q+j+1];
    }

    L[n1] = INT_MAX; 
    R[n2] = INT_MAX;

    int i=0, j = 0, k = p;
    for(k = p; k<= r; k++){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
    }
    delete[] L, R;
}

void mergesort(int arr[], int p, int r) {
	if(p < r) {
		int q = floor((p+r)/2.0);
		mergesort(arr, p, q);
		mergesort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}