#ifndef BST_H
#define BST_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class BST{
    protected:
    Nodo* root;
    public:
    BST(){
        root = nullptr;
    }

    void insert(string anno, string titolo, string valutazione){
        insert(root,  anno,  titolo,  valutazione);
    }

    void insert(Nodo* p, string anno, string titolo, string valutazione){
        if(this->root  == nullptr){
            root = new Nodo(anno, titolo, valutazione);
            return;
        }

        if(anno <= p->getAnno() && p->getLeft() == nullptr){
            Nodo* node = new Nodo(anno, titolo, valutazione);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if(anno > p->getAnno() && p->getRight() == nullptr){
            Nodo* node = new Nodo(anno, titolo, valutazione);
            p->setRight(node);
            node->setParent(p);
        }else if(anno <= p->getAnno() && p->getLeft() != nullptr){
            insert(p->getLeft(), anno, titolo, valutazione);
        }else if(anno > p->getAnno() && p->getRight() != nullptr){
            insert(p->getRight(), anno, titolo, valutazione);
        }
    }

    void inorder(){
        inorder(root);
    }

    void inorder(Nodo* p){
        if(p != nullptr){
            inorder(p->getLeft());
            cout << "\t-Titolo:" << p->getTitolo() << " -Valutazione:" << p->getValutazione() << " -Anno:" << p->getAnno() << endl;
            inorder(p->getRight());
        }
    }

};

#endif