#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Nodo_List.h"
using namespace std;

class List{
    private:
    Nodo_List* head;
    int size = 0;

    public:
    List() {
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    Nodo_List* getHead(){
        return this->head;
    }

    void insert(string anno, string titolo, string valutazione){
        if(this->isEmpty()){
            head = new Nodo_List(titolo, anno, valutazione);
            return;
        }
    }

    void insertHead(string anno, string titolo, string valutazione){
        Nodo_List* temp = new Nodo_List(anno, titolo, valutazione);
        temp->next = head;
        head = temp;
        return;
    }

    void insertTail(string anno, string titolo, string valutazione){
        if(this->isEmpty()){
            insertHead(anno, titolo, valutazione);
            return;
        }

        Nodo_List* p = head;
        while(p->getNext() != nullptr){
            p = p->getNext();
        }

        Nodo_List* temp = new Nodo_List(anno, titolo, valutazione);
        p->next = temp;
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

        Nodo_List* p = head;
        while(p->getNext() && (anno >= p->getAnno())){
            if(anno <= p->getNext()->getAnno()){
                break;
            }
            p = p->getNext();
        }

        if(!(p->getNext())){
            this->insertTail(anno, titolo, valutazione);
        }

        Nodo_List* toInsert = new Nodo_List(anno, titolo, valutazione);
        toInsert->setNext(p->getNext());
        p->setNext(toInsert);
        size++;
    }

    void removeHead(){
        if(this->isEmpty()){
            cout << "Empty list:" << endl;
            return;
        }

        Nodo_List* temp = head;
        head = head->next;

        size--;

        delete temp;
    }


    friend ostream& operator<<(ostream& out, List& list){
        out << "lista film:" << endl;
        if(list.isEmpty()){
            out << "\tLa lista è vuota " << endl;
            return out;
        }else{
            Nodo_List* p = list.head;
            while(p->getNext() != nullptr){
                out << "\t" << *p << endl;
                p = p->getNext();
            }
            out << "\t" << *p << endl;
            return out;
        }
        return out;
    }
};

#endif