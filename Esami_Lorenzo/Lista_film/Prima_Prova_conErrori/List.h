#include <iostream>
#include "Nodo.h"

using namespace std;

class List{
    protected:
    int size = 0;
    Nodo* head;

    public:
    List(){
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    Nodo* getHead(){
        return this->head;
    }

    void insert(string proiezione, string titolo, string genere){
        if(this->isEmpty()){
            head = new Nodo(proiezione, titolo, genere);
            size++;
            return;
        }
    }

    void insertHead(string proiezione, string titolo, string genere){
        Nodo* temp = new Nodo(proiezione, titolo, genere);
        temp->next = head;
        head = temp;
        return;
    }

    void insertTail(string proiezione, string titolo, string genere){
        if(this->isEmpty()){
            this->insertHead(proiezione, titolo, genere);
            return;
        }

        Nodo* p = head;
        while(p->getNext() != nullptr){
            p = p->getNext();
        }

        Nodo* temp = new Nodo(proiezione, titolo, genere);
        p->next = temp;
        size++;
    }

    void insertInOrder(string proiezione, string titolo, string genere){
        if(this->isEmpty()){
            this->insertHead(proiezione, titolo, genere);
            return;
        }

        if(proiezione <= head->getProiezione()){
            this->insertHead(proiezione, titolo, genere);
            return;
        }

        Nodo* p = head;
        while(p->getNext() && (proiezione >= p->getProiezione())){
            if(proiezione <= p->getNext()->getProiezione()){
                break;
            }
            p = p->getNext();
        }

        if(!(p->getNext())){
            this->insertTail(proiezione, titolo, genere);
            return;
        }

        Nodo* toInsert = new Nodo(proiezione, titolo, genere);
        toInsert->setNext(p->getNext());
        p->setNext(toInsert);
        size++;
    }

void film_piu_nuovo(){
		Nodo *ptr = getHead();
		while(ptr != nullptr) {
			if(ptr->getNext() == nullptr){
				cout << "Il film più nuovo è: " << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
	}

	void film_piu_vecchio(){
		Nodo *ptr = getHead();
		cout << "Il film più vecchio è: " << *ptr << endl;
	}

    void film_dato_un_genere(string genere){
		Nodo *ptr = getHead();
		cout << "I film di genere " << genere << " presenti in lista sono:" << endl;
		while(ptr != nullptr) {
			if(genere == ptr->getGenere()){
				cout << "\t" << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
		cout << endl;
	}

    friend ostream& operator<<(ostream& out, const List& list){
        out << "Lista film: " << endl;
        Nodo* ptr = list.head;
        while(ptr->getNext() != nullptr){
            out << "\t" << *ptr << endl;
            ptr = ptr->getNext();
        }
        out << "\t" << *ptr << endl;
        return out;
    }
};

