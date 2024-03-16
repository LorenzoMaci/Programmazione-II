#include <iostream>

using namespace std;

class Veicolo{
    private:
    string targa;
    string modello;
    int anno;
    string marca;
    int cilindrata;

    public:
    Veicolo(string targa, string modello, int anno, string marca, int cilindrata) : targa(targa), modello(modello), anno(anno), marca(marca), cilindrata(cilindrata){}

    string getTarga(){
        return targa;
    }

    string getModello(){
        return modello;
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

    virtual void stampa() = 0;

};

class Auto : public Veicolo{
    private:
    int numero_porte;

    public:
    Auto(string targa, string modello, int anno, string marca, int cilindrata, int numero_porte) : Veicolo(targa, modello, anno, marca, cilindrata){
        this->numero_porte = numero_porte;
    } 

    void stampa(){
        cout << "Auto: " << endl;
        cout << "Targa: " << getTarga() << " Nome modello: " << getModello() << endl;
        cout << "Marca: " << getMarca() << " Anno di fabricazione: " << getAnno() << endl;
        cout << "Cilindrata: " << getCilindrata() << " Numero porte: "<< numero_porte << endl; 
    }
};

class Moto : public Veicolo{
    private:
    string tipo_moto;

    public:
    Moto(string targa, string modello, int anno, string marca, int cilindrata, string tipo_moto) : Veicolo(targa, modello, anno, marca, cilindrata){
        this->tipo_moto = tipo_moto
    }

    void stampa(){
        cout << "Moto: " << endl;
        cout << "Targa: " << getTarga() << " Nome modello: " << getModello() << endl;
        cout << "Marca: " << getMarca() << " Anno di fabricazione: " << getAnno() << endl;
        cout << "Cilindrata: " << getCilindrata() << " Tipo Moto: "<< tipo_moto << endl;
    }
};

class Nodo{
    private:
    Veicolo* vec;
    Nodo* left;
    Nodo* right;
    Nodo* parent;

    friend class BST;

    public:
    Nodo(Veicolo* vec) : vec(vec){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    Veicolo* getVec(){
        return vec;
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

    void setLeft(Nodo* left){
        this->left = left;
    }

    void setRight(Nodo* right){
        this->right = right;
    }

    void setParent(Nodo* parent){
        this->parent = parent;
    }
};

class BST{
    private:
    Nodo* root;

    public:
    BST(){
        this->root = nullptr;
    }


    bool isEmpty(){
        return root == nullptr;
    }

    void insert(Veicolo* vec){
        insert(root, vec);
    }

    void insert(Nodo* p, Veicolo* vec){
        if(this->root == nullptr){
            root = new Nodo(vec);
            return;
        }

        Nodo* veicolo = new Nodo(vec);
        if(veicolo->getVec()->getTarga() <= p->getVec()->getTarga() && p->getLeft() == nullptr){
            Nodo* node = new Nodo(vec);
            p->setLeft(node);
            node->setParent(p);
        }
        else if(veicolo->getVec()->getTarga() > p->getVec()->getTarga() && p->getRight() == nullptr){
            Nodo* node = new Nodo(vec);
            p->setRight(node);
            node->setParent(p);
        }
        else if(veicolo->getVec()->getTarga() <= p->getVec()->getTarga() && p->getLeft() != nullptr){
            insert(p->getLeft(), vec);
        }
        else if(veicolo->getVec()->getTarga() > p->getVec()->getTarga() && p->getRight() != nullptr) {
            insert(p->getRight(), vec);
        }   
    }

    Nodo* search(string targa){
        return search(root, targa);
    }

    Nodo* search(Nodo* p, string targa){
        if(p == nullptr){
            return  nullptr;
        }

        if(targa == p->getVec()->getTarga()){
            return p;
        }

        if(targa <= p->getVec()->getTarga()){
            return search(p->getLeft(), targa);
        }
        else{
            return search(p->getRight(), targa);
        }
        return nullptr;
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


    void trapianta(Nodo* u, Nodo*  v){
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

    void remove(string targa){
        if(this->isEmpty()){
            cout << "Empty BST " << endl;
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
                trapianta(y, y->getRight());
                y->setRight(p->getRight());
                y->getRight()->setParent(y);
            }
            trapianta(p, y);
            y->setLeft(p->getLeft());
            y->getLeft()->setParent(y);
        }
        delete p;
    }
};

int main(){
    BST bst;

    Veicolo* vec1 = new Auto("1", "Panda FIRE", 1986, "Fiat", 769, 3);
    Veicolo* vec2 = new Auto("3", "Ferrari Testarossa", 1984, "Ferrari", 4943, 3);
    Veicolo* vec3 = new Moto("4", "YZF-R3", 2014, "Yamaha", 249, "Sportiva");
    Veicolo* vec4 = new Auto("5", "Peugeot 208", 2019, "Peugeot", 1199, 5);
    Veicolo* vec5 = new Moto("6", "Honda Africa Twin 650", 1983, "Honda", 749, "Enduro");

    bst.insert(vec2);
    bst.insert(vec1);
    bst.insert(vec4);
    bst.insert(vec3);
    bst.insert(vec5);

    cout << "BST InOrder e PreOrder " << endl;
    cout << "Inorder: "<< endl;
    bst.inorder();

    cout << endl;
    cout << "preOrder: " << endl;
    bst.preOrder();
    cout << endl;
    
    cout <<"Elimino i veicoli con la targa 3 e 5" << endl;
    bst.remove("3");
    bst.remove("5");

    cout << endl;
    cout << "La BST aggiornata è " << endl;
    bst.preOrder();
}