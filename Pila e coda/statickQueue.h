//implementazione tramite array
#ifndef STATIC_QUEUE
#define STATIC_QUEUE

#include <iostream>
#define MAX_SIZE 1000

using namespace std;

template<typename T>
class StaticQueue{
    private:
    T* array; //Array di templeate
    int size = 0; //dimenzione
    int maxSize = MAX_SIZE; //Dimenzione Massima della coda
    int head = -1; //testa
    int tail = -1; //coda

    public:
    StaticQueue(int maxSize = MAX_SIZE) : maxSize(maxSize){ //inizializzo MaxSize = MAX_SIZE e dichiaro un array di dimenzione maxSize
        this->array = new T[maxSize];
    }

    void enqueue(T val){ //inserisci elementi
        if(size == maxSize){ //se la dimenzione è uguale alla dimenzione massima della coda, scrivi che la coda è piena e fai return
            cout << "Queue full" << endl;
            return; 
        }

        if(head == -1){ //se la testa è == -1
            head = 0; //pongo la testa = 0
        }

        tail = (++tail % maxSize); //pongo la coda = al modulo dell'incremento prefisso della coda e maxSize
        array[tail] = val; //pongo l'array[coda] = val;
        size++; //incremento la dimenzione
    }

    T dequeue(){
        if(size == 0){ //se la dimenzione è  = 0;
            cout << "tail is empty " << endl; //scrivo la coda è vuota
            return 0;  // restituisco 0
        }

        T val = array[head]; //creo una variabile val e la pongo = all'elemento dell'array nella posizione head
        head = (++head % maxSize); //pongo la testa = al modulo dell'incremento prefisso della testa e maxSize
        size--; //diminuisco al dimenzione
        return val; //restituisco val
    }

    friend ostream& operator<<(ostream& out, StaticQueue<T>& queue){
        if(queue.size == 0){
            out < "queue is empty " << endl;
        }
        out << ", queue.size=" << queue.size << ", queue.maxSize=" << queue.maxSize;
        for(int i=queue.head, count = 0; count < queue.size; count++){
            out << queue.array[i] << " ";
            i = (i + 1) % queue.maxSize;
        }
        return out;
    }
};

#endif