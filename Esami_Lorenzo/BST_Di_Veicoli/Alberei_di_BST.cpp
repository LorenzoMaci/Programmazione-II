#include <iostream>

using namespace std;

class Veicolo{
    private:
    string targa;
    string nome;
    int anno;
    string marca;
    int cilindrata; 
    public:
    Veicolo(string targa, string nome, int anno, string marca, int cilindrata) : targa(targa), nome(nome), anno(anno), marca(marca), cilindrata(cilindrata){}

    virtual void stampa() = 0;

    string getTarga(){
        return targa;
    }

    string getNome(){
        return nome;
    }

    int getAnno(){
        return anno;
    }

    string getMarca(){
        return marca;
    }

    int getCilindrata(){
        return cilindrata;
    }

    friend bool operator<(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) < 0;}
    friend bool operator>(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) > 0;}
    friend bool operator==(const Veicolo& v1, const Veicolo& v2) { return v1.targa.compare(v2.targa) == 0;}
};

class Auto : public Veicolo{
    private:
    int numero_porte;

    public:
    Auto(string targa, string nome, int anno, string marca, int cilindrata , int numero_porte) : Veicolo(targa,nome,anno,marca,cilindrata){
        this->numero_porte = numero_porte;
    }
    
    int getNumero(){return numero_porte;}

    void stampa(){
        cout << "\t Automobile: " << endl;
        cout << "-Targa :" << getTarga() << " ";
        cout << "-Nome Modello: " << getNome() << endl;
        cout << "-Marca: " << getMarca() << " -Anno di fabrica: " << getAnno() << endl;
        cout <<  "-Cilindrata: "<< getCilindrata() <<" -Numero porte: " << numero_porte << endl; 
    } 
};

class Moto : public Veicolo{
    private:
    string tipo_moto;

    public:
    Moto(string targa, string nome, int anno, string marca,int cilindrata, string tipo_moto) : Veicolo(targa,nome,anno,marca,cilindrata){
        this->tipo_moto = tipo_moto;
    }

    void stampa() {
        cout << "\nMoto: " << endl;
        cout << "-Targa: " << getTarga() << " -Nome modello: "<< getNome() << endl;
        cout << "-Marca: " << getMarca() << " -Anno di fabrica: " << getAnno() << endl;
        cout <<  "-Cilindrata: "<< getCilindrata() << " -Tipo moto: " << tipo_moto << endl;
    }
};



class Nodo{
    Veicolo* vec;
    Nodo* left;
    Nodo* right;
    Nodo* parent;

    friend class BST;

    public:
    Nodo(Veicolo* vec1) : vec(vec1){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    Nodo* getLeft(){
        return left;
    }

    Nodo* getRight(){
        return right;
    }

    Nodo* getParent(){
        return parent;
    }

    Veicolo* getVec(){
        return vec;
    }

    void setLeft(Nodo* left){
        this->left = left;
    }

    void setRight(Nodo* right){
        this->right = right;
    }

    void setParent(Nodo* parent){
        this->parent = parent;
    }

    void setVeicolo(Veicolo* vec){
        this->vec = vec;
    }
};


class BST{
    private:
    Nodo* root;

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

    
    
    Veicolo* TrovaVeicolo(string targa){    
        // Trova il nodo (se esiste)
        Nodo* nodo = search(targa);

        // restituisce il veicolo
        if(nodo != nullptr){
            return nodo->getVec();
        }else{
            cout << "Veicolo non trovato" << endl;
            return nullptr;
        }
    }


