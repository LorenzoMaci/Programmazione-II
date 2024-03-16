#include <iostream>
#include <fstream>

using namespace std;

void mantissa(double* arr, int n, ostream& out){
    for(int i=0; i<n; i++){
        int temp = int(arr[i]);
        arr[i] = arr[i] - temp;

        out << arr[i] <<  " ";
    } 
    out << endl;
}

int main(){
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in >> n;

        double* arr = new double[n];
        for(int j=0; j<n; j++){
            in >> arr[j];
        }
        mantissa(arr, n, out);
    }
}