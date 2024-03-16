#ifndef BST_H
#define BST_H

#include <iostream>
#include "Nodo.h"
using namespace std;

int static counter = 0;

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
    
    void insert(Nodo<T>* p, T key){
        if(root == nullptr){
            root = new Nodo<T>(key);
            return;
        }

        if(search(key)){
            if(counter % 2 == 0){
                if(key <= p->getKey() && p->getLeft() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "key=" << key << endl;
                    cout << "La metto a sinistra" << endl;
                    counter++;
                    return;
                }else if(key > p->getKey() && p->getRight() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setRight(node);
                    node->setParent(p);
                    cout << "key=" << key << endl;
                    cout << "La metto a sinistra" << endl;
                    counter++;
                    return;
                }else if(key <= p->getKey() && p->getLeft() != nullptr){
                    insert(p->getLeft(), key);
                }else if(key > p->getKey() && p->getRight() != nullptr){
                    insert(p->getRight(), key);
                }
            }else{
                if(key < p->getKey() && p->getLeft() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "key=" << key << endl;
                    cout << "La metto a destro" << endl;
                    counter++;
                    return;
                }else if(key >= p->getKey() && p->getRight() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setRight(node);
                    node->setParent(p);
                    cout << "key: "<< key << endl;
                    cout << "La metto a destra" << endl;
                    counter++;
                    return;
                }else if(key < p->getKey() && p->getLeft() != nullptr){
                    insert(p->getLeft(), key);
                }else if(key >= p->getKey() && p->getRight() != nullptr){
                    insert(p->getRight(), key);
                }
            }
        }else{
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
};

#endif