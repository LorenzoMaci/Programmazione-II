#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

using namespace std;

template<typename T>
class BSTNode{
    T key;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode<T>* parent;
    bool verbose = false;
    
    template <typename U>
    friend class BST;

    public:
    BSTNode(T key, bool verbose = true){
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

    void getLeft(){
        return left;
    }

    void getRight(){
        return right;
    }

    void getParent(){
        return parent;
    }

    void setKey(T key){
        this->key = key;
    }

    friend ostream& operator<<(ostream& out, BSTNode<T>& node){
        if(node.verbose){
            out << "@node:" << &node << ", node.key:" << node.key << ", node.left:" << node.left << ", node.right:" << node.right << ", node.parent" << node.parent; 
        }else{
            out << "node.key:" << node.key;
        } 
        return out;
    }
};

#endif