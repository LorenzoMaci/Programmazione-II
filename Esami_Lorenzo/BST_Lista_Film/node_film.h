#ifndef LNODE_FILM_H
#define LNODE_FILM_H

#include <iostream>
using namespace std;

class Node {
	string nome;
	string anno;
	string valutazione;
	Node* next;
	
	friend class List;
	
	public:
	
	Node(string anno, string nome, string valutazione) : anno(anno), nome(nome), valutazione(valutazione) {
		next = nullptr;
	}
	
	Node* getNext() const{ 
		return this->next; 
	}
	
	string& getNome(){
		return this->nome; 
	}

	string& getAnno(){
		return this->anno; 
	}

	string& getValutazione(){
		return this->valutazione; 
	}

	void setNext(Node* next){
		this->next = next;
	}
	
	friend ostream& operator<<(ostream& out, const Node& node){
		out << "- Nome = " << node.nome << ", Valutazione = " << node.valutazione << ", Anno Uscita = " << node.anno;
		return out;
	}
};

#endif