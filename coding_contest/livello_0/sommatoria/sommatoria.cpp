#include <iostream>
#include <fstream>

using namespace std;

double sommatoria(double arr[], int n, ostream& out){
    double somma = 0.0;
    for(int i=0; i<n; i++){
        somma += arr[i];

    }
    return somma;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        double* arr = new double[n];
        for(int j=0; j<n; j++){
            in >> arr[j];
        }
        out << sommatoria(arr, n, out) << endl;
    }
}