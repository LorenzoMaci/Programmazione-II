#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo{
    protected:
    string titolo;
    string anno;
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

    Nodo* getLeft(){
        return left;
    }

    Nodo* getRight(){
        return right;
    }

    Nodo* getParent(){
        return parent;
    }

    string& getAnno(){
        return this->anno;
    }

    string& getTitolo(){
        return this->titolo;
    }

    string& getValutazione(){
        return this->valutazione;
    }

    friend ostream& operator<<(ostream& out, Nodo& node){
        out << "-Titolo:" << node.titolo << " -Valutazione:" << node.valutazione << " -Anno:" << node.anno << endl;
        return out;
    }
};

#endif