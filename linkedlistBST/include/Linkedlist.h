
class Node {
    int data;
    Node* left;
    Node* right;
};

class LinkedList : public Node{
private:
    Node* root;

public:
    LinkedList();
    ~LinkedList();

    void insert(int data);
    void remove(int data);
    bool search(int data);
    void display();
};
