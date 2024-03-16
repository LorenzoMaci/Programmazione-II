#include <iostream>

using namespace std;

int swap(int n, int m){
    int temp = n;
    n = m;
    m = temp;
    return temp;
}

int MCM(int n, int m){
    if(n == 0 && m == 0){
        cout << "il mcm(0,0) non è definito" << endl;
    }

    if(n == 0){
        return m;
    }else if(m == 0){
        return n;
    }

    if(n < m){
        swap(n, m);
    }
    return MCM(m, n % m);
}


int main(){
    int n = 36;
    int m = 24;
    cout << MCM(n, m) << endl;
}