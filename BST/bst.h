#ifndef BST_H
#define BST_H

#include <iostream>
#include "bst_node.h"

using namespace std;

template<typename T>
class BST{
    BSTNode<T>* root;
    
    public:
    BST() {this->root = nullptr;}

    bool isEmpty(){
        return root == nullptr;
    }

    BSTNode<T>* getRoot(){
        return root;
    }

    void insert(T key){
        if(this->isEmpty()){
            root = new BSTNode<T>(key);
            return;
        }
        insert(root, key);
    }

    void insert(BSTNode<T>* ptr, T key){
        if(ptr->left == nullptr && key <= ptr->key){
            ptr->left = new BSTNode<T>(key);
            ptr->right->parent = ptr;
            return
        }else if(key <= ptr->key){
            insert(ptr->left, key);
        }else{
            insert(ptr->right, key);
        }
    }

    void visit(BSTNode<T>* node){
        cout << "node:" << *node;
    }

    void inorder(BSTNode<T>* ptr){
        if(ptr == nullptr){
            return;
        }
        inorder(ptr->left);
        visit(ptr);
        inorder(ptr->right);
    }

    void inorder(){
        inorder(root);
    }

    //Implementazione PREORDER E POSTORDER
    BSTNode<T>* min(){
        return min(root);
    }

    BSTNode<T>* min(BSTNode<T>* from){
        if(this->isEmpty()){
            return NULL;
        }
        
        BSTNode<T>* ptr = from;
        while(ptr->left){
            ptr = ptr->left;
            return ptr; 
        }
    }

    BSTNode<T>* max(){
        return max(root);
    }

    BSTNode<T>* max(BSTNode<T>* from){
        if(this->isEmpty()){
            throw "Empty BST";
        }
        BSTNode<T>* ptr = from;
        while(ptr->right){
            ptr = ptr->right;
            return ptr;
        }
    }

    BSTNode<T>* successor(BSTNode<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }
        if(x->right){
            return min(x->right);
        }

        BSTNode<T>* y = x->parent;
        while(x != nullptr && x == y->right){
            x = y;
            y = y->parent;
        }
        return y;
    }

    BSTNode<T>* search(T key){
        return search(root, key);
    }

    BSTNode<T>* search(BSTNode<T>* ptr, T key){
        if(ptr == nullptr){
            return nullptr;
        }
        if(ptr->key == key){
            return ptr;
        }
        if(key <= ptr->key){
           return search(ptr->left, key); 
        }else{
            return nullptr;
        }
    }


    //Se Il nodo è una foglia
    BSTNode<T>* remove(BSTNode<T>* node){
        if(node->left == nullptr && node->right == nullptr){
            if(node == node->parent->left){
                node->parent->left = nullptr
            }else if(node == node->parent->right){
                node->parent->right = nullptr;
            }
            return node;
        }

        //il nodo da eliminare ha solo un figlio destro
        if(node->left == nullptr && node->right != nullptr){
            node->right->parent = node->parent;
            if(node == node->parent->left){
                node->parent->left = node->right;
            }else if(node == node->parent->right){
                node->parent->right = node->right;
            }
            return node;
        }

        //il nodo da eliminare ha solo un figlio sinistro
        if(node->left != nullptr && node->right == nullptr){
            node->left->parent = node->parent;
            if(node == node->parent->right){
                node->parent->right = node->left;
            }else if(node == node->parent->left){
                node->parent->left = node->left;
            }
            return node;
        }
    }

    BSTNode<T>* remove(T key){
        if(this->isEmpty()){
            return nullptr;
        }
        BSTNode<T>* node = this->search(key);
        if(node == nullptr){
            return nullptr;
        }

        BSTNode<T>* toDelete = this->remove(node);
        if(toDelete != nullptr){
            return toDelete;
        }
        
        //Il nodo da eliminare ha 2 figli
        BSTNode<T>* next = this->successor(node);
        T swap = node->key;
        node->key = next->key;
        next->key = swap;

        //Richiamo la procedura di cancellazione 
        toDelete = this->remove(next);
        return toDelete; 
    }
};

#endif