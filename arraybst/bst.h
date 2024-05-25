#pragma once
class BST{
    public:
        BST(){}
        ~BST(){}

        virtual bool isEmpty()=0;
        virtual void addBST(int key , int value)=0;
        virtual void removeBST(int keytodelete)=0;
        virtual bool searchBST(int targetkey)=0;
};