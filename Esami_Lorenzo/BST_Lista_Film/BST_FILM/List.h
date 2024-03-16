#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Nodo_List.h"

using namespace std;

class List{
    protected:
    Nodo_List* head;
    int size = 0;

    public:
    List(){
        this->head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    Nodo_List* getHead() const{
        return head;
    }

    void insert(string anno, string titolo, string valutazione){
        if(this->isEmpty()){
            head = new Nodo_List(anno, titolo, valutazione);
            size++;
            return;
        }
    }

    void insertHead(string anno, string titolo, string valutazione){
        Nodo_List* temp = new Nodo_List(anno, titolo, valutazione);
        temp->next = head;
        head = temp;
        size++;
    }

    void insertTail(string anno, string titolo, string valutazione){
        if(this->isEmpty()){
            insertHead(anno, titolo, valutazione);
            return;
        }

        Nodo_List* ptr = head;
        while(ptr->getNext() != nullptr){
            ptr = ptr->getNext();
        }

        Nodo_List* temp = new Nodo_List(anno, titolo, valutazione);
        ptr->next = temp;
        size++;
    }


    void insertInOrder(string anno, string titolo, string valutazione){
        if(this->isEmpty()){
            insertHead(anno, titolo, valutazione);
            return;
        }

        if(anno <= head->getAnno()){
            insertHead(anno, titolo, valutazione);
            return;
        }

        Nodo_List* ptr = head;
        while(ptr->getNext() && anno >= ptr->getAnno()){
            if(anno <= ptr->getNext()->getAnno()){
                break;
            }
            ptr = ptr->getNext();
        }

        if(!(ptr->getNext())){
            insertTail(anno, titolo, valutazione);
            return;
        }

        Nodo_List* toInsert = new Nodo_List(anno, titolo, valutazione);
        toInsert->setNext(ptr->getNext());
        ptr->setNext(toInsert);
        size++;
    }

    void removeHead(){
        if(this->isEmpty()){
            cout << "Empty list" << endl;
            return;
        }

        Nodo_List* temp = head;
        head = head->next;
        size--;
        delete temp;
    }

    friend ostream& operator<<(ostream& out,  List& list){
        out << "Lista Film: "<< endl;
        if(list.isEmpty()){
            out << "\tLa lista è vuota" << endl;
            return out;
        }
        else{
            Nodo_List* ptr = list.head;
            while(ptr->getNext() != nullptr){
                out << "\t" << *ptr << endl;
                ptr = ptr->getNext();
            }
            out << "\t" << *ptr << endl;
            return out;
        }
        return out;
    }
};

#endif