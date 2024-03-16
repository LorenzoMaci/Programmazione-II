#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

using namespace std;

template <typename T>
class List{
    protected:
    Node<T>* head; //testa
    int size = 0; //dimenzione  lista
    bool verbose; //condizione

    public:
    List(bool verbose = false) : verbose(verbose){ //iniziallizo verbose = false e pongo head = nullptr
        head = nullptr;
    }

    bool isEmpty(){ 
        return head == nullptr; //se è vuoto la testa è nulla
    }

    Node<T>* getHead() const {return head; } //ritorna la testa costante

    void insert(T val){ //inserisci valore
        if(this->isEmpty()){
            head = new Node<T>(val, verbose); //pongo la testa = a un nuovo nodo
            size++; //Dimenzione aumenta
            return;
        }
    }

    void insertHead(T val){ //inserisci testa
        Node<T>* temp = new Node<T>(val, verbose);//creo un nodo temporaneo
        temp->next = head;//pongo il temp->next = a testa
        this->head = temp; //pongo la testa = temp
        size++;//incremento la dimenzione
    }

    void insertTail(T val){ //coda della lista
        if(this->isEmpty()){ //controllo se la testa è vuota
            this->insertHead(val); //richiamo inserisci testa(val)
            return;
        }

        Node<T>* ptr = head; //pongo il nodo pointer  = alla testa
        while(ptr->getNext() != nullptr){//se ptr->getNext() è != nullptr ptr è uguale al valore succ;
            ptr = ptr->getNext(); //pongo ptr = ptr->getNext()
        } 
        
        Node<T>* temp = new Node<T>(val, verbose); //dichiaro un nodo temporaneo
        ptr->next = temp; //pongo ptr->next = temp;
        size++; //incremento la dimenzione
    }

    void insertInOrder(T val){ //inserimento ordinato

        if(this->isEmpty()){//Controlla se è vuoto
            this->insertHead(val); //richiama inserisci testa(Val)
        }    
        
        if(val <= head->val){ //Se il valore è minore o uguale testa->val
            this->insertHead(val); //richiama  isnersici testa (val)
            return;
        }
        
        Node<T>* ptr = head; //pongo pointer = alla testa
        while(ptr->getNext() && (val >= ptr->val)){ //se il ptr->getNext() && se il valore è >= ptr->val 
            if(val <= ptr->next->val) //se il val  è <= del pointer->successivo->valore
                break; //non fai nulla;

            ptr = ptr->getNext(); //altrimenti ptr = al valore successivo
        }

        if(!(ptr->next)){ //se non c'è alcun valore successivo
            this->insertTail(val); //richiama inserisci coda(Val)
            return;
        }

        Node<T>* toInsert = new Node<T>(val, verbose); //dichiara un node da inserire 
        toInsert->next = ptr->next; //pongo Da inserire->successivo = pointer->successivo;
        ptr->next = toInsert; //pongo il pointer->successivo = da inserire
        size++; //aumenta la dimenzione
    }

    void removeHead(){ //rimuovi la testa
        if(this->isEmpty()){ //controlla se è vuota e scrivi lista vuota
            cout << "Empty list!" << endl;
            return;
        }

        Node<T>* temp = head; //pongo un nodo temporaneo uguale alla testa
        head = head->next; //pongo la testa uguale alla testa->successiva

        size--; //Diminuisce la dimensione 

        delete temp; //rimuovo temp
    }

    void removeTail(){ //rimuovi coda
        if(this->isEmpty()){ //se la lista è vuota scrivi la lista e vuota
            cout << "Empty list!" << endl;
            return;
        }

        Node<T>* cur = head; //pongo il valore attuale = alla testa
        Node<T>* prev = nullptr; //pongo il valore precedente = nullo
        while(cur->next){ //se il valore corrente ha un valore successivo 
            prev = cur; //precedente sarà uguale a attuale
            cur = cur->next; // attuale = attuale->successivo
        }
        prev->next = nullptr; //precedenete->successivo = nullptr
        size--; //decremento la dimensione
        delete cur; //rimuovo attuale
    }   

    void remove(T val){ //richiamo delle funzioni remove
        if(this->isEmpty()){ //cotnrollo se è vuota e scrivo che la lista è vuota
            cout << "Empty list! " << endl;
            return;
        }
        if(head->val == val){ //se head->val è uguale a val
            this->removeHead(); //riciamo rimuovi testa
            return;
        }

        Node<T>* cur = head; //pongo il valore attuale è = alla testa
        Node<T>* prev = nullptr; //pongo il valore precedente è = a nullptr
        while(cur->next && cur->val != val){ //se esiste attuale->prossimo e attuale->valore sono diversi da val
            prev = cur; //precedente è uguale al attuale
            cur = cur->next; //attuale è = al valore successivo
        }

        if(!(cur->next) && cur->val != val){ //se non attuale->successivo e attuale->valore sono diversi da val
            cout << "Element with value " << val << "not found" << endl; // scrivi l'elemento con il valore val non è stato trovato
            return;
        }

        prev->next = cur->next; //il precedente->successivo = attuale->successivo
        size--; //decremento la dimenzione
        delete cur; //rimuovo corrente
    }

    friend ostream& operator<<(ostream& out, const List<T>& list){
        if(list.verbose){
            out << "List head=" << list.head << endl;
            Node<T>* ptr = list.head;
            while(ptr != nullptr){
                out << "\t" << *ptr << endl;
                ptr = ptr->getNext();
            }
        }else{
            Node<T>* ptr = list.head;
            while(ptr->getNext() != nullptr){
                out << *ptr << " ->";
                ptr = ptr->getNext();
            }
            out << *ptr;
        }
        return out;
    }
};

#endif;