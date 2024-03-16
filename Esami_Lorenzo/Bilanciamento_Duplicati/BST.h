#ifndef BST_H
#define BST_H

#include <iostream>
#include "bstnode.h"

using namespace std;

static int counter = 0;

template<typename T>
class BST{
    private:
    BSTNode<T>* root;

    public:
    BST() {root = nullptr;}

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(T key){
        insert(root, key);
    }

    bool search(T key){
        return search(root, key);
    }

    bool search(BSTNode<T>* p, T key){
        if(p == nullptr){
            return false;
        }
        if(p->getKey() == key){
            return p;
        }
        if(key <= p->getKey()){
            return search(p->getLeft(), key);
        }else{
            return search(p->getRight(), key);
        }
        return false;
    }

    void insert(BSTNode<T>* p, T key){
        if(this->root == nullptr){
            root = new BSTNode<T>(key);
            return;
        }
    
        if(search(key)){
            if(counter % 2 == 0){
                if(key <= p->getKey() && p->getLeft() == nullptr){
                    BSTNode<T>* node = new BSTNode<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "key: " << key << endl;
                    cout << "Metto il valore a sinsitra " << endl;
                    counter++;
                    return;
                }else if(key > p->getKey() && p->getRight() == nullptr){
                    BSTNode<T>* node = new BSTNode<T>(key);
                    p->setRight(node);                  
                    node->setParent(p);
                    cout << "key: " << key << endl;
                    cout << "Metto il valore a sinistra" << endl;
                    counter++;
                    return; 
                }else if(key <= p->getKey() && p->getLeft() != nullptr){
                    insert(p->getLeft(), key);
                }else if(key > p->getKey() && p->getRight() != nullptr){
                    insert(p->getRight(), key);
                } 
            }else{
                if(key < p->getKey() && p->getLeft() == nullptr){
                    BSTNode<T>* node = new BSTNode<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "key: " << key << endl;
                    cout << "Metto il valore a destra " << endl;
                    counter++;
                    return;
                }else if(key >= p->getKey() && p->getRight() == nullptr){
                    BSTNode<T>* node = new BSTNode<T>(key);
                    p->setRight(node);                  
                    node->setParent(p);
                    cout << "key: " << key << endl;
                    cout << "Metto il valore a destra" << endl;
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
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setLeft(node);
                node->setParent(p);
            }else if(key > p->getKey() && p->getRight() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setRight(node);
                node->setParent(p);
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

    void inorder(BSTNode<T>* p){
        if(p != nullptr){
            inorder(p->getLeft());
            cout << p->getKey() << " ";
            inorder(p->getRight());
        }
    }
};

#endif