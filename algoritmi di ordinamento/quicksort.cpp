#include <iostream>

using namespace std;

void swap(int& a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort(int arr[], int low, int higth){
    int i = low, j = higth;
    int pivot = arr[(low+higth)/2];

    while( i <= j){
        while (arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if(low < j){
        QuickSort(arr, low, j);
    } 
    if(higth > i){
        QuickSort(arr, i, higth);
    }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);
  
  cout << "Unsorted Array: \n";
  printArray(data, n);
  
  // perform quicksort on data
  QuickSort(data, 0, n - 1);
  
  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
}