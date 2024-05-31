#include <iostream>
#include "Linkedlist.h"
class LinkedListBST {
private:
    Node* root;

public:
    LinkedListBST() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            while (true) {
                if (value < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    void display(Node* node) {
        if (node != nullptr) {
            display(node->left);
            std::cout << node->data << " ";
            display(node->right);
        }
    }

    void displayTree() {
        display(root);
        std::cout << std::endl;
    }

    bool search(int value) {
        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    bool remove(int value) {
        Node* parent = nullptr;
        Node* current = root;

        while (current != nullptr) {
            if (value == current->data) {
                break;
            } else {
                parent = current;
                if (value < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }

        if (current == nullptr) {
            return false;
        }

        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) {
                root = nullptr;
            } else if (current == parent->left) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
            delete current;
        } else if (current->left == nullptr) {
            if (current == root) {
                root = current->right;
            } else if (current == parent->left) {
                parent->left = current->right;
            } else {
                parent->right = current->right;
            }
            delete current;
        } else if (current->right == nullptr) {
            if (current == root) {
                root = current->left;
            } else if (current == parent->left) {
                parent->left = current->left;
            } else {
                parent->right = current->left;
            }
            delete current;
        } else {
            Node* successor = getSuccessor(current);
            if (current == root) {
                root = successor;
            } else if (current == parent->left) {
                parent->left = successor;
            } else {
                parent->right = successor;
            }
            successor->left = current->left;
            delete current;
        }

        return true;
    }

private:
    Node* getSuccessor(Node* node) {
        Node* parent = node;
        Node* successor = node;
        Node* current = node->right;

        while (current != nullptr) {
            parent = successor;
            successor = current;
            current = current->left;
        }

        if (successor != node->right) {
            parent->left = successor->right;
            successor->right = node->right;
        }

        return successor;
    }
};

int main() {
    LinkedListBST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    bst.displayTree();

    int valueToSearch = 4;
    if (bst.search(valueToSearch)) {
        std::cout << valueToSearch << " is found in the BST." << std::endl;
    } else {
        std::cout << valueToSearch << " is not found in the BST." << std::endl;
    }

    int valueToRemove = 7;
    if (bst.remove(valueToRemove)) {
        std::cout << valueToRemove << " is removed from the BST." << std::endl;
    } else {
        std::cout << valueToRemove << " is not found in the BST." << std::endl;
    }

    bst.displayTree();

    return 0;
}