    void DistruggiBST(Nodo* nodo){
        if(nodo == nullptr)
            return;
    
        DistruggiBST(nodo->getLeft());
        DistruggiBST(nodo->getRight());
        delete nodo;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(Veicolo* vec){
        insert(root,vec);
    }

    void insert(Nodo* p, Veicolo*vec){
        if(this->root == nullptr){
            root = new Nodo(vec);
            return;
        }
        Nodo* v = new Nodo(vec);
        if(v->getVec()->getTarga() <= p->getVec()->getTarga() && p->getLeft() == nullptr){
            Nodo* node = new Nodo(vec);
            p->setLeft(node);
            node->setParent(p);        
        }
        else if(v->getVec()->getTarga()  > p->getVec()->getTarga() && p->getRight() == nullptr){
            Nodo* node = new Nodo(vec);
            p->setRight(node);
            node->setParent(p);
        }
        else if(v->getVec()->getTarga() <= p->getVec()->getTarga() && p->getLeft() != nullptr){
            insert(p->getLeft(), vec);
        }
        else if(v->getVec()->getTarga() > p->getVec()->getTarga() && p->getRight() != nullptr){
            insert(p->getRight(), vec);
        }
    }

    void trapianta(Nodo* u, Nodo* v){
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

    Nodo* min(){
        return min(root);
    }

    Nodo* min(Nodo* x){
        if(this->isEmpty()){
            return nullptr;
        }
        Nodo* nMin = x;
        while(nMin->getLeft()){
            nMin = nMin->getLeft();
        }
        return nMin;
    }

    void remove(string targa){
        if(this->isEmpty()){
            cout << "Empty BST " << endl;
            return;
        }

        Nodo* p = search(targa);
        
        if(p->getLeft() == nullptr){
            trapianta(p, p->getRight());
        }
        else if(p->getRight() == nullptr){
            trapianta(p, p->getLeft());
        }
        else{
            Nodo* y = min(p->getRight());
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
    }

    Nodo* search(string targa){
        return search(root, targa);
    }

    Nodo* search(Nodo* p, string targa){
        if(p == nullptr){
            return nullptr;
        }

        if(targa == p->getVec()->getTarga()){
            return p;
        }

        if(targa <= p->getVec()->getTarga()){
            return search(p->getLeft(),targa);
        }
        else {
            return search(p->getRight(), targa);
        }
        return nullptr;
    }

    void preOrder(){
        preOrder(root);
    }

    void preOrder(Nodo* p){
        if(p != nullptr){
            p->getVec()->stampa();
            preOrder(p->getLeft());
            preOrder(p->getRight());
        }
    }

    void inorder(){
        inorder(root);
    }

    void inorder(Nodo* p){
        if(p != nullptr){
            inorder(p->getLeft());
            p->getVec()->stampa();
            inorder(p->getRight());
        }
    }
};

int main() {
    BST albero;

    Auto panda("1", "Panda FIRE", 1986, "FIAT", 769, 3);
    Auto ferrari("3", "Ferrari Testarossa",  1984, "Ferrari",4943, 3);
    Moto r3("4", "YZF-R3", 2014, "Yamaha", 249, "Sportiva");
    Auto peugeot("5", "Peugeot 208",  2019,"Peugeot", 1199, 5);
    Moto xlv("6", "Honda Africa Twin 650",  1983, "Honda", 749, "Enduro");
    // Creazione dei veicoli
 
    // Inserimento dei veicoli nell'albero
    albero.insert(&ferrari);
    albero.insert(&panda);
    albero.insert(&peugeot);
    albero.insert(&r3);
    albero.insert(&xlv);


    //Visualizzazione pre e inorder
    cout << endl;
    cout << "PreOrder: "<< endl;
    albero.preOrder();

    cout << endl << endl;
    cout << "Inorder " << endl;
    albero.inorder();

    //Cerco il veicolo 
    Veicolo* v = albero.TrovaVeicolo("3");
    if (v != nullptr)
        v->stampa();
    else
        cout << "Veicolo non trovato" << endl;

    cout << endl << endl;
    cout << "Elimino veicolo con targa 3 e 5 " << endl;
    // Eliminazione dei veicoli con targa 3 e 5
    albero.remove("3");
    albero.remove("5");

    // Stampa con visita Pre-Order
    cout << "Verifica post eliminazione " << endl;
    albero.preOrder();

}
