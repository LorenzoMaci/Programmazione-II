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

    Nodo<T>* getRoot(){
        return this->root;
    }

    void insert(T key){
        insert(root, key);        
    }

    void insert(Nodo<T>* p, T key){
        if(this->root == nullptr){
            root = new Nodo<T>(key);
            return;
        }

        if(key <= p->getKey() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if(key > p->getKey() && p->getRight() == nullptr){
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

    void inorder(){
        inorder(root);
    }

    void inorder(Nodo<T>* p){
        if(p != nullptr){
            inorder(p->getLeft());
            cout << p->getKey() << " ";
            inorder(p->getRight());
        }
    }

    Nodo<T>* max(){
        return max(root);
    }

    Nodo<T>* max(Nodo<T>* x){
        if(this->isEmpty()){
            throw out_of_range("Empty bst..."); 
        }
        Nodo<T>* nMax = x;
        while(nMax->getRight()){
            nMax = nMax->getRight();
        }
        return nMax;
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

    int distanz_successor(T key){
        if(this->isEmpty()){
            return 0;
        }

        int counter = 0;

        Nodo<T>* p = search(key);

        if(!p || p == max()){
            return 0;
        }
        if(p->getRight()){
            p = p->getRight();
            counter++;
            while(p->getLeft()){
                p = p->getLeft();
                counter++;
            }
            return counter;
        }

        Nodo<T>* y = p->getParent();
        counter++;
        while(p && p == y->getRight()){
            p = p->getParent();
            y = y->getParent();
            counter++;
        }
        return counter;
    }
};

#endif