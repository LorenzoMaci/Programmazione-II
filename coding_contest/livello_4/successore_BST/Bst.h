#ifndef BST_H
#define BST_H

#include <iostream>
#include "Nodo.h"
using namespace std;

template <typename T>
class BST{
    private:
    Nodo<T>* root;
    
    public:
    BST(){
        root = nullptr;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if(root == nullptr){
            root = new Nodo<T>(key);
            return;
        }

        if(key <= p->getKey() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if(key > p->getKey() && p->getRigth() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if(key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRigth() != nullptr){
            insert(p->getRigth(), key);
        }
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
        }else if(key <= p->getKey()){
           return search(p->getLeft(), key);
        }else{
            return search(p->getRigth(),key);
        }
        return nullptr;
    }

    Nodo<T>* min(){
        return min(root);
    }

    Nodo<T>* min(Nodo<T>* x){
        if(this->isEmpty()){
            return 0;
        }
        Nodo<T>* nMin = x;
        while(nMin->getLeft()){
            nMin = nMin->getLeft();
        }
        return nMin;
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if(u->getParent() == nullptr){
            root = v;
        }
        else if(u == u->getParent()->getLeft()){
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
            trapianta(p, p->getRigth());
        }else if(p->getRigth() == nullptr){
            trapianta(p, p->getLeft());
        }else{
            Nodo<T>* y = min(p->getRigth());
            if(y->getParent() != p){
                trapianta(y, y->getRigth());
                y->setRight(p->getRigth());
                y->getRigth()->setParent(y);
            }
            trapianta(p, y);
            y->setLeft(p->getLeft());
            y->getLeft()->setParent(y);
        }
        delete p;
    }

    Nodo<T>* max(){
        return max(root);
    }

    Nodo<T>* max(Nodo<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }

        Nodo<T>* nMax = x;
        while(nMax->getRigth()){
            nMax = nMax->getRigth();
        }
        return nMax;
    }

    Nodo<T>* successor(T key){
        Nodo<T>* p = search(key);
        if(!p || p == max()){
            return nullptr;
        }
        return successor(p);
    }

    Nodo<T>* successor(Nodo<T>* p){
        if(this->isEmpty()){
            return nullptr;
        }
 // 1. p ha un sottoalbero destro
        if(p->getRigth()){
            return min(p->getRigth());
        }
// 2. p non ha un sottoalbero destro, il successore di p è l'antenato più prossimo di p il cui figlio sinistro è anche un antenato di p

        Nodo<T>* y = p->getParent();
        while(p != nullptr && p == y->getRigth()){
            p = y;
            y = y->getParent();
        }
        return y;
    }   
};  

#endif