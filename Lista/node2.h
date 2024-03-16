#ifndef LNODE_H
#define LNODE_H

#include <iostream>

using namespace std;

template<typename T>
class Node{
    private:
    T val;
    Node<T>* next;
    bool verbose = false;

    template<typename U>
    friend class List;

    public:
    Node(T val, bool verbose = true) : val(val), verbose(verbose){this->next = nullptr;}

    T& getVal() {return this->val;}
    Node<T>* getNext() const{return this->next;}

    friend ostream& operator<<(ostream& out, const Node<T>& node){
        if(node.verbose)
        out << "@node:" << &node << ", node.val:" << node.val << ", node.next: "<< node.next;
        else
        out << "node.val:" << node.val;
        return out;
    }
};