#include <iostream>
using namespace std;

void swap(int &a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n){
    int indiceMin;
    for(int i=0; i<n; i++){
        indiceMin = i;
        cout <<"indiceMin i: " <<  indiceMin << endl;
        for(int j= i+1; j<n; j++){
            if(arr[j] < arr[indiceMin]){
                indiceMin = j;
                cout << "indiceMin j: " << indiceMin << endl;
            }
        }
        swap(arr[i], arr[indiceMin]);
    }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int main(){
    int arr[] = {4, 8, 2, 1, 5, 7};
    int n = 6;
    selectionSort(arr,n);
    cout << "l'array ordinato è: " << endl;
    printArray(arr, n);
}