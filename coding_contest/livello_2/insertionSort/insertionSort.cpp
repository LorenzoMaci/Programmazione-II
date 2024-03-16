#include <iostream>
#include <fstream>

using namespace std;

int insertionSort(int* arr, int n){
    int counter = 0;
    int temp, j;
    for(int i=1; i<n; i++){
        temp = arr[i];
        for(j = i; j>0; j--){
            if(temp < arr[j - 1]){
                arr[j] = arr[j - 1];
                counter++;
            }else{
                break;
            }
        }
        arr[j] = temp;
    }
    return counter;
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

        out << insertionSort(arr, n) << endl;
        delete [] arr;
    }
}