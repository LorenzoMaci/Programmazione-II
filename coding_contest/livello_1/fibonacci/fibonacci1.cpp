#include <iostream>
#include <fstream>

using namespace std;


long fibonacci(int n, ostream& out){
    if(n == 0 || n == 1){
        return 1;
    }
    long sum1 = 1, sum2 = 1, x;
    for(int i = 2; i<= n; i++){
        x = sum2;
        sum2 = sum1;
        sum1 = sum2 + x;
    }
    return sum1;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    long arr[61];
    for(int i=0; i<=60; i++){
        arr[i] = fibonacci(i, out);
        cout << "F_array[" << i << "]=" << arr[i] << endl;
    }
    for(int i=0; i<100; i++){
        int n;
        in >> n;

        out << arr[n - 1] << endl;
    }
}