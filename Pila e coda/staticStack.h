#ifndef STATICK_STACK_H
#define STATICK_STACK_H

#include <iostream>

using namespace std;

template <typename T>
class StaticStack{
    private:
    T* array; //dichiaro un array di template
    int top = -1; // cima = -1
    int size = 0; //dimenzione 
    int maxSize = -1; //la dimenzione massima = -1
    public:
    StaticStack(int _maxSize) : maxSize(_maxSize){ // inizializzo max_size e dichiaro un array di maxSize elementi
		array = new T[maxSize]; 
	}

    T getTop(){  //ottieni la cima
        if(isEmpty()){ //se è vuota restituisco -1
            return -1;
        }
        return array[top]; //restituiscimi la cima dell'array
    }

    void push(T val){ //inserisco un elemento nella pila
        if(top == maxSize - 1){ //se la cima = alla dimenzione -1 fai return
            return; 
        }
        array[++top] = val; //pongo l'elemento dell'array che si trova nell'incremento prefisso della cima = val
    }

    T pop(){ //preleva
        if(isEmpty()){ //se è vuota restituisci -1
            return -1;
        }
        return array[top--]; //restituisci elemento dell'array nella posizione postfissa(decrementata) della cima
    }

    bool isEmpty(){ 
        return top == -1; //restituisci la cima che è uguale a -1
    }

    friend ostream& operator<<(ostream& out, StaticStack<T>& stack){
        out << "Stack size= " << stack.size << endl;
        out << "-----------" << endl;
        for(int i = stack.top, i >= 0; i--){
            out << " array[i]{" << array[i] << "-";
        } 
        out << endl;
        return out;
    }
};