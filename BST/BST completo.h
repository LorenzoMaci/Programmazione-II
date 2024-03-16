#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include<iostream>

template<typename T>
class BST {
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        BSTNode<T>* getRoot() {
            return this->root;
        }

        //CONTROLLO LISTA VUOITA
            bool isEmpty() {
                return root == nullptr;
            }

        //INSERIMENTO
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

        //MINIMO
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

        //MASSIMO
            BSTNode<T>* max(){
                return max(root);
            }

            BSTNode<T>* max(BSTNode<T>* from){
                if(isEmpty()){
                    return nullptr;
                }

                BSTNode<T>* p = from;
                while(p->getRight()){
                    p = p->getRight();
                }
                return p;
            }

        //SUCCESSORE
            BSTNode<T>* successor(T key){
                BSTNode<T>* p = search(key);
                if(!p || p == max()){
                    return nullptr;
                }
                return successor(p);
            }

            BSTNode<T>* successor(BSTNode<T>* p){
                if(this->isEmpty()) {
                    return nullptr;
                }
                
                if(p->getRight()){
                    return this->min(p->getRight());
                }
                BSTNode<T>* y = p->getParent();
                while(p && p == y->getRight()) {
                    p = y;
                    y = y->getParent();
                }
                return y;
            }

        //PREDECESSORE
            BSTNode<T>* predecessor(T key){
                BSTNode<T>* p = search(key);
                if(!p || p == min()){
                    return nullptr;
                    }
                return predecessor(p);
            }

            BSTNode<T>* predecessor(BSTNode<T>* p){
                if(this->isEmpty()){
                    return nullptr;
                }

                if(p->getLeft()){
                    return max(p->getLeft());
                }
                BSTNode<T>* y = p->getParent();
                while(p && p == y->getLeft()){
                    p = y;
                    y = y->getParent();
                }
                
                return y;
            }

        //RICERCA
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

