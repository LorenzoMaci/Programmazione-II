#include <iostream>
#include <fstream>
#include "Bst.h"

using namespace std;

template<typename S>
void Process_Input(string* vett1, int n, int m, string tipo, ifstream& in, ostream& out){
	S* vett2 = new S[m];
    for(int i = 0; i<m; i++){
        in >> vett2[i];
    }
    
    BST<S> bst;

    S key;

	for(int i = 0; i<n; i++){
        int l = vett1[i].length();

        //Inserimento
        if(vett1[i][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett1[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }

            bst.insert(key);
        }
        //Cancellazione
        else if(vett1[i][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett1[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }

            bst.remove(key);
        }
    }

    //Stampa altezza Nodo
    for(int i = 0; i<m; i++){
        out << bst.livello(vett2[i]) << " ";
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
        for(int i = 0; i<n; i++){
            in >> vett1[i];
        }

		if(tipo == "int"){
			Process_Input<int>(vett1, n, m, tipo, in, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(vett1, n, m, tipo, in, out);
		}
    }
}