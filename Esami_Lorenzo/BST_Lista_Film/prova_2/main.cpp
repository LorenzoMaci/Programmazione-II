#include <iostream>
#include <fstream>

using namespace std;

#define DIM 10

#include "List.h"
#include "bst.h"

int main(){
    ifstream in("input.txt");

    List lista;
    BST bst;

    for(int i=0; i<DIM; i++){
        string s;
        getline(in, s);

        string film[3];
        for(int j=0; j<3; j++){
            film[j] = "";
        }

        int k = 0;
        int l = s.length() - 1;
        for(int j=0; j<l; j++){
            if(s[j] != ';'){
                film[k] += s[j];
            }else{
                k++;
            }
        }

        string nome = film[0];
        string anno = film[1];
        string valutazione = film[2];

        lista.insertInOrder(anno, nome, valutazione); 
    }

    cout << lista << endl;

    for(int i=0; i<DIM; i++){
        bst.insert(lista.getHead()->getAnno(), lista.getHead()->getTitolo(), lista.getHead()->getValutazione());
        lista.removeHead();
    }

    cout << "Trasferimento nel Bst:" << endl << endl;

    cout << "BST Stampa:" << endl;
    bst.inorder();

    cout << "Lista vuota" << endl;
    cout << endl << lista << endl;
}