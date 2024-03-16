#include <iostream>
#include <fstream>

using namespace std;

void importo(int* arr1, int n, int* arr2, int m, ostream& out){
    int importo = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr1[i] == arr2[j]){
                importo += 5;
            }
        }
    }
    out << importo << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int n;
        in >> n;

        int m; 
        in >> m;

        int* arr1 = new int[n];
        for(int j=0; j<n; j++){
            in >> arr1[j];
        }

        int* arr2 = new int[m];
        for(int j=0; j<m; j++){
            in >> arr2[j]; 
        }

        importo(arr1, n, arr2, m, out);
    }
}