#include<iostream>
#include<fstream>
using namespace std;

template<typename H>
class BSTNode {
    protected:
        H key;
        BSTNode<H>* left;
        BSTNode<H>* right;
        BSTNode<H>* parent;

        template<typename U>
	    friend class BST;

    public:
        BSTNode(H key) : key(key){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        void setLeft(BSTNode<H>* left){
            this->left = left;
        }

        void setRight(BSTNode<H>* right){
            this->right = right;
        }

        void setParent(BSTNode<H>* parent){
            this->parent = parent;
        }

        void setKey(H key){
            this->key = key;
        }

        BSTNode<H>* getLeft(){
            return left;
        }

        BSTNode<H>* getRight(){
            return right;
        }

        BSTNode<H>* getParent(){
            return parent;
        }

        H getKey(){
            return key;
        }
};

template<typename T>
class BST {
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        bool isEmpty() {
		    return root == nullptr;
	    }

        void Insert(T key){
            if(this->isEmpty()) {
                root = new BSTNode<T>(key);
                return;
            }
            Insert(root, key);
        }

        void Insert(BSTNode<T>* p, T key){
            if(this->root == nullptr){
                this->root = new BSTNode<T>(key);
                return;
            }

            if(key <= p->getKey() && p->getLeft() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setLeft(node);
                node->setParent(p);
                return;
            }
            else if(key > p->getKey() && p->getRight() == nullptr){
                BSTNode<T>* node = new BSTNode<T>(key);
                p->setRight(node);
                node->setParent(p);
                return;
            }
            else if(key <= p->getKey() && p->getLeft() != nullptr){
                Insert(p->getLeft(), key);
            }
            else if(key > p->getKey() && p->getRight() != nullptr){
                Insert(p->getRight(), key);
            }
        }

        BSTNode<T>* min(){
		    return min(root);
	    }
	
        BSTNode<T>* min(BSTNode<T>* from){   
            if(this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* p = from;
            while(p->getLeft()) {
                p = p->getLeft();
            }
            return p;
        }

        BSTNode<T>* max() {
            return max(root);
        }
        
        BSTNode<T>* max(BSTNode<T>* from) {            
            if(this->isEmpty()) {
                return nullptr;
            }

            BSTNode<T>* p = from;
            while(p->getRight()) {
                p = p->getRight();
            }
            return p;
        }

        BSTNode<T>* predecessor(BSTNode<T>* p){
            if(this->isEmpty()) {
                return nullptr;
            }
            
            // 1. p ha un sottoalbero sinistro
            if(p->getLeft()){
                return this->max(p->getLeft());
            }
            // 2. p non ha un sottoalbero sinistro, il successore di p è l'antenato più prossimo di p il cui figlio destro è anche un antenato di p
            BSTNode<T>* y = p->getParent();
            
            while(p != nullptr && p == y->getLeft()) {
                p = y;
                y = y->getParent();
            }
            return y;
	    }

        BSTNode<T>* successor(BSTNode<T>* p){
            if(this->isEmpty()) {
                return nullptr;
            }
            
            // 1. p ha un sottoalbero destro
            if(p->getRight()){
                return this->min(p->getRight());
            }
            // 2. p non ha un sottoalbero destro, il successore di p è l'antenato più prossimo di p il cui figlio sinistro è anche un antenato di p
            BSTNode<T>* y = p->getParent();
            
            while(p != nullptr && p == y->getRight()) {
                p = y;
                y = y->getParent();
            }
            return y;
	    }

        BSTNode<T>* search(T key) {
            return search(root, key);
        }
        
        BSTNode<T>* search(BSTNode<T>* p, T key) {
            if(p == nullptr){
                return nullptr;
            }
            if(p->getKey() == key){
                return p;
            }
            if(key <= p->getKey()){
                return search(p->getLeft(), key);
            }
            else{
                return search(p->getRight(), key);
            }
            return nullptr;
        }

        void trapianta(BSTNode<T>* u, BSTNode<T>* v){
			if(u->getParent() == NULL) root = v;
			else if(u == u->getParent()->getLeft()) u->getParent()->setLeft(v);
			else u->getParent()->setRight(v);
			
			if(v != NULL) v->setParent(u->getParent());
		}

        void remove(T key){
			BSTNode<T>* p = search(key);
			
			if(p->getLeft() == NULL) trapianta(p, p->getRight());
			else if(p->getRight() == NULL) trapianta(p, p->getLeft());
			else{
				BSTNode<T>* y = min(p->getRight());
				
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

        int Dist_successor(T key){
            int counter = 0;
            BSTNode<T> *p = search(key);

            if(!p){
                return 0;
            }
            else if(p == max()){
                return -1;
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
            BSTNode<T>* y = p->getParent();
            counter++;
            while(p && p == y->getRight()){
                p = p->getParent();
                y = y->getParent();
                counter ++;
            }
            return counter;
        }
};

template<typename S>
void Process_Input(string* vett1, int n, int m,  string tipo, ifstream& in, ostream& out){
    S* vett2 = new S[m];
    for(int j = 0; j<m; j++){
        in >> vett2[j];

    }

    BST<S> bst;

    S key;

    //Vado a fare gli inserimenti e le cancellapioni
    for(int j = 0; j<n; j++){
        int l = vett1[j].length();

        //Inserimento
        if(vett1[j][0] == 'i'){
            string tmp = "";
            for(int x = 4; x<l; x++){
                tmp += vett1[j][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else{
                key = stod(tmp);
            }   
            bst.Insert(key);
        }
        //Cancellapione
        else if(vett1[j][0] == 'c'){
            string tmp = "";
            for(int x = 5; x<l; x++){
                tmp += vett1[j][x];
            }

            if(tipo == "int"){
                key = stoi(tmp);
            }
            else{
                key = stod(tmp);
            }         
            bst.remove(key);
        }
    }

    //Distanza successore
    for(int j = 0; j<m; j++){
        if(bst.Dist_successor(vett2[j]) == -1){
            out << "INF ";
        }
        else{
            out << bst.Dist_successor(vett2[j]) << " ";
        }
    }
    out << endl;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    for(int i = 0; i<100; i++){
        string tipo;
        in >> tipo;

        int n;
        in >> n;

        int m;
        in >> m;

        string* vett1 = new string[n];
        for(int j = 0; j<n; j++){
            in >> vett1[j];
        }

        if(tipo == "int"){
            Process_Input<int>(vett1, n, m, tipo, in, out);
        }
        else if(tipo == "double"){
            Process_Input<double>(vett1, n, m, tipo, in, out);
        }
    }
}