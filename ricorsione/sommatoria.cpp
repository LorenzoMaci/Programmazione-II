#include <iostream>
#include <cmath>
using namespace std;

int sommatoria(int n){
    int somma = 0;
    if(n == 1){
        return 1;
    }else{
        for(int i=0; i < n; n--){
            //somma += n; sommatoria di n numeri
            somma += pow(n, 2); //Sommatoria di n numeri al quadrato
        }
    }
    return somma;
}

int main(){
    int n = 3;
    cout << sommatoria(n) << endl;
}