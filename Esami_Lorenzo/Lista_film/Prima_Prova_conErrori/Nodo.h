#include <iostream>

using namespace std;

class Nodo{
    protected:
    string titolo;
    string genere;
    string proiezione;
    Nodo* next;

    friend class List;
    public:
    Nodo(string titolo, string genere, string proiezione) : titolo(titolo), genere(genere), proiezione(proiezione){
        this->next = nullptr;
    }

    Nodo* getNext() const { return next;}

    string& getTitolo(){
        return this->titolo;
    }

    string& getGenere(){
        return this->genere;
    }

    string& getProiezione(){
        return this->proiezione;
    }

    void setNext(Nodo* next){
        this->next = next;
    }


    friend ostream& operator<<(ostream& out, const Nodo& node){
        out << "-Proiezione = " << node.proiezione << " - Titolo:" << node.titolo << " -Genere:" << node.genere << endl;
        return out;
    }

};

