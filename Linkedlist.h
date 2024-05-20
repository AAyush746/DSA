#ifndef Linkedlist_h
#define Linkedlist_h
//program2

// This is the class for Each Node;
class Node
{

public:
    int data;
    Node *next;

    Node(){};

    // Contructor for Node, it accepts the data and store it the the public variable of this class.
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }

    ~Node(){};
};

/**
 *
 * Linked List class for various functionality of Linked list
 */
class Linkedlist
{

public:
    Node *HEAD;
    Node *TAIL;

    // Initializing Head and tail to nullptr
    Linkedlist() : HEAD(nullptr), TAIL(nullptr){};

    // DEFINE
    void addToHead(int data);
    void addToTail(int data);
    void displayHead();
    void displayTail();
    Node *find(int data, const Linkedlist &list1);
    void insert(int data, int after, const Linkedlist &list1);
    void displayAllData(const Linkedlist &list1);

    // Destructor
    ~Linkedlist(){};
};

#endif