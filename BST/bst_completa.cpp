// Definire una classe BST che implementi:
// - inserimento
// - visite (inorder, preorder e postorder)
// - cancellazione di un nodo

#include <iostream>
using namespace std;

class Nodo { //implementazione nodo
public:
    int val;  //valore
    Nodo* left; //sinistra
    Nodo* right; //destra
    Nodo* parent; //genitore
};


class BST{
    private:
    Nodo* root; //radice
    int numElem =0; //dimenzione
    void inOrder(Nodo* p)const; //procedura inorder
    void preOrder(Nodo* p)const; // procedura postorder
    void postOrder(Nodo* p)const; //procedura postOrder

    //procedure ausiliarie per la cancellazione
    void cancella(Nodo *); //cancella il nodo
    void trapianta(Nodo* u, Nodo* v); //trapianta le foglie
    Nodo* minimo(Nodo* x); //trova il minimo
    Nodo* massimo(Nodo* x);
    public:
    BST(): root(nullptr){};  //costruttore pongo root = nullptr
    void insert(int valore); //inserimento del valore 
    void inOrder()const; // sx rad dx
    void preOrder()const;// rad sx dx
    void postOrder()const;// sx dx rad

    int altezza(Nodo* p)const; //restituise l'altezza sinistra o destra

    bool cancella(int x); //elimina il valore
    int minimo(); //minimo
    int max();

    friend
    ostream& operator<<(ostream& out, const BST& t);

};


void BST::inOrder(Nodo* p) const{ //procedura inorder
    if(p!=nullptr){ //se p != nullptr
        inOrder(p->left); //ordino p->sinistro
        cout << p->val << "\t"; //scrivo il p->val
        inOrder(p->right); //ordino p->destro
    }
}
//versione pubblica
void BST::inOrder() const {inOrder(root);} //richiama inOrder(radice)


void BST::preOrder(Nodo* p) const{ //procedura preOrder
    if(p!=nullptr){ //se p != nullptr
        cout << p->val << "\t"; //scrivo il p->val
        preOrder(p->left);// preOrdino p->left
        preOrder(p->right); // perOrdino p->right
    }
}
//versione pubblica
void BST::preOrder()const {preOrder(root);} //richiamo preOrder(RADICE)



void BST::postOrder(Nodo* p) const{ //procedura postOrder
    if(p!=nullptr){ //se p != nullptr
        postOrder(p->left); //postOrdino p->left
        postOrder(p->right); // postOrdino p->right
        cout << p->val << "\t"; //scrivo il valore
    }
}
//versione pubblica
void BST::postOrder()const {postOrder(root);} //richiamo postOrder(radice)

void BST::insert(int valore){ //inserisco il valore

    Nodo* nuovo = new Nodo; //dichiaro un nuovo nodo 
    Nodo* x = root, *y = nullptr; //pongo un nodo *x = root e *y = nullptr

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
void stampaLivello(Nodo* p, int level){ // stampa i nodi ad un dato livello
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

int BST::altezza(Nodo* p)const{ //altezza
    if (p==nullptr) return 0; //se p = nullptr fai return 0

    int lh = altezza(p->left); // dichiaro una variabile lh(left height) e la pongo = altezza(p->left)
    int rh = altezza(p->right);//dichiaro una variabile rh(right height) e la pongo = altezza(p->right)

    if(lh>rh)   return (lh+1); //se left height > right height fai return (lh + 1)
    else        return (rh+1); // altrimenti fai return (rh + 1)
}


ostream& operator<<(ostream&out, const BST& t){ //ostream 
    int h = t.altezza(t.root); //pongo una variabile h (height) = al richiamo dell'albero t.altezza(t.root)
    cout << "Albero di altezza " << h << endl; //scrivo l'altezza h
    for(int i=0;i<h;i++){ //creo un ciclo for minore dell'altezza h dell'albero
        stampaLivello(t.root, i); //richiamo stampalivello(t.root, i)
        cout << endl;
    }
    return out; //return out (ostream)
}

void BST::trapianta(Nodo* u, Nodo* v){ 

    if(u->parent == nullptr) // se u e' la radice ed == nullptr 
        root = v; //pongo la radice = v
    else if (u == u->parent->left) // se u è = e' figlio sx del  padre di u u->parent->left
        u->parent->left = v; //pongo u->parent->left = v
    else  
        u->parent->right = v; //altrimenti pongo il figlio destro, del padre di u (u->parent->right) = v 
    if(v!=nullptr) //se v è diverso da nullptr pongo v->genitore = u->genitore
        v->parent = u->parent;
}

int BST::minimo(){ //cerco la radice minima
    Nodo* nMin = minimo(root); //pongo un nodo nMin = al minimo della radice
    return nMin->val; //restituiscio il valore minimo nMin ->val
}

Nodo* BST::minimo(Nodo* x){
    //bisognerebbe controllare che x!=nullptr
    Nodo* nMin =x; //pongo un nodo nMin = x
    while(nMin->left != nullptr) //utilizzo un ciclo while con condizione se (il minimo sinistro è diverso nullptr) esiste il nMin->left 
        nMin = nMin->left; //pongo nMin = nMin->left
    return nMin; //restituisco nMin
}

int BST::max(){
    Nodo* nMax = massimo(root);
    return nMax->val;
}

Nodo* BST::massimo(Nodo* x){
    Nodo* nMax = x;
    while(nMax->right != nullptr){
        nMax = nMax->right;
    }
    return nMax;
}

void BST::cancella(Nodo* z){ //cancellazione del Nodo
    Nodo* y; //creo un Nodo * y
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



bool BST::cancella(int x){
    Nodo* iter = root; //pongo un nodo* iter = radice
    // ricerca di un nodo con chiave x
    while((iter!=nullptr) && (x!=iter->val)){ //utilizzo un ciclo while con condizione se (iter esiste(iter != nullptr)) e (x != valore di iter)
        if(x< iter->val) //se x < valore di iter (iter->val)
            iter = iter->left; //pongo iter = al figlio sinistro di iter (iter->left)
        else //altrimenti
            iter = iter->right; //pongo iter = al figlio destro di iter (iter->right)
    }
    if(iter == nullptr) // se iter non esiste (iter == nullptr)
        return false; //resituisci falso
    // chiamo la procedura cancella(iter) 
    cancella(iter);
    return true; //restituisco vero
}

int main(){
    BST tree;
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
    BST tree1;
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