// Definire una classe BST che implementi:
// - inserimento
// - visite (inorder, preorder e postorder)
// - cancellazione di un nodo

#include <iostream>
using namespace std;

template<typename T>
class Nodo { //implementazione nodo
public:
    T val;  //valore
    Nodo<T>* left; //sinistra
    Nodo<T>* right; //destra
    Nodo<T>* parent; //genitore
};

template<typename T>
class BST{
    private:
    Nodo<T>* root; //radice
    int numElem =0; //dimenzione
    void inOrder(Nodo<T>* p)const; //procedura inorder
    void preOrder(Nodo<T>* p)const; // procedura postorder
    void postOrder(Nodo<T>* p)const; //procedura postOrder

    //procedure ausiliarie per la cancellazione
    void cancella(Nodo<T>*); //cancella il nodo
    void trapianta(Nodo<T>* u, Nodo<T>* v); //trapianta le foglie
    Nodo<T>* minimo(Nodo<T>* x); //trova il minimo
    Nodo<T>* massimo(Nodo<T>* x);
    public:
    BST(): root(nullptr){};  //costruttore pongo root = nullptr
    void insert(T valore); //inserimento del valore 
    void inOrder()const; // sx rad dx
    void preOrder()const;// rad sx dx
    void postOrder()const;// sx dx rad

    int altezza(Nodo<T>* p)const; //restituise l'altezza sinistra o destra

    bool cancella(T x); //elimina il valore
    int minimo(); //minimo
    int max();

    template<typename U>
    friend ostream& operator<<(ostream& out, const BST<U>& t);

};

template<typename T>
void BST<T>::inOrder(Nodo<T>* p) const{ //procedura inorder
    if(p!=nullptr){ //se p != nullptr
        inOrder(p->left); //ordino p->sinistro
        cout << p->val << "\t"; //scrivo il p->val
        inOrder(p->right); //ordino p->destro
    }
}
//versione pubblica
template<typename T>
void BST<T>::inOrder() const {inOrder(root);} //richiama inOrder(radice)

template<typename T>
void BST<T>::preOrder(Nodo<T>* p) const{ //procedura preOrder
    if(p!=nullptr){ //se p != nullptr
        cout << p->val << "\t"; //scrivo il p->val
        preOrder(p->left);// preOrdino p->left
        preOrder(p->right); // perOrdino p->right
    }
}
//versione pubblica
template<typename T>
void BST<T>::preOrder()const {preOrder(root);} //richiamo preOrder(RADICE)


template<typename T>
void BST<T>::postOrder(Nodo<T>* p) const{ //procedura postOrder
    if(p!=nullptr){ //se p != nullptr
        postOrder(p->left); //postOrdino p->left
        postOrder(p->right); // postOrdino p->right
        cout << p->val << "\t"; //scrivo il valore
    }
}
//versione pubblica
template<typename T>
void BST<T>::postOrder()const {postOrder(root);} //richiamo postOrder(radice)

template<typename T>
void BST<T>::insert(T valore){ //inserisco il valore

    Nodo<T>* nuovo = new Nodo<T>; //dichiaro un nuovo nodo 
    Nodo<T>* x = root ;
    Nodo<T>* y = nullptr; //pongo un nodo *x = root e *y = nullptr

    nuovo->val = valore; //pongo nuovo->val = valore;
    nuovo->left = nuovo->right = nullptr; //pongo nuovo->left = nuovo ->right = nullptr

    while(x!=nullptr){ //utilizzo un ciclo while dove se x != nullptr
        y=x; //pongo y = x
        if(valore< x->val) //Se valore è minore x->val
            x = x->left; //pongo x = x->left
        else 
            x = x->right; //altrimenti pongo x = x->right
    }

    nuovo->parent = y; //pongo nuovo->parent = y
    if(y==nullptr) //se y == nullptr
        root = nuovo; //pongo la radice = nuovo
    else if(valore<y->val) //altrimenti se valore < y->val
        y->left = nuovo; //pongo y->left = nuovo
    else 
        y->right = nuovo; //Altrimenti y->right = nuovo

    numElem++; //aumento la dimenzione
}

//NB: questa puo' essere sfruttata da operator<<
template<typename T>
void stampaLivello(Nodo<T>* p, int level){ // stampa i nodi ad un dato livello
    // p punta ad una posizione vuota
    if(p == nullptr){ //se p == nullptr
        if (level==0) cout << "_\t"; //se il livello = 0, scrivo "_\t" e faccio return
        return;
    }

    if(level == 0) //se il livello è uguale a 0 scrivo il valore di p (p->val)
       cout << p->val << "\t";
    else if(level>0){ //altrimenti se il livello è > 0
        stampaLivello(p->left,level-1); //richiama stampalivello(p->left, level -1)
        stampaLivello(p->right,level-1); //richiama stampalivello(p->right, level - 1)
    }

}

template<typename T>
int BST<T>::altezza(Nodo<T>* p)const{ //altezza
    if (p==nullptr) return 0; //se p = nullptr fai return 0

    int lh = altezza(p->left); // dichiaro una variabile lh(left height) e la pongo = altezza(p->left)
    int rh = altezza(p->right);//dichiaro una variabile rh(right height) e la pongo = altezza(p->right)

    if(lh>rh)   return (lh+1); //se left height > right height fai return (lh + 1)
    else        return (rh+1); // altrimenti fai return (rh + 1)
}

