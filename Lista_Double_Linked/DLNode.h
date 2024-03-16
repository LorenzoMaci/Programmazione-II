#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

using namespace std;

template<typename T>
class DLNode{
    private:
    T val; //valore
    DLNode<T>* next; //prossimo
    DLNode<T>* prev; //precendente

    template<typename U>
    friend class DLList; //friend class DLList

    public:
    DLNode(T val) : val(val), next(nullptr), prev(nullptr){} //inizializzo val e pongo next e prev a nullptr

    DLNode<T>* getNext() const {return this->next;} //restituisci next
    DLNode<T>* getPrev() const {return this->prev;} //restituisci prev

    friend ostream& operator<<(ostream& out, const DLNode<T>* &node){ //ostream della reference del nodo e il valore prossimo e precendente del nodo
        out << "@node=" << &node << ", node.next=" << node.next << ", node.prev=" << node.prev << endl;
        return out;
    }
};

#endif