#include <iostream>

using namespace std;


void bubbleSort(int arr[], int n){
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) { //confronto gli elementi e scambio quello > con quello <
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i]<;
  }
  cout << "\n";
}

int main(){
    int data[] = {-2, 45, 0, 11, -9};
  
  // find array's length
  int n = 5;
  
  bubbleSort(data, n);
  
  cout << "Sorted Array in Ascending Order:\n";  
 printArray(data, n);
}
