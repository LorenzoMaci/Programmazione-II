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
        cout << titolo << " - " << autore << " -" << anno << " - " << genere() << endl;
   } 

};

class Romanzo : public Libro{
    string genere_romanzo;

    public:
    Romanzo(string titolo, string autore, int anno, string genere_romanzo) : Libro(titolo, autore, anno){
        this->genere_romanzo = genere_romanzo;
    }
    
    string genere(){
        return genere_romanzo;
    }
};

class Saggio : public Libro{
    string genere_saggio;

    public:
    Saggio(string titolo, string autore, int anno, string genere_saggio) : Libro(titolo, autore, anno){
        this->genere_saggio = genere_saggio;
    }

    string genere(){
        return genere_saggio;
    }
};

template <typename T>
class Nodo{
    private:
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

    Libro* getLibro(){
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

    void setLibro(Libro* vec){
        this->vec = vec;
    }
};

template <typename T>
class BST{
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
        DistruggiBST(root);
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void DistruggiBST(Nodo<T>* node){
        if(node == nullptr){
            return;
        }
        DistruggiBST(node->getLeft());
        DistruggiBST(node->getRight());

        delete node;
    }

    void insert(Libro* vec){
        insert(root, vec);
    }

    void insert(Nodo<T>* p, Libro* vec){
        if(this->root == nullptr){
            root = new Nodo<T>(vec);
            return;
        }

        Nodo<T>* libro = new Nodo<T>(vec);
        if(libro->getLibro()->getTitolo() <= p->getLibro()->getTitolo() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(vec);
            p->setLeft(node);
            node->setParent(p);
        }
        else if(libro->getLibro()->getTitolo() > p->getLibro()->getTitolo() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(vec);
            p->setRight(node);
            node->setParent(p);
        }
        else if(libro->getLibro()->getTitolo() <= p->getLibro()->getTitolo() && p->getLeft() != nullptr){
            insert(p->getLeft(), vec);
        }
        else if(libro->getLibro()->getTitolo() > p->getLibro()->getTitolo() && p->getRight() != nullptr){
            insert(p->getRight(), vec);
        }
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if(u->getParent() == nullptr){
            root = v;
        }
        else if(u == u->getParent()->getLeft()){
            u->getParent()->setLeft(v);
        }else{
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

    Nodo<T>* search(string titolo){
        return search(root, titolo);
    }

    Nodo<T>* search(Nodo<T>* p, string titolo){
        if(p == nullptr){
            return nullptr;
        }

        if(titolo == p->getLibro()->getTitolo()){
            return p;
        }
        else if(titolo < p->getLibro()->getTitolo()){
            return search(p->getLeft(), titolo);
        }
        else{
            return search(p->getRight(),titolo);
        }
        return nullptr;
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
        }
        else if(p->getRight() == nullptr){
            trapianta(p, p->getLeft());
        }
        else{
            Nodo<T>* y = min(p->getRight());
            if(y->getParent() != p){
                trapianta(y,y->getRight());
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
            p->getLibro()->stampa();
            inorder(p->getRight());
        }
    }
};

int main(){
    BST<Libro*> bst;

    Libro* libro1 = new Romanzo("il nome della rosa", "Umberto Eco", 1980, "Romanzo");
    Libro* libro2 = new Romanzo("Il mondo nuovo", "Aldous Huxley", 1932, "Romanzo");
    Libro* libro3 = new Saggio("Breve storia del tempo", "Stephen Hawking",  1988, "Saggio");
    Libro* libro4 = new Romanzo("Orgoglio e pregiudizio", "Jane Austen", 1813," Romanzo");
    Libro* libro5 = new Saggio("Il gene egoista", "Richard Dawkins", 1976, "Saggio");
    Libro* libro6 = new Romanzo("Il signore degli anelli",  "J.R.R. Tolkien",  1954, "Romanzo");

    //Inserimento nel BST dei Libri
    bst.insert(libro1);
    bst.insert(libro2);
    bst.insert(libro3);
    bst.insert(libro4);
    bst.insert(libro5);
    bst.insert(libro6);

    //Visualizzazione inorder
    cout << endl;
    cout << "Visita InOrder "<< endl;
    bst.inorder();

    //L'utente inserisci il libro da rimuovere
    string titolo; 
    cout << "Inserisci il libro da rimuovere " << endl;
    getline(cin, titolo); //Serve il getLine per scrivere un intero titolo, la stringa viene considerata come una singola parola
    if(bst.remove(titolo)){
        cout << "il libro " << titolo << " è stato rimosso con successo " << endl;
        cout << "il BST adesso è: " << endl;
        bst.inorder();
    }
    else{
        cout << "il libro non è stato trovato all'interno dell'albero "  << endl;
    }
    return 0; 
}