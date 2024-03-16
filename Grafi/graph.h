#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

template<typename T>
class Node {
	T key; //chiave
	
	template<typename U>
	friend class Graph;
	
	public:
	
	Node(T key) : key(key) {} //inizializzo key
	Node() : Node(NULL) {} //costruttore che pone la classe a NULL
	
	bool operator==(Node<T>& n) { //overloading dell operator == (Node<T>& v)
		return this->key == n.key; //restituisce la chiave == v.key (chiave del nodo)
	}
	
	friend std::ostream& operator <<(std::ostream& out, Node<T>& n) { 
		out << n.key; //scrivi la chiave del nodo v.key
		return out; 
	}
};

template<typename T>
class Graph {
	
	Node<T>** arr; //array di nodi del grafo
	bool** matrix;//matrice che ci da delle informazioni su come i nodi sono collegati
	int maxSize = 0;  //dimenzione massima
	int nVertices = 0; //rappresenta l'indice dell'ultimo elemento dell'array di puntatori
	
	public:
	
	Graph(int max_size) : maxSize(max_size) {
		arr = new Node<T>*[max_size];
		matrix = new bool*[max_size];
		for(int i=0; i < max_size; i++) {
			matrix[i] = new bool[max_size]{0};
			
			//for(int j=0; j < max_size; j++) 
			//	adj[i][j] = false;
		}
	}
	
	void addNode(T key) {
		if(this->nVertices == this->maxSize) { //l'indice dell'ultimo elemento = alla dimenzione massima il grafo è pieno
			std::cerr << "Graph is full" << std::endl;
			return;
		}
		
		arr[nVertices++] = new Node<T>(key);
			
	}
	
	void addEdge(T key1, T key2) {
		int i = this->search(key1); //creo due variabili che indicano i due archi
		int j = this->search(key2);
		
		if( i != -1 && j != -1) {
			matrix[i][j] = true;
			matrix[j][i] = true;
		}
		else {
			if(i == -1)
				std::cerr << "There is no vertex with key " << key1 << std::endl;
			else 
				std::cerr << "There is no vertex with key " << key2<< std::endl;
		}
	}
	
	int search(T key) {
		if(this->nVertices == 0) {
			return -1;
		}
		
		for(int i=0; i < this->nVertices; i++) {
			if(arr[i]->key == key)
				return i;
		}
		
		return -1;
	}
	
	friend std::ostream& operator <<(std::ostream& out, Graph<T>& g) {
		
		for(int i=0; i < g.nVertices; i++) {
			out << "v[" << i << "] = " << *g.arr[i] << "\t";
		}
		
		out << std::endl;
		
		for(int i = 0; i < g.nVertices; i++) {
			for(int j = 0; j < g.nVertices; j++) {
				if(g.matrix[i][j])
					out << "(" << i << ", " << j << ")" << std::endl;
			}
		}
		
		return out;
	}
	
	
};

#endif