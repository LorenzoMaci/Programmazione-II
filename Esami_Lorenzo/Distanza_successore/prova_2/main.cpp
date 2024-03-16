#include <iostream>
#include "BST.h"
#define DIM 10

using namespace std;

int main(){
    BST<int> bst1;
    BST<char> bst2;

    for(int i=0; i<DIM; i++){
        bst1.insert(rand()% 50);
        bst2.insert(rand()%('z' - 'a' + 1) + 'a');
    }

    cout << "BST INTERI: " << endl;

    cout << "BST ROOT:" << endl;
    cout << *(bst1.getRoot()) << endl;
    cout << "\tVisita inOrder:" << endl;
    bst1.inorder();
    cout << "\tDistanza sucessore:" << bst1.distanza_successore(36) << endl;
    cout << "\nBST di Char:"  << endl;
    cout << "\tBST Root: ";
    cout << *(bst2.getRoot()) << endl;

	cout << "\tVisita in order: " << endl;
	bst2.inorder();
    cout << "\n\tDistanza dal successore di r : " << bst2.distanza_successore('r') << endl;
}