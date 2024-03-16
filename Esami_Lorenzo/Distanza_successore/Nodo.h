#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

template <typename T>
class Nodo{
    protected:
    T key;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
    bool verbose;
    template <typename U>
    friend class BST;
    
    public:
    Nodo(T key, bool verbose = false) : key(key), verbose(verbose){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    void setLeft(Nodo<T>* left){
        this->left = left;
    }

    void setRight(Nodo<T>* right){
        this->right = right;
    }

    void setParent(Nodo<T>* parent){
        this->parent = parent;
    }

    Nodo<T>* getLeft(){
        return left;
    }

    Nodo<T>* getRight(){
        return right;
    }

    Nodo<T>* getParent(){
        return parent;
    }


    T getKey(){
        return key;
    }

    friend ostream& operator<<(ostream& out, Nodo<T>& n){
        if(n.verbose){
        out << "Nodo:" << &n << endl;
        out << "key=" << n.key << endl;
        out << "left->" << n.left << ", right->" << n.right << ", parent->" << n.parent << endl;
        return out;
        }
        return out << "\tkey:" << n.key << endl;
    }
};

#endif