#include <iostream>

using namespace std;

template <typename T>
class Nodo{
    public:
    T val;
    Nodo<T>* left;
    Nodo<T>* right;
    Nodo<T>* parent;
};

template<typename T>
class BST{
    private:
    Nodo<T>* root;
    int size = 0;
    void InOrder(Nodo<T>* p) const;
    void PreOrder(Nodo<T>* p) const;
    void PostOrder(Nodo<T>* p) const;

    void trapianta(Nodo<T>* u, Nodo<T>* v);
    void cancella(Nodo<T>* z);
    
    Nodo<T>* min(Nodo<T>* x);
    Nodo<T>* max(Nodo<T>* x);

    public:
    BST() : root(nullptr){}
    void InOrder() const;
    void PreOrder() const;
    void PostOrder() const;

    void insert(T val);
    int altezza (Nodo<T>* p) const;
    bool cancella(T x);
    T min();
    T max();

    template<typename U>
    friend ostream operator<<(ostream& out, const BST<U>& t);

};

template<typename T>
void BST<T>::InOrder(Nodo<T>* p) const{
    if(p != nullptr){
        InOrder(p->left);
        cout << p->val << "\t";
        InOrder(p->right);
    }
}
//public
template<typename T>
void BST<T>::InOrder()const{
    InOrder(root);
}

template<typename T>
void BST<T>::PreOrder(Nodo<T>* p) const{
    if(p != nullptr){
        cout << p->val << "\t";
        PreOrder(p->left);
        PreOrder(p->right);
    }
}

template<typename T>
void BST<T>::PreOrder(Nodo<T>* p) const{
    PreOrder(root);
}

template<typename T>
void BST<T>::PostOrder(Nodo<T>* p)const{ 
    if(p != nullptr){
        PostOrder(p->left);
        PostOrder(p->right);
        cout << p->val << "\t";
    }
}

template<typename T>
void BST<T>::PostOrder() const{
    PostOrder(root);
}

template<typename T>
void BST<T>::trapianta(Nodo<T>* u, Nodo<T>* v) {
    if(u->parent == nullptr){
        root = v;
    }else if(u = u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

template<typename T>
void BST<T>::cancella(Nodo<T>* z){
    Nodo<T>* y;
    if(z->left == nullptr){
        trapianta(z, z->right);
    }else if(z->right == nullptr){
        trapianta(z, z->left);
    }else{
        y = min(z->right);
        if(y->parent != z){
            trapianta(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        trapianta(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}

//PUBLIC    
template<typename T>
bool BST<T>::cancella(T x){
    Nodo<T>* temp = root;
    while(temp != nullptr && x != temp->val){ 
        if(x < temp->val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    if(temp == nullptr){
        return false;
    }
    cancella(temp);
    return true;
}

template<typename T>
Nodo<T>* BST<T>::min(Nodo<T>* x){
    Nodo<T>* nMin = x;
    while(nMIN->left != nullptr){
        nMin = nMin->left;
    }
    return nMin;
}
//public
template<typename T>
T BST<T>::min(){
    Nodo<T>* nMin = min(root);
    return nMin;
}

template<typename T>
Nodo<T>* BST<T>::max(Nodo<T>* x){
    Nodo<T>* nMax = x;
    while(nMax->right != nullptr){
        nMax = nMax->right;
    }
    return nMax;
}

//public
template<typename T>
T BST<T>::max(){
    Nodo<T>* nMax = max(root);
    return nMax;
}

template<typename T>
void BST<T>::insert(T val){
    Nodo<T>* toInsert = new Nodo<T>;
    Nodo<T>* x = root;
    Nodo<T>* y = nullptr;
    toInsert->val = val;
    toInsert->left = toInsert->right = nullptr;
    while(x != nullptr){
        y = x;
        if(val < x->val){
            x = x->left;
        }else{
            x = x->right;
        }   
    }
    toInsert->parent = y;
    if(y == nullptr){
        root = toInsert;
    }else if( val < y->val){
        y->left = toInsert;
    }else{
        y->right = toInsert;
    }
    size++;
}

template<typename T>
int BST<T>::altezza(Nodo<T>* p) const{
    if(p == nullptr){
        return 0;
    }
    int lh = altezza(p->left);
    int rh = altezza(p->right);

    if(lh > rh){
        return (lh + 1);
    }else{
        return (rh + 1);
    }
}

template<typename T>
void stampalivello(Nodo<T>* p, int level){
    if(p == nullptr){
        if(level == 0)
            cout << "\t";
        return
    }

    if(level == 0){
        cout << p->val << "\t";
    }else if(level > 0){
        stampalivello(p->left, level-1);
        stampalivello(p->right, level - 1);
    }
}

template<typename T>
ostream& operator<<(ostream& out, const BST<T>& t){
    int h = t.altezza(t.root);
    cout << "Tree height " << h << endl;
    for(int i=0; i<h; i++){
        stampalivello(t.root, i);
        cout << endl;
    }
    return out;
}

int main(){
    BST<int> tree;
    tree.insert(7);
    tree.insert(20);
    tree.insert(15);
    tree.insert(8);
    tree.insert(18);
    tree.insert(2);

    cout << tree << endl;

    cout << "InOrder visit:\t\t";
    tree.InOrder();
    cout << endl;

    int v = 2;
    cout << endl << "Cancella il nodo con la chiave: " << v << endl;
    if(!tree.cancella(v)){
        cout << "Element not found" << endl;
    }

    cout << endl << tree << endl;
}