#include <iostream>
#include "Linkedlist.cpp"
//program

int main()
{

    Linkedlist list1; // Creating list

    list1.addToHead(1);
    list1.addToTail(2);
    list1.addToHead(3);

    list1.displayHead();
    list1.displayTail();

    Node *pointer = list1.find(2, list1); // find return the node pointer
    // std::cout << &pointer << "\n"; ////it prints memory address

    list1.insert(9, 1, list1); // inserting data 9 after 1

    list1.displayAllData(list1);
};

/**
 * NOTE:(FIND RUNNING TWICE)
 * -> it is because, displayAllData() is also using find() function. Inside find function there is std::cout << ....
 */