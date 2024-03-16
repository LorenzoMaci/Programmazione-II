#include <iostream>
#include "list2.h"
using namespace std;

int main(){
    List<int> list;
    
    list.insert(12);
    list.insert(15);
    list.insert(1);
    list.insert(3);
    list.insert(8);
    list.insert(10);
    list.insert(5);
    list.insert(13);

    cout << list << endl;

    list.remove(3);
    cout << "La lista con rimosso un elemento è:" << endl;
    cout << list << endl;
    list.inserTail(9);
    cout << list << endl;
    int x;
    cout << "Ricerca di un elemento: " << endl;
    cin >> x;
    Node<int>* p;
    p = list.search(x);
    if(p != nullptr){
        cout << "l'elemento " << x << " è presente in lista" << endl;
    }
}