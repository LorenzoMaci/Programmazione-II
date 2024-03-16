#include <iostream>
#include <fstream>
#define DIM 10000

using namespace std;

void minori(int arr[], int n, ostream& out){
    int min = 999999;
    for(int i=0; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    out << min << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<100; i++){
        int* arr = new int[DIM];
        string temp;
        in >> temp;
        
        int j = 0;
        while(temp != "STOP"){
            int val = stoi(temp);
            arr[j] = val;
            j++;
            in >> temp;
        }
        minori(arr, j, out);
        delete [] arr;
    }
}