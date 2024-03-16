#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Nodo{
    protected:
    T key;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
    bool verbose;
    template <typename U>
    friend class BST;
    public:
    Nodo(T key, bool verbose = false) : key(key), verbose(verbose){
        this->left = nullptr;
        this->right =  nullptr;
        this->parent = nullptr;
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

    friend ostream& operator<<(ostream& out, Nodo<T>& n){
        if(n.verbose){
            out << "Nodo:" << &n << endl;
            out << "key:" << n.key << endl;
            out << "left->" << n.left << ", right->" << n.right << ", parent->" << n.parent << endl;
            return out;
        }
        return out << "\tKey:" << n.key << endl;
    }
};


template <typename H>
class BST{
    private:
    Nodo<H>* root;

    public:
    BST(){
        root = nullptr;
    }

    Nodo<H>* getRoot(){
        return root;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    void insert(H key){
        insert(root, key);
    }

    void insert(Nodo<H>* p, H key){
        if(root == nullptr){
            root = new Nodo<H>(key);
            return;
        }

        if(key <= p->getKey() && p->getLeft() == nullptr){
            Nodo<H>* node = new Nodo<H>(key);
            p->setLeft(node);
            node->setParent(p);
            return;
        }else if(key > p->getKey() && p->getRight() == nullptr){
            Nodo<H>* node = new Nodo<H>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if(key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRight() != nullptr){
            insert(p->getRight(), key);
        }
    }

    Nodo<H>* search(H key){
        return search(root, key);
    }

    Nodo<H>* search(Nodo<H>* p, H key){
        if(p == nullptr){
            return nullptr;
        }

        if(p->getKey() == key){
            return p;
        }

        if(key <= p->getKey()){
            return search(p->getLeft(), key);
        }else{
            return search(p->getRight(), key);
        }
        return nullptr;
    }

    int distanza_Root(Nodo<H>* nodo_h, Nodo<H>* partenza){
        if(this->isEmpty()){
            return -1;
        }

        if(partenza->getKey() == nodo_h->getKey()){
            return 0;
        }

        Nodo<H>* temp = partenza;
        int counter = 0;
        while(temp && temp->getKey() != nodo_h->getKey()){
            if(nodo_h->getKey() > temp->getKey()){
                temp = temp->getRight();
            }else{
                temp = temp->getLeft();
            }
            counter++;
        }
        if(!temp){
            return -1;
        }else{
            return counter;
        }
    }

    int distanza_Chiavi(H k, H h){
        Nodo<H>* nodo_k = search(k);
        Nodo<H>* nodo_h = search(h);

        int counter = 0;
        if(! nodo_k || ! nodo_h){
            cout << "chiavi erratte " << endl;
            return 0;
        }

        if(k <= h){
            Nodo<H>* temp = nodo_k;
            bool flag = true;
            while(temp && flag){
                int distance = distanza_Root(nodo_h, temp);
                if(distance == 0){
                    flag = false;
                }else if(distance == -1){
                    temp = temp->getParent();
                    counter++;
                }else{
                    counter += distance;
                    flag = false;
                }
            }
            return counter;
        }else{
            return distanza_Chiavi(h, k);
        }
    }
};

template <typename T>
void Process_Input(string* vett, int n, string tipo, ifstream& in, ofstream& out){
    T key1;
    in >> key1;
    cout << key1 << " ";

    T key2;
    in >> key2;
    cout << key2 << endl;

    BST<T> bst;

    T key;

    for(int j=0; j<n; j++){
        int l = vett[j].length();
        string temp = "";
        for(int x=4; x<l; x++){
            temp += vett[j][x];
        }
        if(tipo == "int"){
            key = stoi(temp);
        }else if(tipo == "double"){
            key = stod(temp);
        }else if(tipo == "bool"){
            key = stoi(temp);
        }else if(tipo == "char"){
            key = temp[0];
        }
        bst.insert(key);
    }

    out << bst.distanza_Chiavi(key1, key2) << endl << endl;

}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i=0; i<6; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string* vett = new string[n];
        for(int i=0; i<n; i++){
            in >> vett[i];
            cout << vett[i] << " ";
        }
         if(tipo == "int"){
            Process_Input<int>(vett, n, tipo, in, out);
        }
        else if(tipo == "double"){
            Process_Input<double>(vett, n, tipo, in, out);
        }
        else if(tipo == "bool"){
            Process_Input<bool>(vett, n, tipo, in, out);
        }
        else if(tipo == "char"){
            Process_Input<char>(vett, n, tipo, in, out);
        }
    }
}