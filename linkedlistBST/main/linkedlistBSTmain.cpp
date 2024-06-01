#include<iostream>
#include"Linkedlist.h"
 int main(){
    LLBST tree1;
    std::cout << "\nIs the tree empty?\n " << (tree1.isEmpty()? "yes": "no") << std::endl;

    std::cout << "\nAdding 10 and 5 to the tree\n" << std::endl;
    tree1.addBST(10);
    tree1.addBST(5);

    std::cout<<"\nis 5 in the tree?\n";
    tree1.searchBST(5);

    std::cout<<"\nRemoving 5 from the tree\n";
    tree1.removeBST(5);

    std::cout<<"\nis 5 in the tree?\n";
    tree1.searchBST(5);
    
    return 0;
 }