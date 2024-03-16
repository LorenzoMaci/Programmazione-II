#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
using namespace std;

template<typename T>
class BSTNode {
    protected:
        T key;
        BSTNode<T>* left;
        BSTNode<T>* right;
        BSTNode<T>* parent;

        template<typename U>
	    friend class BST;

    public:
        BSTNode(T key) : key(key){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void setLeft(BSTNode<T>* left){
            this->left = left;
        }

        void setRight(BSTNode<T>* right){
            this->right = right;
        }

        void setParent(BSTNode<T>* parent){
            this->parent = parent;
        }

        void setKey(T key){
            this->key = key;
        }

        BSTNode<T>* getLeft(){
            return left;
        }

        BSTNode<T>* getRight(){
            return right;
        }

        BSTNode<T>* getParent(){
            return parent;
        }

        T getKey(){
            return key;
        }

        //OVERLOADING PER LA STAMPA DA TERMINALE
            friend ostream& operator<<(ostream& out, BSTNode<T>& node) {
                out << "key: " << node.key << endl;
                return out;
            }
};

#endif