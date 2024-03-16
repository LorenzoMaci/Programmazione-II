#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int selectionSort(int arr[], int n){
    int indiceMin;
    int somma = 0;
    for(int i=0; i<n; i++){
        indiceMin = i;
        for(int j= i + 1; j<n; j++){
            if(arr[j] < arr[indiceMin]){
                indiceMin = j;
            }
        }
        somma += indiceMin - i;
        swap(arr[i], arr[indiceMin]);
    }
    return somma;
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in >> n;

        int* arr = new int[n];
        for(int j=0; j<n; j++){
            in >> arr[j];
        }
        out << selectionSort(arr, n) << endl;
        delete [] arr;
    }
}