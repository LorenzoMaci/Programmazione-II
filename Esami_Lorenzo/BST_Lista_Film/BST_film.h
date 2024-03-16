#ifndef BST_H
#define BST_H

#include<iostream>

#include "BSTNode_film.h"

class BST {
    private:
        BSTNode* root;

    public:
        BST(){
            root = nullptr;
        }

        void Insert(string anno, string nome, string valutazione){
            Insert(root, anno, nome, valutazione);
        }

        void Insert(BSTNode* p, string anno, string nome, string valutazione){
            if(this->root == nullptr){
                this->root = new BSTNode(anno, nome, valutazione);
                return;
            }

            if(anno <= p->getAnno() && p->getLeft() == nullptr){
                BSTNode* node = new BSTNode(anno, nome, valutazione);
                p->setLeft(node);
                node->setParent(p);
                return;
            }
            else if(anno > p->getAnno() && p->getRight() == nullptr){
                BSTNode* node = new BSTNode(anno, nome, valutazione);
                p->setRight(node);
                node->setParent(p);
                return;
            }
            else if(anno <= p->getAnno() && p->getLeft() != nullptr){
                Insert(p->getLeft(), anno, nome, valutazione);
            }
            else if(anno > p->getAnno() && p->getRight() != nullptr){
                Insert(p->getRight(), anno, nome, valutazione);
            }
        }

        void Inorder(){
            Inorder(root);
        }

        void Inorder(BSTNode* p){
            if(p != nullptr){
                Inorder(p->getLeft());
                cout << "\t- Nome = " << p->getNome() << ", Valutazione = " << p->getValutazione() << ", Anno = " << p->getAnno() << endl;
                Inorder(p->getRight());
            }
        }

        // void Print(ostream& out){
		// 	Inorder(root, out);
		// }
};

#endif