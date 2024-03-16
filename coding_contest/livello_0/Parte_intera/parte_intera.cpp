#include<iostream>
#include<fstream>
using namespace std;

void Parte_intera(double* vett, int n, ostream& out){
    for(int i = 0; i<n; i++){
        int tmp = int(vett[i]);
        vett[i] = tmp;

        out << vett[i] << " ";
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        int n;
        in >> n;

        double* vett = new double[n];
        for(int j = 0; j<n; j++){
            in >> vett[j];
        }

        Parte_intera(vett, n, out);
        delete [] vett;
    }
}