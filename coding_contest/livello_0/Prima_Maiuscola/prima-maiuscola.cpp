#include<iostream>
#include<fstream>

using namespace std;

void Prima_maiuscola(string* vett, int n, ostream& out){
    for(int i = 1; i<n; i+=2){
        char tmp = vett[i][0];
        tmp = tmp - 32;
        vett[i][0] = tmp;

        out << vett[i] << " ";
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string* vett = new string[6];
        for(int j = 0; j<6; j++){
            in >> vett[j];
        }

        Prima_maiuscola(vett, 6, out);
        delete [] vett;
    }
}