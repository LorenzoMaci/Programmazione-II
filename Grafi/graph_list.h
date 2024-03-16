#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include "./list.h"

//ESTENDO LA CLASSE List IN MODO DA AVERE IL
//VERTICE NELLA head E LA LISTA DI ADIACENZA NEI SUCCESSORI
template<typename T>
class GraphVertex : public List<T> {
	protected:
	bool verbose; //condizione
	
	public:
	GraphVertex(T key, bool verbose=false) : List<T>(), verbose(verbose) { //inizializzio verbose = false e richiamo insert(key)
		List<T>::insert(key);
	}
	
	friend std::ostream& operator<<(std::ostream& out, const GraphVertex<T>& v) { //ostream
		if(v.verbose) { // se la condizione è vera
			out << "Graph Vertex with key " << v.head->getVal() << ": " << std::endl; // scrivo il vertice del grafico con la chiave << v.head->getVal()
			out << "\tAdjacency List: "; //"\telenco delle adiacenze: "
			Node<T> *ptr = v.getHead(); // pongo un nodo pointer = v.getHead(), (uguale al valore della testa, del vertice del grafico)
			while(ptr) { //se ptr esiste
				out << " -> " << ptr->getVal() ; //scrivo il valore di ptr (ptr->getVal());
				ptr = ptr->getNext(); //pongo poi ptr = ptr->getNext() (uguale al prossimo valore di ptr)
			}
		}
		else {
			Node<T> *ptr = v.getHead(); //altrimenti pongo il nodo ptr = v.getHead (uguale alla testa del vertice del grafico)
			out << ptr->getVal() << ": "; //scrivo ptr->getVal()  << ": " (scrivo il valore di ptr)
			if(ptr->getNext()) { //se ptr ha un elemento successivo (ptr->getNext())
				ptr = ptr->getNext(); //pongo ptr = ptr->getNext()
				while(ptr->getNext()) { //utilizzo un ciclo while dove controllo se ptr ha un elemento successivo
					out << ptr->getVal() << ", "; 
					ptr = ptr->getNext(); 
				}
				out << ptr->getVal(); 
			}
			else 
				out << "/"; 
					
		}
		
		return out;
	}
};

template<typename T>
class GraphList {
	List< GraphVertex<T> > vertices;
	int nVertices = 0; 
	bool isOriented; 
	bool verbose,
	
	public:
		GraphList(bool isOriented=true, bool verbose=false) : isOriented(isOriented), verbose(verbose) {}
		
		void addVertex(T key) { 
			GraphVertex<T> toAdd(key, verbose); 
			vertices.insertTail(toAdd); 
			nVertices++; 
		}
		
		void addEdge(T key1, T key2) {  //aggiungi bordo 
			
			Node< GraphVertex<T> > *node1 = this->search(key1); 
			Node< GraphVertex<T> > *node2 = this->search(key2);
			
			if(node1 && node2) { 
				node1->getVal().insertTail(key2); 
				if(!this->isOriented) { o
					node2->getVal().insertTail(key1); 
				}
			}
			
		}
		
		Node< GraphVertex<T> >* search(T key) { //ricerca di un nodo
			if(nVertices == 0) 
				return NULL; 
			
			Node< GraphVertex<T> > *ptr = vertices.getHead(); 
			while(ptr) {
				if(key == ptr->getVal().getHead()->getVal()) 
					return ptr; 
				
				ptr = ptr->getNext(); 
			}
			
			return NULL; 
			
		}
		
		friend std::ostream& operator<<(std::ostream& out, GraphList<T>& g) {
			out << g.vertices;
			
			return out;
		}
		
};

#endif