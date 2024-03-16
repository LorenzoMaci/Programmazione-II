#include <iostream>
#define DIM 10

using namespace std;

static int counter = 0;

template <typename T>
class Nodo{
    protected:
    T key;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
    bool verbose;

    template<typename U>
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
            out << "Nodo:" << &n << endl;
            out << "Nodo->Key" << n.key << endl;
            out << "- Parent->" << n.parent << " -Left->" << n.left << " -right->" << n.right << endl;
            return out;
        }
        return out << "Key->" << n.key << endl;
    }
};


template<typename T>
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
        }else{
            return search(p->getRight(), key);
        }
        return nullptr;
    }

    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if(root == nullptr){
            this->root = new Nodo<T>(key);
            return;
        }

        if(search(key)){
            if(counter % 2 == 0){
                if(key <= p->getKey() && p->getLeft() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "Metto il valore a sinistra " << endl;
                    cout << "key " << key << endl;
                    counter++;
                    return;
                }else if(key > p->getKey() && p->getRight() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setRight(node);
                    node->setParent(p);
                    cout << "Metto il valore a sinistra " << endl;
                    cout << "key:" << key << endl;
                    counter++;
                    return;
                }else if(key <= p->getKey() && p->getLeft() != nullptr){
                    insert(p->getLeft(), key);
                }else if(key > p->getKey() && p->getRight() != nullptr){
                    insert(p->getRight(), key);
                }
            }else{
                if(key < p->getKey() && p->getLeft() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setLeft(node);
                    node->setParent(p);
                    cout << "Metto il valore a destra " << endl;
                    cout << "key " << key << endl;
                    counter++;
                    return;
                }else if(key >= p->getKey() && p->getRight() == nullptr){
                    Nodo<T>* node = new Nodo<T>(key);
                    p->setRight(node);
                    node->setParent(p);
                    cout << "Metto il valore a destra " << endl;
                    cout << "key:" << key << endl;
                    counter++;
                    return;
                }else if(key < p->getKey() && p->getLeft() != nullptr){
                    insert(p->getLeft(), key);
                }else if(key >= p->getKey() && p->getRight() != nullptr){
                    insert(p->getRight(), key);
                }
            }
        }else{
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
};

int main(){
    BST<int> bst1;
    BST<char> bst2;

    for(int i=0; i<DIM; i++){
        bst1.insert(rand()% 50);
        bst2.insert(rand()%('z' - 'a' + 1) + 'a');
    }

    //BST interi
    cout << "BST di Interi:" << endl;

    cout << "BST Root: " << endl;
    cout << *(bst1.getRoot()) << endl;
	cout << "\tVisita in order: " << endl;
	bst1.inorder();

    cout << "Counter: " << counter << endl << endl;

    //BST char
    cout << "\nBST di Char:"  << endl;
    cout << "\tBST Root: ";
    cout << *(bst2.getRoot()) << endl;

	cout << "\tVisita in order: " << endl;
	bst2.inorder();

    cout << "Counter char:" << counter << endl << endl;
}