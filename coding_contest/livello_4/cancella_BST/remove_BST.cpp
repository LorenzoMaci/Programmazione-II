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

    template <typename U>
    friend class BST;
    
    public:
    Nodo(T key) : key(key){
        left = nullptr;
        right = nullptr;
        parent = nullptr;
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

    Nodo<T>* getRigth(){
        return right;
    }

    Nodo<T>* getParent(){
        return parent;
    }

    T getKey(){
        return key;
    }
};

template <typename T>
class BST{
    private:
    Nodo<T>* root;

    public:
    BST() {
        root = nullptr;
        }

    bool isEmpty(){
        return root == nullptr;
    }

    void Inorder(ostream& out){
        Inorder(root, out);
    }

    void Inorder(Nodo<T>* p, ostream& out){
        if(p != nullptr){
            Inorder(p->getLeft(), out);
            out << p->getKey() << " ";
            Inorder(p->getRigth(), out);
        }
    }

    void Preorder(ostream& out){
        Preorder(root, out);
    }

    void Preorder(Nodo<T>* p, ostream& out){
        if(p != nullptr){
            out << p->getKey() << " ";
            Preorder(p->getLeft(), out);
            Preorder(p->getRigth(), out);
        }
    }

    void Postorder(ostream& out){
        Postorder(root, out);
    }

    void Postorder(Nodo<T>* p, ostream& out){
        if (p != nullptr){
            Postorder(p->getLeft(), out);
            Postorder(p->getRigth(), out);
            out << p->getKey() << " ";
        }
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
        }else if(key > p->getKey() && p->getRigth() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if(key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRigth() != nullptr){
            insert(p->getRigth(), key);
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
            return search(p->getLeft(), key);
        }else {
            return search(p->getRigth(), key);
        }
        return nullptr;
    }

    void trapianta(Nodo<T>* u, Nodo<T>* v){
        if( u->getParent() == nullptr){
            root = v;
        }
        else if(u == u->getParent()->getLeft()){
            u->getParent()->setLeft(v);
        }else {
            u->getParent()->setRight(v);
        }
        if(v != nullptr){
            v->setParent(u->getParent());
        }
    }

    void remove(T key){
        Nodo<T>* p = search(key);

        if(p->getLeft() == nullptr){
            trapianta(p, p->getRigth());
        }else if(p->getRigth() == nullptr){
            trapianta(p, p->getLeft());
        }else{
            Nodo<T>* y = min(p->getRigth());
            if(y->getParent() != p){
                trapianta(y, y->getRigth());
                y->setRight(p->getRigth());
                y->getRigth()->setParent(y);
            }
            trapianta(p, y);
            y->setLeft(p->getLeft());
            y->getLeft()->setParent(y);
        }
        delete p;
    }


    void Print(string s, ostream& out){
        if(s == "inorder"){
            Inorder(root, out);
            out << endl;
        }else if(s == "preorder"){
            Preorder(root, out);
            out << endl;
        }else if(s == "postorder"){
            Postorder(root, out);
            out << endl;
        }
    }
};  

template<typename S>
void Process_Input(int n, string visita, string tipo, ifstream& in, ostream& out){
	string* vett = new string[n];
	for(int i = 0; i<n; i++){
		in >> vett[i];
	}

	BST<S> bst;

    S key;

	for(int i = 0; i<n; i++){
        int l = vett[i].length();

        //Inserimento
        if(vett[i][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }
            else if(tipo == "bool"){
                key = stoi(tmp);
            } 
            else if(tipo == "char"){
                key = tmp[0];
            } 

            bst.insert(key);
        }
        //Cancellapione
        else if(vett[i][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett[i][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else if(tipo == "double"){
                key = stod(tmp);
            }
            else if(tipo == "bool"){
                key = stoi(tmp);
            } 
            else if(tipo == "char"){
                key = tmp[0];
            } 

            bst.remove(key);
        }
    }

	bst.Print(visita, out);
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        string visita;
        in >> visita;

		if(tipo == "int"){
			Process_Input<int>(n, visita, tipo, in, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(n, visita, tipo, in, out);
		}
		else if(tipo == "bool"){
			Process_Input<bool>(n, visita, tipo, in, out);
		}
		else if(tipo == "char"){
			Process_Input<char>(n, visita, tipo, in, out);
		}
    }
}