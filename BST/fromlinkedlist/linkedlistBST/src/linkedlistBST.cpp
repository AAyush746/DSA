 #include <iostream>
#include "Linkedlist.h"


    bool LLBST:: isEmpty() {
        if(root == nullptr){
        
        return true;
        }
        else{
        
        return false;}
    }

  void LLBST::addBST(int key) {
    if (root == NULL) {
        root = new Node(key);
        return;
    }

    Node* temp = root;
    Node* parent = NULL;

    while (temp != NULL) {
        parent = temp;
        if (key < temp->key) {
            temp = temp->left;
        } else if (key > temp->key) {
            temp = temp->right;
        } 
    }

    if (key < parent->key) {
        parent->left = new Node(key);
    } else {
        parent->right = new Node(key);
    }
}
    bool LLBST :: searchBST(int targetKey) {
    bool found = false;
    if(this->isEmpty()){
        std::cout << "\n the list is empty\n";
    }
    else{
        Node* temp = this->root;

       
       while (temp!=NULL){
            if(temp->key == targetKey){
                found = true;
                break;
            }
            else if(temp->key<targetKey){
                temp=temp->right;
            }
            else if(temp->key>targetKey){
                temp=temp->left;
            }
        }
    }
        
    }

 void LLBST::removeBST(int key) {
    if (root == NULL) {
        std::cout << "Tree is empty\n";
        return;
    }
    Node* temp = root;

    while (temp != NULL) {
        if(temp->key != key){
            delete temp;
            break;
        }
        
       else if (key < temp->key) {
            temp = temp->left;
        } 
        else {
            temp = temp->right;
        }
    }

    if (temp == NULL) {
        std::cout << "Key not found in the tree\n";
        return;
    }
 }
