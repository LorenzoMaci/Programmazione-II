#include<iostream>
#include<fstream>
using namespace std;

#define DIM 10

#include "list_film.h"
#include "BST_film.h"

int main(){
    ifstream in("input.txt");

    List lista;
    BST bst;

    for(int i = 0; i<DIM; i++){
        string tmp;
        getline(in, tmp);

        string film[3];
        for(int j = 0; j<3; j++){
            film[j] = "";
        }

        int k = 0;      //Variabile per muovermi nell'array
        int l = tmp.length()-1;
        for(int j = 0; j<l; j++){
            if(tmp[j] != ';'){
                film[k] += tmp[j];
            }
            else{
                k++;
            }
        }

        string nome = film[0];
        string anno = film[1];
        string valutazione = film[2];
        //cout << "- nome = " << nome << ", anno = " << anno << ", valutazione = " << valutazione << endl;
    
        lista.insertInOrder(anno, nome, valutazione);
    }

    //Stampa della lista
    cout << lista << endl;

    //Non cancellare, può servire
    // cout << *(lista.getHead()) << endl;
    // cout << lista.getHead()->getNome() << endl;
    // cout << lista.getHead()->getValutazione() << endl;
    // cout << lista.getHead()->getAnno() << endl;

    for(int i = 0; i<DIM; i++){
        bst.Insert(lista.getHead()->getAnno(), lista.getHead()->getNome(), lista.getHead()->getValutazione());
        lista.removeHead();
    }

    cout << "Dopo il trasferimento dalla Lista al BST...\n" << endl;

    //Stampa della bst
    cout << "BST Stampa:" << endl;
    bst.Inorder();

    //Stampa della lista
    cout << endl << lista << endl;
}