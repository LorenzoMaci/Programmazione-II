#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>
#include "DLNode.h"

using namespace std;

template<typename T>
class DLList{
    protected:
    DLNode<T>* head; //testa
    DLNode<T>* tail; //coda
    public:
    DLList() : head(nullptr), tail(nullptr){} //pongo testa e coda = nullptr

    bool isEmpty(){ //controllo se la lista è vuota vedendo se la testa e la coda sono = nullptr
        return (head == nullptr) && (tail == nullptr);
    }
    
    void insertHead(T val){ //inserisci testa
        if(this->isEmpty()){ //controlla se la lista è vuota, poni la testa uguale al nuovo DLNode<T>(val), la coda = alla testa e return
            head = new DLNode<T>(val); 
            tail = head;
            return;
        }
        DLNode<T>* toInsert = new DLNode<T>(val); //dichiara un nuovo nodo da inserire e lo poni uguale al NUOVO DLNode<T>(val)
        toInsert->next = head; //inserisici->prossimo = testa
        head->prev = toInsert; //la testa precendentte = inserisci
        head = toInsert; //testa = inserisci
    }

    void insertTail(T val){ //inserisci coda
        if(this->isEmpty()){ //se la coda è vuota inserisci nella testa(val) e return
            this->insertHead(val);
            return;
        }

        DLNode<T>* toInsert = new DLNode<T>(val); //dichiara un nuovo nodo da inserire e lo poni uguale al New DLNode<T>(val)
        toInsert->prev = tail; //inserisci->precedente = code
        tail->next = toInsert; //coda->prossimo = inserisci 
        tail = toInsert; //coda = inserisci
    }

    void removeHead(){ //rimuovi testa
        if(this->isEmpty()){ //se la lista è vuota scrivi la lista è vuota e fai return
            cout << "Empty List "<< endl;
            return;
        }
        if(head == tail){ //se la testa è uguale alla coda, dichiara un Nodo Pointer e lo poni uguale alla testa, poni la testa e la coda = nullptr e rimuovi pointer
            DLNode<T>* ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
            return;  //return
        }

        DLNode<T>* ptr = head; //Dichiaro un DLNode pointer e lo pongo uguale alla testa
        ptr->next->prev = nullptr; //pongo il valore prossimo e precedente di pointer = nullptr
        head = ptr->next; //pongo la testa = al valore prossimo di pointer 
        delete ptr; //rimuovi pointer
    }

    void removeTail(){ //rimuovi coda
        if(this->isEmpty()){ //se la lista è vuota, scrivi la lista è vuota e fai return
            cout << "Empty list "<< endl;
            return;
        }
        if(head == tail){ //se la testa è uguale alla coda
            DLNode<T>* ptr = head; //dichiaro un DLNode pointer e lo pongo uguale alla testa 
            head = nullptr; //pongo la testa e la coda = nullptr
            tail = nullptr;
            delete ptr; //rimuovo pointer
        }

        DLNode<T>* ptr = tail; //dichiaro un DLNode<T> pointer e lo pongo uguale alla coda
        ptr->prev->next = nullptr; //pongo il prossimo e precedente valore di pointer = nullptr
        tail = ptr->prev; // pongo la coda = precedente valroe di pointer
        delete ptr; //rimuovo pointer
    }
};

#endif