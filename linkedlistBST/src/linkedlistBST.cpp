 #include <iostream>
 #include"Linkedlist.h"


    bool LLBST:: isEmpty() {
        if(root == nullptr){
        
        return true;
        }
        else{
        
        return false;}
    }

    void LLBST ::addBST(int key) {
        root = insert(root, key);
    }

    bool LLBST :: searchBST(int targetKey) {
        if (search(root, targetKey) != nullptr){
        std::cout << "The key is in the tree" << std::endl;
        return true;
        }
        else{
            std::cout << "The key is not in the tree" << std::endl;
            return false;
        }
        
    }

    void  LLBST :: removeBST(int keyToDelete) {
        root = remove(root, keyToDelete);
    }

    Node* LLBST::insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* LLBST :: search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

    Node* LLBST::remove(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = remove(node->left, key);
        } else if (key > node->key) {
            node->right = remove(node->right, key);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);

            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
        return node;
    }

    Node* LLBST ::minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }

    void LLBST :: destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
