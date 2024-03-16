#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;

template<typename T>
class List{
    private:
    Node<T>* head;
    int size = 0;
    bool verbose = false;
    
    public:
    List(bool verbose = true) : verbose(verbose){ head = nullptr;}

    bool isEmpty(){
        return head == nullptr;
    }     

    Node<T>* getHead() const {return head;}

    void insert(T val){
        if(this->isEmpty()){
            head = new Node<T>(val, verbose);
            size++;
            return;
        }
    }

    void insertHead(T val){
        Node<T>* temp = new Node<T>(val, verbose);
        temp->next = head;
        this->head = temp;
        size++; 
    }

    void inserTail(T val){
        if(this->isEmpty()){
            this->insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext() != nullptr){
           ptr = ptr->getNext();
        }

        Node<T>* temp = new Node<T>(val,verbose);
        ptr->next = temp;
        size++;
    }

    void insertInOrder(T val){
        if(this->isEmpty()){
            this->insertHead(val);
        }

        if(val <= head->val){
            this->insertHead(val);
            return;
        }

        Node<T>* ptr = head;
        while(ptr->getNext() && (val >= ptr->val)){
            if(val <= ptr->next->val){
                break;
            }
            ptr = ptr->getNext();
        }
        
        if(!(ptr->next)){
            this->inserTail(val);
            return;
        }

        Node<T>* toInsert = new Node<T>*(val,verbose);
        toInsert->val = ptr->next;
        ptr->next = toInsert;
        size++;
    }

    void RemoveHead(){
        if(this->isEmpty()){
            cout << "Empty list" << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        size--;
        delete temp;
    }

    void RemoveTail(){
        if(this->isEmpty()){
            cout << "Empty list " << endl;
            return;
        }
        
        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        while(cur->next){
            prev = cur;
            cur = cur->next;
        }

        prev->next = nullptr;
        size--;
        delete cur;
    }

    void remove(T val){
        if(this->isEmpty()){
            cout << "Empty List" << endl;
            return;
        }

        if(head->val == val){
            this->RemoveHead();
            return;
        }

        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        while(cur->next && cur->val != val){
            prev = cur;
            cur = cur->next;
        } 

        if(!(cur->next) && cur->val != val){
            cout << "l'elemento con il valore " << val << "non è stato trovato" << endl;
            return;
        }

        prev->next = cur->next;
        size--;
        delete cur;
    }

    Node<T>* search(T val){
        Node<T>* p = head;
        for(p = head; p != nullptr; p = p->next){
            if(p->val == val){
                return p;
            }
        }
        return nullptr;
    }

    friend ostream& operator<<(ostream& out, const List& list){
        if(list.verbose){
            out << "list.head: " << list.head << endl;
            Node<T>* ptr = list.head;
            while(ptr != nullptr){
                out << "\t" <<*ptr << endl;
                ptr = ptr->getNext();
            }
        }else{
            Node<T>* ptr = list.head;
            while(ptr -> getNext() != nullptr){
                out << *ptr << "->";
                ptr = ptr->getNext();
            }
            out << *ptr;
        }
        return out;
    }
};


#endif