#include <iostream>
#include <typeinfo>

#define MAX_SIZE 10

using namespace std;

class Studente{
    private:
    int matricola;
    string nome;
    string cognome;
    double media;

    public:
    Studente(int matricola, string nome, string cognome, double media) : matricola(matricola), nome(nome),cognome(cognome), media(media){}

    int getMatricola(){
        return matricola;
    }

    string getNome(){
        return nome;
    }

    string getCognome(){
        return cognome;
    }

    double getMedia(){
        return media;
    }

   virtual float getImportoBorsa() { //abbiamo creato questa classe per il dynamic cast perchè senza di questo non possiamo controllare se uno studente è borsista o meno
        return 0.0;
    }
    void stampa(){
        cout << "\t" << matricola << ": " << nome << " " << cognome << " - " << media;
    }
};

class BorsaDiStudio{
    private:
    float importo;
    int durata;
    public:
    BorsaDiStudio(float importo, int durata){
        this->importo = importo;
        this->durata = durata;
    }

    float getImporto(){
        return importo;
    }

    int getDurata(){
        return durata;
    }
};

class StudenteBorsista : public Studente{
    private:
    BorsaDiStudio* borsa;

    public:
    StudenteBorsista(int matricola, string nome, string cognome, double media, BorsaDiStudio* borsa) : Studente(matricola, nome, cognome, media){
        this->borsa = borsa;
    }

    float getImportoBorsa(){
        return borsa->getImporto();
    }

    void stampa(){
        Studente::stampa();
        cout << " [Borsa di " << borsa->getImporto() << " euro] ";
    }
};

template <typename T>
class StaticQueue{
    private:
    T* arr;
    int size = 0;
    int max_Size = MAX_SIZE;
    int head = -1;
    int tail = -1;
    public:
    StaticQueue(int max_Size = MAX_SIZE) : max_Size(max_Size){
        this->arr = new T[max_Size];
    }

    bool isEmpty(){
        return size == 0;
    }
    void enqueue(Studente* student){
        if(size == max_Size){
            cout << "Queue full "<< endl;
            return;
        }

        if(head == -1){
            head = 0;
        }

        tail = (++tail%max_Size);
        arr[tail] = student;
        size++;
    }

    Studente* dequeue(){ //ovviamente restituisce uno studente visto che deve essere rimosso 
        if(size == 0){
            cout << "Empty Queue" << endl;
            return nullptr;
        }

        Studente* val = arr[head];

        head = (++head%max_Size);
        size--;

        return val;   
    }
};

int main(){
    BorsaDiStudio borsa1(880.0 , 1);
    BorsaDiStudio borsa2(500.0, 1);
    BorsaDiStudio borsa3(600.0, 1);

    StaticQueue<Studente*> tail;
    StaticQueue<Studente*> tail2; //creo questa classe per la stampa in modo tale da vedere gli studenti che rimangono 

    tail.enqueue(new Studente(1001, "Mario", "Rossi", 25.5 ));
    tail.enqueue(new StudenteBorsista(1002, "Anna", "Verdi", 28.0, &borsa1));
    tail.enqueue(new Studente(1003, "Luca", "Bianchi", 26.0));
    tail.enqueue(new Studente(1004, "Sara", "Neri", 27.5));
    tail.enqueue(new StudenteBorsista(1005, "Marco", "Gialli", 24.0, &borsa2));
    tail.enqueue(new StudenteBorsista(1006, "Laura" , "Marroni", 29.0, &borsa3));

    float totale_importo = 0.0;
    int studenti_Rimossi = 0;
    while(!tail.isEmpty()){ // scorriamo la coda fino a quando essa non sarà vuota condizione se la coda non è vuota entriamo nel while
        Studente* student = tail.dequeue(); 
        if(student->getMedia() < 25.0){
            studenti_Rimossi++;
            cout << "Lo studente " << student->getNome() << " Matricola: "<< student->getMatricola() << " è stato rimosso "<< endl;
            delete student;
        }else{
            if(StudenteBorsista* borsista = dynamic_cast<StudenteBorsista*>(student)){
                totale_importo += borsista->getImportoBorsa();
            }
            tail2.enqueue(student);
        }
    }
    cout << endl;

    cout << "Il contenuto della coda è: " << endl;
    while(!tail2.isEmpty()){
        Studente* student = tail2.dequeue();
        student->stampa();
        cout << endl;
        delete student;
    }

    cout << "Il totale degli importi delle borse di studio assegnate agli studenti è: " << totale_importo << " euro." << endl;
    return 0;
}