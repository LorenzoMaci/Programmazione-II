#include <iostream>
#include "BST.h"
#define DIM 6
using namespace std;

int main(){
    BST<int> bst1;
	BST<char> bst2;

	for(int i=0; i<DIM; i++){
        bst1.insert(rand() % 50);
        bst2.insert(rand() % ('z' - 'a' + 1 ) + 'a');
    }

    //BST interi
    cout << "BST di Interi:" << endl;

    cout << "BST Root: " << endl;
    cout << *(bst1.getRoot()) << endl;
	cout << "\tVisita in order: " << endl;
	bst1.inorder();
    cout << "\n\tDistanza dal successore di 12 : " << bst1.distanz_successor(12) << endl;

    //BST char
    cout << "\nBST di Char:"  << endl;
    cout << "\tBST Root: ";
    cout << *(bst2.getRoot()) << endl;

	cout << "\tVisita in order: " << endl;
	bst2.inorder();
    cout << "\n\tDistanza dal successore di r : " << bst2.distanz_successor('r') << endl;    
}
