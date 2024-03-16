#include <iostream>
#define DIM 8
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
            out << "@nodo" << &n << endl;
            out << "n.key:" << n.key << endl;
            out << "-Left->" << n.left << " -Right->" << n.right << " -Parent->" << n.parent << endl;
            return out;
        }
        return out << "Key; " << n.key << endl;
    }
};

template <typename T>
class BST{
    private:
    Nodo<T>* root;

    public:
    BST(){
        root = nullptr;
    }

    bool isEmpty(){
        return root == nullptr;
    }

    Nodo<T>* getRoot(){
        return root;
    }

    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if(this->root == nullptr){
            this->root = new Nodo<T>(key);
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
            return search(p->getRight(), key);
        }
        return nullptr;
    }

    Nodo<T>* max(){
        return max(root);
    }

    Nodo<T>* max(Nodo<T>* x){
        if(this->isEmpty()){
           throw out_of_range("Empty bst....");
        }

        Nodo<T>* nMax = x;
        while(nMax->getRight()){
            nMax = nMax->getRight();
        }
        return nMax;
    }

    void inorder(){
        inorder(root);
    }

    void inorder(Nodo<T>* p){
        if(p != nullptr){
            inorder(p->getLeft());
            cout << p->getKey() << " ";
            inorder(p->getRight());
        }
    }

    int distanza_successore(T x){
        if(this->isEmpty()){
            return 0;
        }

        int counter = 0;
        Nodo<T>* p = search(x);
  
        if(!p || p==max()){
            return 0;
        }

        if(p->getRight()){
            p = p->getRight();
            counter++;
            while(p->getLeft()){
                p = p->getLeft();
                counter++;
            }
            return counter;
        }

        Nodo<T>* y = p->getParent();
        counter++;

        while(p && p == p->getRight()){
            p = p->getParent();
            y = y->getParent();
            counter++;
        }
        return counter;
    }
};

int main(){
    BST<int> bst1;
	BST<char> bst2;

	for(int i=0; i<DIM; i++){
        bst1.insert(rand() % 50);
        bst2.insert(rand() % ('z' - 'a' + 1 ) + 'a');
    }

    //BST interi
    cout << "BST di Interi:" << endl;

    cout << "BST Root: " << endl;
    cout << *(bst1.getRoot()) << endl;
	cout << "\tVisita in order: " << endl;
	bst1.inorder();
    cout << "\n\tDistanza dal successore di 12 : " << bst1.distanza_successore(12) << endl;

    //BST char
    cout << "\nBST di Char:"  << endl;
    cout << "\tBST Root: ";
    cout << *(bst2.getRoot()) << endl;

	cout << "\tVisita in order: " << endl;
	bst2.inorder();
    cout << "\n\tDistanza dal successore di r : " << bst2.distanza_successore('r') << endl;    
}