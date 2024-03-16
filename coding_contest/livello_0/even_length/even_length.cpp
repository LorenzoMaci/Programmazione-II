#include<iostream>
#include<fstream>
using namespace std;

void Even_length(string n, ostream& out){
    int l = n.length();
    if(l % 2 == 0){
        out << n;
    }
    else{
        for(int i = 0; i<(l-1); i++){
            out << n[i];
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string n;
        in >> n;

        Even_length(n, out);
    }
}