#include <iostream>
#include <fstream>

using namespace std;

class Libro{
    private:
    string titolo;
    string autore;
    int anno;

    public:
    Libro(string titolo, string autore, int anno) : titolo(titolo), autore(autore), anno(anno){}

    string getTitolo(){
        return titolo;
    }

    string getAutore(){
        return autore;
    }

    int getAnno(){
        return anno;
    }

    virtual string genere() = 0;

    void stampa(){
        cout << titolo << " - " << autore << " - " << anno <<" - " << genere() << endl;
    }

    friend ostream& operator<<(ostream& out, Libro& l){
        l.stampa();
        return out;
    }
};


class Romanzo : public Libro{
    public:
    Romanzo(string titolo, string autore, int anno) : Libro(titolo, autore, anno){}

    string genere(){
        return "Romanzo";
    }

    friend ostream& operator<<(ostream& out, Romanzo& r){
        out << static_cast<Libro&>(r);
        return out;
    }
};

class Saggio : public Libro{
    public:
    Saggio(string titolo, string autore, int anno) : Libro(titolo, autore, anno){}

    string genere(){
        return "Saggio";
    }

    friend ostream& operator<<(ostream& out, Saggio& s){
        out << static_cast<Libro&>(s);
        return out;
    }
};

template <typename T>
class Nodo{
    Libro* vec;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;

    template <typename U>
    friend class BST;

    public:
    Nodo(Libro* vec) : vec(vec){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    Nodo<T>* getLeft(){
        return left;
    }

    Nodo<T>* getRight(){
        return right;
    }

    Nodo<T>* getParent(){
        return parent;
    }

    Libro* getVec(){
        return vec;
    }

    void setLeft(Nodo<T>* left){
        this->left = left;
    }

    void setRight(Nodo<T>* right){
        this->right = right;
    }

    void setParent(Nodo<T>* parent){
        this->parent = parent;
    }
    
};  

template <typename T>
class BST{
    private:
    Nodo<T>* root;
    int size = 0;

    public:
    BST(){
        this->root = nullptr;
    }

    ~BST(){
        if(this->isEmpty()){
            return;
        }
        removeNodo(root);
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(Libro* vec){
        insert(root, vec);
    }

    void removeNodo(Nodo<T>* node){
        if(node == nullptr){
            return;
        }
        removeNodo(node->getLeft());
        removeNodo(node->getRight());

        delete node;
    }
    void insert(Nodo<T>* p, Libro* vec){
        if(this->root == nullptr){
            root = new Nodo<T>(vec);
            size++;
            return;
        }

        Nodo<T>* v = new Nodo<T>(vec);
        
        if(v->getVec()->getTitolo() <= p->getVec()->getTitolo() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(vec);
            p->setLeft(node);
            node->setParent(p);
            size++;
        }
        else if(v->getVec()->getTitolo() > p->getVec()->getTitolo() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(vec);
            p->setRight(node);
            node->setParent(p);
            size++;
        }
        else if(v->getVec()->getTitolo() <= p->getVec()->getTitolo() && p->getLeft() != nullptr){
            insert(p->getLeft(), vec);
        }
        else if(v->getVec()->getTitolo() > p->getVec()->getTitolo() && p->getLeft() != nullptr){
            insert(p->getRight(), vec);
        }
    }

    Nodo<T>* search(string titolo){
        return search(root, titolo);
    }

    Nodo<T>* search(Nodo<T>* p, string titolo){
        if(p == nullptr){
            return nullptr;
        }

        if(p->getVec()->getTitolo() == titolo){
            return p;
        }

        if(titolo <= p->getVec()->getTitolo()){
            search(p->getLeft(), titolo);
        }else{
            search(p->getRight(), titolo);
        }
        return nullptr;
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if(u->getParent() == nullptr){
            root = v;
        }
        else if(u == u->getParent()->getLeft()){
            u->getParent()->setLeft(v);
        }
        else{
            u->getParent()->setRight(v);
        }
        if(v != nullptr){
            v->setParent(u->getParent());
        }
    }

    Nodo<T>* min(){
        return min(root);
    }

    Nodo<T>* min(Nodo<T>* x){
        if(this->isEmpty()){
            return nullptr;
        }

        Nodo<T>* nMin = x;
        while(nMin->getLeft()){
            nMin = nMin->getLeft();
        }
        return nMin;
    }

    bool remove(string titolo){
        if(this->isEmpty()){
            cout << "Empty BST " << endl;
            return false;
        }

        Nodo<T>* p = search(titolo);
        if(!p){
            return false;
        }
        if(p->getLeft() == nullptr){
            trapianta(p, p->getRight());
        }else if(p->getRight() == nullptr){
            trapianta(p, p->getLeft());
        }
        else{
            Nodo<T>* y = min(p->getRight());
            if(y->getParent() != p){
                trapianta(y, y->getRight());
                y->setRight(p->getRight());
                y->getRight()->setParent(y);
            }
            trapianta(p, y);
            y->setLeft(p->getLeft());
            y->getLeft()->setParent(y);
        }
        delete p;
        return true;
    }

    void inorder(){
        inorder(root);
    }

    void inorder(Nodo<T>* p){
        if(p != nullptr){
            inorder(p->getLeft());
            p->getVec()->stampa();
            inorder(p->getRight());
        }
    }
};

int main(){
    BST<Libro>* bst = new BST<Libro>();

    //Inserimento nel BST dei Libri
     bst->insert(new Romanzo("il nome della rosa", "Umberto Eco", 1980));
     bst->insert(new Romanzo("Il mondo nuovo", "Aldous Huxley", 1932));
     bst->insert(new Saggio("Breve storia del tempo", "Stephen Hawking",  1988));
     bst->insert(new Romanzo("Orgoglio e pregiudizio", "Jane Austen", 1813));
     bst->insert(new Saggio("Il gene egoista", "Richard Dawkins", 1976));
    bst->insert(new Romanzo("Il signore degli anelli",  "J.R.R. Tolkien",  1954));

    cout << "BST Inorder" << endl;
    bst->inorder();
    cout << endl;


    string titolo; 
    cout << "Inserisci il libro da rimuovere " << endl;
    getline(cin, titolo);
    if(bst->remove(titolo)){
        cout << "il libro " << titolo << " è stato rimosso con successo " << endl;
        cout << "il BST adesso è: " << endl;
        bst->inorder();
    }
    else{
        cout << " Nessun libro con questo titolo trovato nell'albero. "  << endl;
    }
    return 0; 
}