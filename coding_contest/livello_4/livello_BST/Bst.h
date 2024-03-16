#ifndef BST_H
#define BST_H

#include <iostream>
#include "Nodo.h"

template<typename T>
class BST{
    private:
    Nodo<T>* root;
    
    public:
    BST() {root = nullptr;}

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if( root == nullptr){
            root = new Nodo<T>(key);
            return;
        }

        if(key <= p->getKey() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if( key > p->getKey() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if(key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRight() != nullptr){
            insert(p->getRight(), key);
        }
    }

    Nodo<T>* min(){
        return min(root);
    }

    Nodo<T>* min(Nodo<T>* x){
        if(this->isEmpty()) {
            return nullptr;
        }
        Nodo<T>* nMin = x;
        while(nMin->getLeft()){
            nMin = nMin->getLeft();
        }
        return nMin;
    }

    Nodo<T>* search(T key){
        return search(root, key);
    }

    Nodo<T>* search(Nodo<T>* p, T key){
        if(p == nullptr){
            return nullptr;
        }
        if(p->getKey() == key){
            return p;
        }
        if(key <= p->getKey()){
            return search(p->getLeft(), key);
        }else{
            return search(p->getRight(), key);
        }
        return nullptr;
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if(u->getParent() == nullptr){
            root = v;
        }else if(u == u->getParent()->getLeft()){
            u->getParent()->setLeft(v);
        }else{
            u->getParent()->setRight(v);
        }
        if(v != nullptr){
            v->setParent(u->getParent());
        }
    }

    void remove(T key){
        Nodo<T>* p = search(key);
        if(p->getLeft() == nullptr){
            trapianta(p, p->getRight());
        }else if(p->getRight() == nullptr){
            trapianta(p, p->getLeft());
        }else{
            Nodo<T>* y = min(p->getRight());
            if( y->getParent() != p){
                trapianta(y, y->getRight());
                y->setRight(p->getRight());
                y->getRight()->setParent(y);
            }
            trapianta(p, y);
            y->setLeft(p->getLeft());
            y->getLeft()->setParent(y);
        }
        delete p;
    }

    int livello(T key){
        Nodo<T>* p = search(key);
        if(p == nullptr){
            return -1;
        }
        return livello(p);
    }

    int livello(Nodo<T>* p){
        if(p == root){
            return 0;
        }
        if(p->getParent() == root){
            return 1;
        }
        int counter = 0;
        while(p->getParent() != root){
            counter++;
            p = p->getParent();
        }
        return counter + 1;
    }
};  

#endif