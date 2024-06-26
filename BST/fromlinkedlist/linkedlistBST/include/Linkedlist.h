#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(){}
    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};
class LLBST: public Node{
    public:
        Node* root;

        LLBST() {
            root = nullptr;
            }

        ~LLBST(){}

        bool isEmpty();
        void addBST(int key);
        bool searchBST(int targetKey);
        void removeBST(int keyToDelete);

};
#endif