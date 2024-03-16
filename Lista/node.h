#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node{
    T val; //valore
    Node<T>* next; //valore successivo
    bool verbose; //condizione
    
    template <typename U>
    friend class List; //perchè ci servirà per la lista

    public:
    
    Node(T val, bool verbose) : val(val), verbose(verbose){ //inizializzo il valore e la condizione e pongo next = nullptr
        next = nullptr;
    }

    Node<T>* getNext() const{return this->next; } //ritorna il valore  successivo costante

    T& getVal() {return this->val;} //ritrona il valore

    friend ostream& operator<<(ostream& out, const Node<T> &node){
        if(node.verbose){
            out << "node@" << &node << " val="<< node.val << " - next= "<< node.next;
        }else{
            out << "val=" << node.val;
        }
        return out;
    }
};

#endif