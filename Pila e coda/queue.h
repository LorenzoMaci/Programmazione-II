#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include "DLList.h"

using namespace std;

template<typename T>
class Queue : protected DLList<T>{ 
    protected:
    int size = 0; //dimenzione
    public:
    Queue() : DLList<T>(){} //costruttore

    void enqueue(T val){ //inserisci l'elemento nella collonna della lista e incrementa la dimenzione 
        DLList<T>::insertTail(val); 
        size++; 
    }

    DLNode<T> dequeue(){ //se la lista è vuota restituisci zero
        if(isEmpty()){
            return 0;
        }
        DLNode<T>* ptr = *(DLList<T>::head); //Dichiaro un DLNode pointer e lo pongo = alla testa di DLList
        DLList<T>::removeHead(); //rimuovo la testa della lista
        size--;
        return ptr; //restituisci ptr
    }

    bool isEmpty(){ //se è vuota restituisci la dimenzione = 0;
        return size == 0;
    }

    friend ostream& operator<<(ostream& out,  Queue<T>& queue){
        out << "Queue.head= " <<&(queue.head);
        DLNode<T>* ptr = queue.head;
        while(ptr){
            out << *ptr << endl;
            ptr = ptr->getNext();
        }
        return out;
    }
};

#endif