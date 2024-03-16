#include <iostream>

using namespace std;

int LinearySearch(int arr[], int n, int key){
    for(int i=0; i<n; i++){
        if(arr[i == key]){
            return i;
        }
    }
    return -1;
}

bool BinarySearch(int arr[], int n, int key){
    bool found = false;

    int start = 0;
    int end = n;
    //utilizziamo il ciclo while perchè non sappiamo il numeri di iterazioni da dover fare
    while(!found && (start != end)){
        int midpoint =(start + end)/2;

        if(arr[midpoint] == key){
            found = true;
        }else if(key < arr[midpoint]){ //considero la metà inferiore
            end = midpoint; //midpoint = (end-start)/2
        }else{ //considera la metà superiore
            start = midpoint +1;
        }
    }
    return found;
}