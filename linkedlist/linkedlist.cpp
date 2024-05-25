#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
  Node* current = head;
  while (current != nullptr) {
    Node* temp = current;
    current = current->next;
    delete temp;
  }
}

bool LinkedList::isEmpty() {
  return head == nullptr;
}

void LinkedList::printList() {
  Node* current = head;
  std::cout << "List: ";
  while (current != nullptr) {
    std::cout << current->data << " -> ";
    current = current->next;
  }
  std::cout << "NULL" << std::endl;
}
