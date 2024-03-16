#include<iostream>
#include<fstream>
using namespace std;

void Seleziona_nome(string* vett, int n, char A, char B, ostream& out){
    for(int i = 1; i<n; i+=2){
        string nome = vett[i];
        int ultimo_carattere = (nome.length())-1;

        if(nome[0] == A && nome[ultimo_carattere] == A){
            out << nome << " ";
        }
        else if(nome[0] == A && nome[ultimo_carattere] != B){
            out << nome << " ";
        }
        else if(nome[0] != B && nome[ultimo_carattere] == A){
            out << nome << " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        char A;
        in >> A;

        char B;
        in >> B;

        string* vett = new string[6];
        for(int j = 0; j<6; j++){
            in >> vett[j];
        }

        Seleziona_nome(vett, 6, A, B, out);
        delete [] vett;
    }
}