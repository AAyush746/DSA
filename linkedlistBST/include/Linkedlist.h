#include <iostream>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int data) {
        key = data;
        left = right = nullptr;
    }
};
