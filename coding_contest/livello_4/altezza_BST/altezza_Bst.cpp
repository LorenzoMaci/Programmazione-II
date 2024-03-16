#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class Nodo{
    protected:
    T key;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
    
    template <typename U>
    friend class BST;

    public:
    Nodo(T key) : key(key){
        left = nullptr;
        parent = nullptr;
        right = nullptr;
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

    Nodo<T>* getLeft(){
        return left;
    }

    Nodo<T>* getRight(){
        return right;
    }

    Nodo<T>* getParent(){
        return parent;
    }

    T getKey(){
        return key;
    }
};

template<typename T>
class BST{
    private:
    Nodo<T>* root;

    public:
    BST() {root = nullptr;}

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if(root == nullptr){
            root = new Nodo<T>(key);
            return;
        }  
        if(key <= p->getKey() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if( key > p->getKey() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if( key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRight() != nullptr){
            insert(p->getRight(), key);
        }
    }

    Nodo<T>* search(T key){
        return search(root, key);
    }

    Nodo<T>* search(Nodo<T>* p, T key){
        if(p == nullptr){
            return nullptr;
        }
        if(p->getKey() == key){
            return p;
        }
        if(key <= p->getKey()){
            search(p->getLeft(), key);
        }else{
            search(p->getRight(), key);
        }
        return nullptr;   
    }

    Nodo<T>* min(){
        return min(root);
    }

    Nodo<T>* min(Nodo<T>* x){
        Nodo<T>* nMin = x;
        while(nMin->getLeft()){
            nMin = nMin->getLeft();
        }
        return nMin;
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if(u->getParent() == nullptr){
            root = v;
        }else if(u == u->getParent()->getLeft()){
            u->getParent()->setLeft(v);
        }else{
            u->getParent()->setRight(v);
        }
        if(v != nullptr){
            v->setParent(u->getParent());
        }
    }

    void remove(T key){
        Nodo<T>* p = search(key);
        if(p->getLeft() == nullptr){
            trapianta(p, p->getRight());
        }else if(p->getRight() == nullptr){
            trapianta(p, p->getLeft());
        }else{
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
    }

    int altezza(){
        return altezza(root);
    }

    int altezza(Nodo<T>* p){
        if( p == nullptr){
            return 0;
        }

        int lh = altezza(p->getLeft());
        int rh = altezza(p->getRight());

        if(lh > rh){
            return (lh +1);
        }else{
            return (rh + 1);
        }
    }
};

template<typename T>
void Process_Input(string* vett, int n, string tipo, ifstream& in, ostream& out){
    BST<T> bst;

    T key;

    for(int i=0; i<n; i++){
        int l = vett[i].length();

        if(vett[i][0] == 'i'){
            string temp = "";
            for(int x=4; x<l; x++){
                temp += vett[i][x];
            }
            if(tipo == "int"){
                key = stoi(temp);
            }else if(tipo == "double"){
                key = stod(temp);
            }
            bst.insert(key);
        }
        else if(vett[i][0] == 'c'){
            string temp = "";
            for(int x=5; x<l; x++){
                temp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(temp);
            }else if(tipo == "double"){
                key = stod(temp);
            }
            bst.remove(key);
        }
    }
    out << bst.altezza() << endl;

}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i< 100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string* vett = new string[n];
        for(int i=0; i<n; i++){
            in >> vett[i];
        }
        if(tipo == "int"){
            Process_Input<int>(vett, n, tipo, in ,out);
        }else if(tipo == "double"){
            Process_Input<double>(vett, n, tipo, in, out);
        }
    }
}