template<typename T>
ostream& operator<<(ostream&out, const BST<T>& t){ //ostream 
    int h = t.altezza(t.root); //pongo una variabile h (height) = al richiamo dell'albero t.altezza(t.root)
    cout << "Albero di altezza " << h << endl; //scrivo l'altezza h
    for(int i=0;i<h;i++){ //creo un ciclo for minore dell'altezza h dell'albero
        stampaLivello(t.root, i); //richiamo stampalivello(t.root, i)
        cout << endl;
    }
    return out; //return out (ostream)
}

template<typename T>
void BST<T>::trapianta(Nodo<T>* u, Nodo<T>* v){ 

    if(u->parent == nullptr) // se u e' la radice ed == nullptr 
        root = v; //pongo la radice = v
    else if (u == u->parent->left) // se u è = e' figlio sx del  padre di u u->parent->left
        u->parent->left = v; //pongo u->parent->left = v
    else  
        u->parent->right = v; //altrimenti pongo il figlio destro, del padre di u (u->parent->right) = v 
    if(v!=nullptr) //se v è diverso da nullptr pongo v->genitore = u->genitore
        v->parent = u->parent;
}

template<typename T>
int BST<T>::minimo(){ //cerco la radice minima
    Nodo<T>* nMin = minimo(root); //pongo un nodo nMin = al minimo della radice
    return nMin->val; //restituiscio il valore minimo nMin ->val
}

template<typename T>
Nodo<T>* BST<T>::minimo(Nodo<T>* x){
    //bisognerebbe controllare che x!=nullptr
    Nodo<T>* nMin =x; //pongo un nodo nMin = x
    while(nMin->left != nullptr) //utilizzo un ciclo while con condizione se (il minimo sinistro è diverso nullptr) esiste il nMin->left 
        nMin = nMin->left; //pongo nMin = nMin->left
    return nMin; //restituisco nMin
}

template<typename T>
int BST<T>::max(){
    Nodo<T>* nMax = massimo(root);
    return nMax->val;
}

template<typename T>
Nodo<T>* BST<T>::massimo(Nodo<T>* x){
    Nodo<T>* nMax = x;
    while(nMax->right != nullptr){
        nMax = nMax->right;
    }
    return nMax;
}

template<typename T>
void BST<T>::cancella(Nodo<T>* z){ //cancellazione del Nodo
    Nodo<T>* y; //creo un Nodo * y
    //Caso 1: z ha un solo figlio
    if(z->left == nullptr) //se z->sinistro è = nullptr (z non ha figlio sx)
        trapianta(z, z->right); // richiamo trapianta(z, z->right)
    else if(z->right == nullptr) // altrimenti se z->destro è = nullptr (z non ha figlio dx)
        trapianta(z, z->left); // richiamo trapianta(z, z->right)
    // altrimenti... caso 3: z ha entrambi i figli
    else{ //altrimenti
        y = minimo(z->right); // pongo y = minimo(z->right) praticamente sarà il successore di destra
        // se y non e' figlio di z devo gestire y.right e z.right
        if(y->parent!=z){ // tradotto in se y->genitore != z (y non è figlio di z)
            trapianta(y, y->right); //richiamo trapianta(y, y->right)
            y->right = z->right; //pongo y->right = z->right
            y->right->parent = y; //pongo y->right->parent = y
        }

        trapianta(z,y); //richiamo trapianta(z, y)
        y->left = z->left; //pongo y->sinistro = z->sinistro
        y->left->parent = y; //pongo y->sinistro->genitore = y
    }
    delete z; //rimuovo z
}


template<typename T>
bool BST<T>::cancella(T x){
    Nodo<T>* toInsert = root;
    // ricerca di un nodo con chiave x
    while((toInsert!=nullptr) && (x!=toInsert->val)){ //utilizzo un ciclo while con condizione se (iter esiste(iter != nullptr)) e (x != valore di iter)
        if(x< toInsert->val) //se x < valore di iter (iter->val)
            toInsert = toInsert->left; //pongo iter = al figlio sinistro di iter (iter->left)
        else //altrimenti
            toInsert = toInsert->right; //pongo iter = al figlio destro di iter (iter->right)
    }
    if(toInsert == nullptr) // se iter non esiste (iter == nullptr)
        return false; //resituisci falso
    // chiamo la procedura cancella(iter) 
    cancella(toInsert);
    return true; //restituisco vero
}

int main(){
    BST<int> tree;
    tree.insert(6);
    tree.insert(5);
    tree.insert(7);
    tree.insert(2);
    tree.insert(8);
    tree.insert(4);

    cout << tree << endl;


    cout << "Visita inorder:\t\t";
    tree.inOrder();
    cout << endl;
    cout << "Visita preorder:\t";
    tree.preOrder();
    cout << endl;
    cout << "Visita postorder:\t";
    tree.postOrder();

    int v = 7;
    cout << endl << "Cancello il nodo con chiave " << v << endl;
    if(!tree.cancella(v))
        cout << "Elemento non trovato nell'albero." << endl;

    cout << endl << tree << endl;

    // albero pieno e bilanciato
    BST<int> tree1;
    tree1.insert(8);
    tree1.insert(5);
    tree1.insert(18);
    tree1.insert(2);
    tree1.insert(6);
    tree1.insert(19);
    tree1.insert(16);

    cout << tree1 << endl;

    tree1.cancella(18);
    cout << tree1;
    return 0;
}