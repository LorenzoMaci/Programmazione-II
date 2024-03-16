#include <iostream>

using namespace std;

class Frutto{
    string tipo;
    string nome;
    string colore;
    string stagione;
    public:
    Frutto(string tipo, string nome, string colore, string stagione) : tipo(tipo), nome(nome), colore(colore), stagione(stagione){}

    string getTipo(){
        return tipo;
    }

    string getNome(){
        return nome;
    }

    string getColore(){
        return colore;
    }

    string getStagione(){
        return stagione;
    }

    virtual string sapore() = 0;

    void stampa(){
        cout << nome << ", " << colore << ", " <<  stagione << ", Sapore " << sapore() << endl;
    }

    friend ostream& operator<<(ostream& out, Frutto& f){
        f.stampa();
        return out;
    }
};

class Mela : public Frutto{
    private:
    string tipo_sapore;

    public:
    Mela(string tipo, string nome, string colore, string stagione, string tipo_sapore) : Frutto(tipo, nome, colore, stagione){
        this->tipo_sapore = tipo_sapore;
    }

    string sapore(){
        return tipo_sapore;
    }

    friend ostream& operator<<(ostream& out, Mela& m){
        out << static_cast<Frutto&>(m);
        return out;
    }
};

class Arancia : public Frutto{
    private:
    string tipo_sapore;

    public:
    Arancia(string tipo, string nome, string colore, string stagione, string tipo_sapore) : Frutto(tipo,nome, colore, stagione){
        this->tipo_sapore = tipo_sapore;
    }

    string sapore(){
        return tipo_sapore;
    }
    
    friend ostream& operator<<(ostream& out, Arancia& a){
        out << static_cast<Frutto&>(a);
        return out;
    }
};

template <typename T>
class Nodo{
    private:
    T* vec;

    public:
    Nodo(T* vec) : vec(vec){
        this->next = nullptr;
    }

    Nodo<T>* next;

    T* getVec(){
        return vec;
    }
    
};


template <typename T>
class Queue{
    private:
    Nodo<T>* head;
    Nodo<T>* tail;
    int size = 0;
    public:
    Queue(){
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~Queue() {
        Nodo<T>* ptr = head;
        while (ptr) {
            delete ptr->getVec();
            delete ptr;
            ptr = ptr->next;
        }
    }
    
    void enqueue(T* dataIn){
        if(this->isEmpty()){
            head = new Nodo<T>(dataIn);
            tail = head;
            return;
        }

        Nodo<T>* node = new Nodo<T>(dataIn);
        ++size;
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
        

    void stampaCoda(){
        Nodo<T>* ptr = head;
        while(ptr){
            cout << *ptr->getVec() << endl;
            ptr = ptr->next;
        }
    }
};

/*void removeTypeRecursive(Queue<Frutto> * queue, Queue<Frutto> * newQueue, string tipo, int * counter) {
    if(queue->isEmpty()) {
        return;
    }
    else {
        if(tipo == queue->front()->getVec()->getTipo()) {
            ++(*counter);
        }
        else {
            newQueue->enqueue(queue->front()->getVec());
        }
        queue->dequeue();
        removeTypeRecursive(queue, newQueue, tipo, counter);
    }
}*/

void removeTypeRecursive(Queue<Frutto>* queue, Queue<Frutto>* newQueue, string tipo, int* counter) {
    if (queue->isEmpty()) {
        return;
    } else {
        Frutto* frontFrutto = queue->front()->getVec();
        Mela* mela = dynamic_cast<Mela*>(frontFrutto);
        Arancia* arancia = dynamic_cast<Arancia*>(frontFrutto);
        
        if ((tipo == "Mela" || tipo == "mela") && mela != nullptr) {
            ++(*counter);
        } else if ((tipo == "Arancia" || tipo == "arancia") && arancia != nullptr) {
            ++(*counter);
        } else {
            newQueue->enqueue(frontFrutto);
        }
        
        queue->dequeue();
        removeTypeRecursive(queue, newQueue, tipo, counter);
    }
}

int removeType(Queue<Frutto> * & queue, string tipo) { //funzione d'interfaccia
    Queue<Frutto> * newQueue = new Queue<Frutto>();
    int counter = 0;
    removeTypeRecursive(queue, newQueue, tipo, &counter);
    queue = newQueue;
    return counter;
}

int main(){
    Queue<Frutto>* queue = new Queue<Frutto>();

    queue->enqueue(new Mela("Mela", "Granny Smith", "Verde", "Autunno", "Aspro"));
    queue->enqueue(new Arancia("Arancia", "Tarocco", "Arancione", "Inverno", "Dolce"));
    queue->enqueue(new Mela("Mela", "Golden Delicious", "Giallo", "Autunno", "Dolce"));
    queue->enqueue(new Arancia("Arancia", "Navel", "Arancione", "Inverno", "Dolce-Acido"));
    queue->enqueue(new Mela("Mela", "Fuji", "Rosso", "Autunno" , "Dolce"));
    queue->enqueue(new Arancia("Arancia", "Valencia", "Arancione", "Estate", "Acido"));
    
    cout << "inserisci il tipo di frutto da rimuovere ";
    string tipo;
    cin >> tipo;
    int frutti_rimossi = 0;
    if(tipo == "Mela" || tipo == "mela"){
        frutti_rimossi = removeType(queue, "Mela");
    }else if(tipo == "Arancia" || tipo == "arancia"){
        frutti_rimossi = removeType(queue, "Arancia");
    }else{
        cout << "Frutto non trovato " << endl;
        cout << endl;
    }
    cout << "Sono stati rimossi " << frutti_rimossi << " dalla coda" << endl;
    cout << "Frutti Rimasti " << endl;
    queue->stampaCoda();
    return 0;
}