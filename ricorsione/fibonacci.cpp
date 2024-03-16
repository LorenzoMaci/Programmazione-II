#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci (n -2);
}

int fibonacciIterattivo(int n){
    if(n == 0 || n == 1)
        return 1;
    int sum1 = 1, sum2 = 1, x;
    for(int i = 2, i<= n; i++){
        x = sum2;
        sum2 = sum1;
        sum1 = x + sum2;
    }
    return sum1;
}
int main(){
    int fib5 = fibonacci(5);
    cout << "fibonacci numero 5 è: " << fib5 << endl;
}