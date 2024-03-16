#include <iostream>

using namespace std;

class Veicolo{
    string modello;
    string marca;
    int anno;
    
    public:
    Veicolo(string modello, string marca, int anno) : modello(modello), marca(marca),anno(anno){}

    string getModello(){
        return modello;
    }

    string getMarca(){
        return marca;
    }

    int getAnno(){
        return anno;
    }

        virtual string tipo() = 0;

    void stampa(){
        cout << "\t" <<modello << " - " << marca << " - " << anno << " - " << tipo();
    }

    friend ostream& operator<<(ostream& out, Veicolo& v){
        v.stampa();
        return out;
    }

};


class Auto : public Veicolo{
    public:
    Auto(string modello, string marca, int anno) : Veicolo(modello,marca,anno){}

    string tipo(){
        return "Auto";
    }

    friend ostream& operator<<(ostream& out, Auto& a){
        out << static_cast<Veicolo&>(a);
        return out;
    }
};


class Moto: public Veicolo{
    public:
    Moto(string modello, string marca, int anno) : Veicolo(modello, marca , anno){}

    string tipo(){
        return "Moto";
    }

    friend ostream& operator<<(ostream& out, Moto& m){
        out << static_cast<Veicolo&>(m);
        return out;
    }
};

template <typename T> 
class Nodo {
    private:
        T * data;
    public:
    Nodo(T* data) : data(data){
        this->next = nullptr;
    }
    Nodo<T>* next;
        
    T* getData() { 
        return data; 
    }
};


template <typename T> 
class Queue {
    Nodo<T>* head;
    Nodo<T>* tail;
    int dim = 0;

    public: 
        Queue(){
            this->head = nullptr;
            this->tail = nullptr;
        }
        
        void enqueue(T* dataIn){
            if(this->isEmpty()){
                head = new Nodo<T>(dataIn);
                tail = head;
                return;
            }

            Nodo<T>* node = new Nodo<T>(dataIn);
            ++dim;
            tail->next = node;
            tail = node;
        }
        
        
        Nodo<T>* dequeue(){
            if(this->isEmpty()){
                cout << "Empty Queue" << endl;
                return nullptr;
            }

            Nodo<T>* ptr = head;
            head = head->next;
            ptr->next = nullptr;
            if(head == nullptr){
                tail = nullptr;
            }
            return ptr;
        }
        
        Nodo<T>* front() { 
            return head; 
        }
        
        
        bool isEmpty() { 
            return head == nullptr && tail == nullptr; 
        }
        
        
        int getDim() { 
            return dim;
        }


        void stampaCoda(){
            Nodo<T>* ptr = head;
            while(ptr){
                cout << *ptr->getData() << endl;
                ptr = ptr->next;
            }
        }
};


void removeTypeRecursive(Queue<Veicolo> * queue, Queue<Veicolo> * newQueue, string tipo, int * counter) {
    if(queue->isEmpty()) {
        return;
    }
    else {
        if(tipo == queue->front()->getData()->tipo()) {
            ++(*counter);
        }
        else {
            newQueue->enqueue(queue->front()->getData());
        }
        queue->dequeue();
        removeTypeRecursive(queue, newQueue, tipo, counter);
    }
}

int removeType(Queue<Veicolo> * & queue, string tipo) {
    Queue<Veicolo> * newQueue = new Queue<Veicolo>();
    int counter = 0;
    removeTypeRecursive(queue, newQueue, tipo, &counter);
    queue = newQueue;
    return counter;
}


int main(){
    Queue<Veicolo>* queue = new Queue<Veicolo>(); 

    //Dichiarazione dei Veicoli
    queue->enqueue(new Auto("Fiesta", "Ford", 2010));
    queue->enqueue(new Moto("CBR 600 RR", "Honda", 2008));
    queue->enqueue(new Auto("Panda", "Fiat", 2012));
    queue->enqueue(new Moto("Ninja ZX-10R", "Kawasaki", 2019));
    queue->enqueue(new Auto("Golf", "Volkswagen", 2015));
    queue->enqueue(new Moto("R1", "Yamaha", 2020));

    //inserimento in coda veicoli più stampa
    
    cout << endl;
    queue->stampaCoda();

    //Chiedi all'utente di inserire il tipo da veicolo da rimuovere
    cout << "Inserisci il tipo di veicolo da rimuovere ";
    string tipo;
    getline(cin, tipo);
    
    int remove;
    if(tipo == "Auto" || tipo == "auto"){
        remove = removeType(queue, "Auto");
    }else{
        remove = removeType(queue, "Moto");
    }
    cout << "Sono stati rimossi " << remove << " veicoli dalla coda" << endl;
    cout << "Veicoli rimasti: ";
    queue->stampaCoda();

    return 0;
}