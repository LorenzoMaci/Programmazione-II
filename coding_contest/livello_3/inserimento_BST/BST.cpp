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
        this->left = nullptr;
        this->right = nullptr;
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

    Nodo<T>* getRight(){
        return right;
    }

    Nodo<T>* getLeft(){
        return left;
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
    Nodo<T>* root;
    public:
    BST() { root = nullptr;}

    void inorder(ostream& out){
        inorder(root, out);
    }

    void inorder(Nodo<T>* p, ostream& out){
        if(p != nullptr){
            inorder(p->getLeft(), out);
            out << p->getKey() << " ";
            inorder(p->getRight(), out);
        }
    }


    void preorder(ostream& out){
        preorder(root, out);
    }

    void preorder(Nodo<T>* p, ostream& out){
        if(p != nullptr){
            out << p->getKey() << " ";
            preorder(p->getLeft(), out);
            preorder(p->getRight(), out);
        }
    }

    void postorder(ostream& out){
        postorder(root, out);
    }

    void postorder(Nodo<T>* p, ostream& out){
        if(p != nullptr){
            postorder(p->getLeft(), out);
            postorder(p->getRight(), out);
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
        }else if(key > p->getKey() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
            return;
        }else if(key <= p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRight() != nullptr){
            insert(p->getRight(), key);
        }
    }

    void Print(string s, ostream& out){
        if(s == "inorder"){
            inorder(root, out);
            out << endl;
        }else if(s == "preorder"){
            preorder(root, out);
            out << endl;
        }else if(s == "postorder"){
            postorder(root, out);
            out << endl;
        }
    }
};

template<typename T>
void Process_Input(int n, string s, ifstream& in, ofstream& out){
    T* vett = new T[n];
    for(int j=0; j<n; j++){
        in >> vett[j];
    }

    BST<T> bst;
    for(int j=0; j<n; j++){
        bst.insert(vett[j]);
    }
    bst.Print(s, out);
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
			Process_Input<int>(n, visita, in, out);
		}
		else if(tipo == "double"){
			Process_Input<double>(n, visita, in, out);
        }
		else if(tipo == "bool"){
			Process_Input<bool>(n, visita, in, out);
		}
		else if(tipo == "char"){
			Process_Input<char>(n, visita, in, out);
		}
    }
}