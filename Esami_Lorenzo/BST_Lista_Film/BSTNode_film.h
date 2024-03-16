#ifndef BSTNODE_FILM_H
#define BSTNODE_FILM_H

#include<iostream>
using namespace std;

class BSTNode {
    protected:
        string nome;
        string anno;
        string valutazione;
        BSTNode* left;
        BSTNode* right;
        BSTNode* parent;

	    friend class BST;

    public:
        BSTNode(string anno, string nome, string valutazione) : anno(anno), nome(nome), valutazione(valutazione){
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }

        BSTNode* getLeft(){
            return left;
        }

        BSTNode* getRight(){
            return right;
        }

        BSTNode* getParent(){
            return parent;
        }

        string& getNome(){
		    return this->nome; 
        }

        string& getAnno(){
            return this->anno; 
        }

        string& getValutazione(){
            return this->valutazione; 
        }

        void setLeft(BSTNode* left){
            this->left = left;
        }

        void setRight(BSTNode* right){
            this->right = right;
        }

        void setParent(BSTNode* parent){
            this->parent = parent;
        }

        friend ostream& operator<<(ostream& out, BSTNode& node) {
            out << "- Nome = " << node.nome << ", Valutazione = " << node.valutazione << ", Anno Uscita = " << node.anno;
		    return out;
        }
};

#endif