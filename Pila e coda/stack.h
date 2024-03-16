#ifndef STACK_H
#define STACK_H

#include "list.h"
#include <iostream>

using namespace std;

template <typename T>
class Stack : protected List<T>{
    private:
    int size = 0;
    public:
    Stack() : List<T>() {}

    bool isEmpty(){
        return size == 0;
    }

    Node<T>* top(){
        if(this->isEmpty()){
            return nullptr;
        }
        return List<T>::getHead();
    }

    void push(T val){
        List<T>::insertHead(val);
        size++;
    }

    Node<T>* pop(){
        if(this->isEmpty()){
            return nullptr;
        }
        Node<T>* ptr = top();
        List<T>::removeHead();
        size--;
        return ptr;
    }

    friend ostream& operator<<(ostream& out, Stack<T>& stack){
        return out << (List<T>)stack;
    }
};