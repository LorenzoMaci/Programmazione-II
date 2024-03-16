#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo{
    protected:
    string anno;
    string titolo;
    string valutazione;
    Nodo* left;
    Nodo* right;
    Nodo* parent;

    friend class BST;
    public:

    Nodo(string anno, string titolo, string valutazione) : anno(anno), titolo(titolo), valutazione(valutazione){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }

    void setLeft(Nodo* left){
        this->left = left;
    }

    void setRight(Nodo* right){
        this->right = right;
    }

    void setParent(Nodo* parent){
        this->parent = parent;
    }

    string& getAnno(){
        return anno;
    }

    string& getTitolo(){
        return titolo;
    }

    string& getValutazione(){
        return valutazione;
    }

    Nodo* getLeft(){
        return left;
    }

    Nodo* getRight(){
        return right;
    }

    Nodo* getParent(){
        return parent;
    }

    friend ostream& operator<<(ostream& out, Nodo& node){
        out << "-Anno: " << node.anno << " -Titolo:" << node.titolo << " -Valutazione: "<< node.valutazione << endl;
        return out;
    }
};

#endif