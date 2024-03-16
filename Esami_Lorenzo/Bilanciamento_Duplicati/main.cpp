#include <iostream>

#include "BST2.h"

using namespace std;

int main(){
    BST<int> bst;

    cout << "Prima: counter = " << counter << endl << endl;

    bst.insert(12);
    bst.insert(34);
    bst.insert(15);
    bst.insert(23);
    bst.insert(76);
    bst.insert(23);
    bst.insert(83);
    bst.insert(15);
    bst.insert(76);
    bst.insert(8);
    bst.insert(2);
    bst.insert(8);
    bst.insert(8);

    bst.inorder();

    cout  << endl << endl << "Dopo: counter = " << counter << endl;

    BST<char> bst1;
    bst1.insert('c');
    bst1.insert('c');
    bst1.insert('z');
    bst1.insert('a');
    bst1.insert('l');
    bst1.insert('e');
    bst1.insert('i');

    cout << "post counter: "<< counter << endl;
    bst1.inorder();
    cout << endl;
}