#ifndef NODO_LIST_H
#define NODO_LIST_H

#include <iostream>

using namespace std;

class Nodo_List{
    protected:
    string titolo;
    string anno;
    string valutazione;
    Nodo_List* next;

    friend class List;

    public:
    Nodo_List(string anno, string titolo, string valutazione) : anno(anno), titolo(titolo), valutazione(valutazione) {
		next = nullptr;
        next = nullptr;
    }

    Nodo_List* getNext() const {return this->next;}

    string& getTitolo(){
        return titolo;
    }

    string& getAnno(){
        return anno;
    }

    string& getValutazione(){
        return valutazione;
    }

    void setNext(Nodo_List* next){
        this->next = next;
    }

    friend ostream& operator<<(ostream& out, Nodo_List& node){
        out << "-Titolo: " << node.titolo << " -Anno: " << node.anno << " -Valutazione: " << node.valutazione << endl;
        return out;
    }
};

#endif