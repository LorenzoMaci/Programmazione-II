#include <iostream>
#include <fstream>

using namespace std;

void conteggio(int arr[], int n, int pivot_x, ostream& out){
    int counter = 0;
    for(int i=0; i<n; i++){
        if(arr[i] > pivot_x){
            counter++;
        }
    }
    out << counter << " ";
}

void maggiore(int arr[], int n, int pivot_x, ostream& out){
    for(int i=0; i<n; i++){
        if(arr[i] > pivot_x){
            out << arr[i] <<  " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    for(int i=0; i<100; i++){
        int n;
        int X;
        in >> n;
        in >> X;

        int* arr = new int[n];
        for(int j=0; j<n; j++){
            in >> arr[j];
        }
        conteggio(arr, n, X, out);
        maggiore(arr, n, X, out);
    }

}