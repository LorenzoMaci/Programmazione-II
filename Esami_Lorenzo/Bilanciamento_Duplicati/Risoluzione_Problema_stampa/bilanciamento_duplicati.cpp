#include <iostream>
using namespace std;

template <typename T>
class Nodo{
    private:
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

    friend ostream& operator<<(ostream& out, Nodo<T>& node){
        if(node.verbose){
            out << "@Nodo: " << &node << endl;
            out << "-Key: " << node.key << endl;
            out << "-Left: "<< node.left << " -Right: " << node.right << " -Parent: "<< node.parent << endl;
            return out;
        }
        return out << "-Key: "<< node.key << endl;
    }
};

template <typename T>
class BST{
    private:
    Nodo<T>* root;

    public:
    BST(){
        this->root = nullptr;
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


    void insert(T key){
        insert(root, key);
    }

    void insert(Nodo<T>* p, T key){
        if(this->root == nullptr){
            root = new Nodo<T>(key);
            return;
        }

        if(key == p->getKey()){
            if(p->getLeft() == nullptr){
                Nodo<T>* node = new Nodo<T>(key);
                p->setLeft(node);
                node->setParent(p);
                 cout << "Inserito " << key << " nel sottoalbero sinistro di " << p->getKey() << endl;
            }else if(p->getRight() == nullptr){
                Nodo<T>* node = new Nodo<T>(key);
                p->setRight(node);
                node->setParent(p);
                 cout << "Inserito " << key << " nel sottoalbero destro di " << p->getKey() << endl;
            }else{
                bool insert = true;
                Nodo<T>* child = nullptr;

                if(p->getRight()->getKey() == key){
                    insert = false;
                    child = p->getRight();
                }
                else if(p->getLeft()->getKey() == key){
                    insert = true;
                    child = p->getLeft();
                }

                Nodo<T>* node = new Nodo<T>(key);
                node->setParent(p);

                if(insert){
                    node->setRight(child);
                    child->setParent(node);
                    p->setRight(node);
                    cout << "Inserito " << key << " nel sottoalbero sinistro di " << p->getKey() << endl;
                }else{
                    node->setLeft(child);
                    child->setParent(node);
                    p->setLeft(node);
                    cout << "Inserito " << key << " nel sottoalbero sinistro di " << p->getKey() << endl;
                }

            }
        }else if(key < p->getKey() && p->getLeft() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setLeft(node);
            node->setParent(p);
        }else if(key > p->getKey() && p->getRight() == nullptr){
            Nodo<T>* node = new Nodo<T>(key);
            p->setRight(node);
            node->setParent(p);
        }else if(key < p->getKey() && p->getLeft() != nullptr){
            insert(p->getLeft(), key);
        }else if(key > p->getKey() && p->getRight() != nullptr){
            insert(p->getRight(), key);
        }
    }
};


int main(){
    BST<int> bst;
    BST<char> bst2;

    bst.insert(15);
    bst.insert(12);
    bst.insert(12);
    bst.insert(3);
    bst.insert(5);
    bst.insert(8);
    bst.insert(8);
    bst.insert(7);
    bst.insert(8);


    bst.inorder();
    cout << endl;

    bst2.insert('a');
    bst2.insert('c');
    bst2.insert('d');
    bst2.insert('c');
    bst2.insert('e');
    bst2.insert('b');
    bst2.insert('e');

    bst2.inorder();
    cout << endl;
}