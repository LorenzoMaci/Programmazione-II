#include <fstream>
#include <iostream>
#include "Bst.h"

using namespace std;

template <typename S>
void Process_Input(string* vett1, int n, int m,  string tipo, ifstream& in, ostream& out){
    S* vett2 = new S[m];
    for(int j = 0; j<m; j++){
        in >> vett2[j];

    }

    BST<S> bst;

    S key;

    //Vado a fare gli inserimenti e le cancellapioni
    for(int j = 0; j<n; j++){
        int l = vett1[j].length();

        //Inserimento
        if(vett1[j][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett1[j][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else{
                key = stod(tmp);
            }   
            bst.insert(key);
        }
        //Cancellapione
        else if(vett1[j][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett1[j][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else{
                key = stod(tmp);
            }         
            bst.remove(key);
        }
    }

    //Stampa Successore
    for(int j = 0; j<m; j++){
        if(bst.successor(vett2[j]) == nullptr){
            out << "-1 ";
        }
        else{
            out << bst.successor(vett2[j])->getKey() << " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        int m;
        in >> m;

        string* vett1 = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett1[j];
        }

        if(tipo == "int"){
            Process_Input<int>(vett1, n, m, tipo, in, out);
        }
        else if(tipo == "double"){
            Process_Input<double>(vett1, n, m, tipo, in, out);
        }
    }
}