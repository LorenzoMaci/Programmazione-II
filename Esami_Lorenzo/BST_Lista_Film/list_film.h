#ifndef LIST_FILM_H
#define LIST_FILM_H

#include<iostream>
#include "node_film.h"

using namespace std;

class List {
	protected:
	Node* head;
	int size = 0;
	
	public:
	
	List(){
		head = nullptr;
	}
	
	bool isEmpty() {
		return head == nullptr;
	}
	
	Node* getHead() const{ 
		return head; 
	}
	
	void insert(string anno, string nome, string valutazione){
		if(this->isEmpty()) {
			head = new Node(anno, nome, valutazione);
			size++;
			return;
		}
	}
	
	void insertHead(string anno, string nome, string valutazione){	
		Node* temp = new Node(anno, nome, valutazione);
		temp->next = head;
		this->head = temp;
		size++;
	}
	
	void insertTail(string anno, string nome, string valutazione){
		if(this->isEmpty()){
			this->insertHead(anno, nome, valutazione);
			return;
		}
		
		Node* p = head;
		while(p->getNext() != nullptr){
			p = p->getNext();
		}
		
		Node* temp = new Node(anno, nome, valutazione);
		p->next = temp;
		size++;
	}
	
	void insertInOrder(string anno, string nome, string valutazione){
		
		if(this->isEmpty()){
			this->insertHead(anno, nome, valutazione);
			return;
		}
		if(anno <= head->getAnno()){
			this->insertHead(anno, nome, valutazione);
			return;
		}
		
		Node* p = head;
		while(p->getNext() && (anno >= p->getAnno())){
			
			if(anno <= p->getNext()->getAnno())
				break;
			
			p = p->getNext();
		}
		
		if(!(p->getNext())){
			this->insertTail(anno, nome, valutazione);
			return;
		}
		
		Node* toInsert = new Node(anno, nome, valutazione);
		toInsert->setNext(p->getNext());
		p->setNext(toInsert);
		size++;
			
	}

	void removeHead() {
		if(this->isEmpty()) {
			cout << "Empty list!" << endl;
			return;
		}
		
		Node* temp = head;
		head = head->next;
		
		size--;
		
		delete temp;
	}
	
	friend ostream& operator<<(ostream& out, List &list) {
		out << "Lista Film:" << endl;
		if(list.isEmpty()){
			out << "\tLa Lista è vuota!" << endl;
			return out;
		}
		else{
			Node *ptr = list.head;
			while(ptr->getNext() != nullptr) {
				out  << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
			out  << "\t" << *ptr << endl;
			return out;
		}
		return out;
	}
};

#endif