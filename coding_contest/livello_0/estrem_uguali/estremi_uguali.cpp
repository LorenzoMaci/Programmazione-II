#include<iostream>
#include<fstream>
using namespace std;

void Estremi_uguali(string* vett, int n, ostream& out){
    int counter = 0;

    for(int i = 1; i<n; i+=2){
        //Si poteva fare anche con stoi ma da errore: invalid_argument!
        if(vett[i][0] == vett[i][((vett[i].length())-1)]){
            counter++;
        }
    }
    out << counter << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        //Array per il salvataggio della lunghezza delle stringhe e delle stringhe
        string* vett = new string[6];

        for(int j = 0; j<6; j++){
            in >> vett[j];
        }

        Estremi_uguali(vett, 6, out);
        delete [] vett;
    }
}