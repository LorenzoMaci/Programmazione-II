/*DATO IL FILE FILM.TXT che contiene:
 -titolo film
 -stringa che contiene il genere
 -stringa che contiene la data della prima proiezione
scrivere un programma che consente di inserire i dati in una lista ordinata
rispetto alla data, e stampa della lista. Ricerca del film più nuovo
e più vecchio, ed straziioni dei film di un dato genere*/

#include <iostream>
#include <fstream>
#define DIM 9

using namespace std;

class Nodo{
    protected:
    string titolo;
    string genere;
    string data;
    Nodo* next;

    friend class List;

    public:
    Nodo(string data, string titolo, string genere) : data(data), titolo(titolo), genere(genere){
        next = nullptr;
    }

    string& getTitolo(){
        return titolo;
    }

    string& getGenere(){
        return genere;
    }

    string& getData(){
        return data;
    }

    Nodo* getNext(){
        return next;
    }

    void setNext(Nodo* next){
        this->next = next;
    }

    friend ostream& operator<<(ostream& out,Nodo& n){
        out << "-DATA->" <<n.data << " -TITOLO->" << n.titolo << " -GENERE->" << n.genere << endl;
        return out; 
    }
};

class List{
    protected:
    Nodo* head;
    int size = 0;

    public:
    List() {
        head = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    Nodo* getHead()const{
        return head;
    }

    void insert(string data, string titolo, string genere){
        if(this->isEmpty()){
            head = new Nodo( data,  titolo,  genere);
            size++;
            return;
        }
    }

    void insertHead(string data, string titolo, string genere){
        Nodo* temp = new Nodo( data,  titolo,  genere);
        temp->next = head;
        head = temp;
        size++;
    }

    void inserTail(string data, string titolo, string genere){
        if(this->isEmpty()){
            insertHead(data, titolo, genere);
            return;
        }

        Nodo* ptr = head;
        while(ptr->getNext() != nullptr){
            ptr = ptr->getNext();
        }
        Nodo* temp = new Nodo(data, titolo, genere);
        ptr->next = temp;
        size++;
    }

    void insertInOrder(string data, string titolo, string genere){
        if(this->isEmpty()){
            this->insertHead(data, titolo, genere);
            return;
        }

        if(data <= head->getData()){
            this->insertHead(data, titolo, genere);
            return;
        }

        Nodo* ptr = head;
        while(ptr->getNext() && data >= ptr->getData()){
            if(data <= ptr->getNext()->getData()){
                break;
            }
            ptr = ptr->getNext();
        }

        if(!(ptr->getNext())){
            inserTail(data, titolo, genere);
            return;
        }

        Nodo* toInsert = new Nodo(data, titolo, genere);
		toInsert->setNext(ptr->getNext());
		ptr->setNext(toInsert);
		size++;
    }

	void film_piu_nuovo(){
		Nodo *ptr = head;
		while(ptr != nullptr) {
			if(ptr->getNext() == nullptr){
				cout << "Il film più nuovo è: " << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
	}

	void film_piu_vecchio(){
		Nodo *ptr = head;
		cout << "Il film più vecchio è: " << *ptr << endl;
	}

	void film_dato_un_genere(string genere){
		Nodo *ptr = head;
		cout << "I film di genere " << genere << " presenti in lista sono:" << endl;
		while(ptr != nullptr) {
			if(genere == ptr->getGenere()){
				cout << "\t" << *ptr << endl;
			}
			ptr = ptr->getNext();
		}
		cout << endl;
	}
	
	friend ostream& operator<<(ostream& out, const List &list) {
		out << "Lista Film:" << endl;
		Nodo *ptr = list.head;
		while(ptr->getNext() != nullptr) {
			out  << "\t" << *ptr << endl;
			ptr = ptr->getNext();
		}
		out  << "\t" << *ptr << endl;
		return out;
	}
};

int main(){
    ifstream in("film.txt");
    
    List lista;

    //Inserimento ordinato dei film, presi dal file film.txt, nella lista 
    for(int i = 0; i<DIM; i++){
        string tmp;
        getline(in, tmp);
        string nome = "";
        for(int j = 0; j<tmp.length()-2; j++){
            nome += tmp[j];
        }
        //cout << "nome = " << nome << endl;


        getline(in, tmp);
        string genere = "";
        for(int j = 0; j<tmp.length()-2; j++){
            genere += tmp[j];
        }
        //cout << "genere = " << genere << endl;
        
        
        getline(in, tmp);
        string data = "";
        for(int j = 0; j<tmp.length()-2; j++){
            data += tmp[j];
        }
        //cout << "data = " << data << endl << endl;

        lista.insertInOrder(data, nome, genere);
    }

    //Stampa della lista
    cout << lista << endl;

    //Ricerca del film più nuovo
    lista.film_piu_nuovo();

    //Ricerca del film più vecchio
    lista.film_piu_vecchio();

    cout << endl;

    //Estrazione dei film di un dato genere
    lista.film_dato_un_genere("FANTASY");
    lista.film_dato_un_genere("COMMEDIA");
    lista.film_dato_un_genere("MUSICAL");
    lista.film_dato_un_genere("HORROR");
    lista.film_dato_un_genere("DRAMATIC");
    lista.film_dato_un_genere("ANIME");
    lista.film_dato_un_genere("THRILLER");
    lista.film_dato_un_genere("ACTION");
}