        //CANCELLAZIONE
            void trapianta(BSTNode<T>* u, BSTNode<T>* v){
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

            void remove(T key){
                if(this->isEmpty()){
                    cout << "Non ci sono elementi nel BST!" << endl;
                    return;
                }

                BSTNode<T>* p = search(key);
                
                if(p->getLeft() == nullptr){
                    trapianta(p, p->getRight());
                } 
                else if(p->getRight() == nullptr){
                    trapianta(p, p->getLeft());
                } 
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

        //VISITA INORDER
            //VERSIONE CON OVERLOADING
            void Inorder(){
                Inorder(root);
            }

            void Inorder(BSTNode<T>* p){
                if(p != nullptr){
                    Inorder(p->getLeft());
                    cout << p->getKey() << " ";
                    Inorder(p->getRight());
                }
            }

            //VERSIONE SENZA OVERLOADING
            // void Inorder(ostream& out){
            //     Inorder(root, out);
            // }

            // void Inorder(BSTNode<T>* p, ostream& out){
            //     if(p != nullptr){
            //         Inorder(p->getLeft(), out);
            //         out << p->getKey() << " ";
            //         Inorder(p->getRight(), out);
            //     }
            // }

        //VISITA PREORDER
            //VERSIONE CON OVERLOADING
            void Preorder(){
                Preorder(root);
            }

            void Preorder(BSTNode<T>* p){
                if(p != nullptr){
                    cout << p->getKey() << " ";
                    Preorder(p->getLeft());
                    Preorder(p->getRight());
                }
            }

            //VERSIONE SENZA OVERLOADING
            // void Preorder(ostream& out){
            //     Preorder(root, out);
            // }

            // void Preorder(BSTNode<T>* p, ostream& out){
            //     if(p != nullptr){
            //         out << p->getKey() << " ";
            //         Preorder(p->getLeft(), out);
            //         Preorder(p->getRight(), out);
            //     }
            // }

        //VISITA POSTORDER
            //VERSIONE CON OVERLOADING
            void Postorder(){
                Postorder(root);
            }

            void Postorder(BSTNode<T>* p){
                if(p != nullptr){
                    Postorder(p->getLeft());
                    Postorder(p->getRight());
                    cout << p->getKey() << " ";
                }
            }

            //VERSIONE SENZA OVERLOADING
            // void Postorder(ostream& out){
            //     Postorder(root, out);
            // }

            // void Postorder(BSTNode<T>* p, ostream& out){
            //     if(p != nullptr){
            //         Postorder(p->getLeft(), out);
            //         Postorder(p->getRight(), out);
            //         out << p->getKey() << " ";
            //     }
            // }

        //STAMPA SENZA OVERLOADING
            // void Print(string s, ostream& out){
            //     if(s == "inorder"){
            //         Inorder(root, out); 
            //         out << endl;
            //     }
            //     else if(s == "preorder"){
            //         Preorder(root, out); 
            //         out << endl;
            //     }
            //     else if(s == "postorder"){
            //         Postorder(root, out); 
            //         out << endl;
            //     }
            // }

        //LIVELLO
            //Il livello di nodo in un BST corrisponde al numero di nodi presenti nel cammino che separano il nodo dalla radice, escludendo il nodo stesso. La radice si trova quindi al livello 0, i figli della radice a livello 1, e così via.
            int livello(T key){
                if(this->isEmpty()){
                    return nullptr;
                }

                BSTNode<T>* p = search(key);

                //La key non è presente nel BST
                if(p == nullptr){
                    return -1;
                }

                return livello(p);
            }

            int livello(BSTNode<T>* p){            
                //La key è la radice
                if(p == root){
                    return 0;
                }

                if(p->getParent() == root){
                    return 1;
                }
                
                int counter = 0;
                while(p->getParent() != root){
                    counter++;
                    p = p->getParent();
                }

                return (counter + 1);
            }

        //ALTEZZA
            //L'altezza di un BST corrisponde al numero di nodi presenti nel cammino che va dalla radice dell'albero alla foglia da essa più distante.
            int altezza(){
                if(this->isEmpty()){
                    return nullptr;
                }
                return altezza(root);
            }
            
            int altezza(BSTNode<T>* p){                
                if (p == nullptr){
                    return 0;
                } 

                int left_height = altezza(p->getLeft());
                int right_height = altezza(p->getRight());

                if(left_height > right_height){
                    return (left_height + 1);
                }   
                else{
                    return (right_height + 1);
                }       
            }

        //DISTANZA SUCCESSORE 
            int Dist_successor(T key){
                if(this->isEmpty()){
                    return nullptr;
                }
                
                int counter = 0;
                BSTNode<T> *p = search(key);

                if(!p || p == max()){
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
                BSTNode<T>* y = p->getParent();
                counter++;
                while(p && p == y->getRight()){
                    p = p->getParent();
                    y = y->getParent();
                    counter++;
                }
                return counter;
            }

        //DISTANZA ROOT
            int distanzaRoot(BSTNode<T>* nodo_h, BSTNode<T>* partenza){
                if(this->isEmpty()){
                    return nullptr;
                }
                
                if(partenza->getKey() == nodo_h->getKey()){
                    return 0;
                }

                BSTNode<T>* tmp = partenza;
                int counter = 0;
                while(tmp && tmp->getKey() != nodo_h->getKey()){
                    if(nodo_h->getKey() > tmp->getKey()){ 
                        tmp = tmp->getRight();
                    }
                    else{ 
                        tmp = tmp->getLeft();
                    }
                    counter++;
                }
                
                if(!tmp){ 
                    return -1;
                }
                else{ 
                    return counter;
                }
            }

        //DISTANZA TRA DUE NODI
            int distanzaChiavi(T k, T h){
                if(this->isEmpty()){
                    return nullptr;
                }

                BSTNode<T>* nodo_k = search(k);
                BSTNode<T>* nodo_h = search(h);
                int counter = 0;
                if(!nodo_k || !nodo_h){
                    cout << "Chiavi Errate!" << endl;
                }
                if(k <= h){
                    BSTNode<T>* tmp = nodo_k;
                    bool flag = true;
                    while(tmp && flag){
                        int distance = distanzaRoot(nodo_h, tmp); 
                        if(distance == 0){
                            flag = false;
                        }
                        else if(distance == -1){
                            tmp = tmp->getParent(); 
                            counter++; 
                        }
                        else{
                            counter += distance;
                            flag = false;
                        }
                    }
                    return counter;
                }
                else{
                    return distanzaChiavi(h, k);
                }
            }

        //Distanza predecessore
            int Dist_predecessore(T key){
                if(this->isEmpty()){
                    return nullptr;
                }
                
                int counter = 0;
                BSTNode<T> *p = search(key);

                if(!p || p == min()){
                    return 0;
                }


                if(p->getLeft()){
                    p = p->getLeft();
                    counter++;
                    while(p->getRight()){
                        p = p->getRight();
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

#endif