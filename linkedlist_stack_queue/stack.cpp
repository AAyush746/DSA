#include "Stack.h"
#include <iostream>

void Stack::push(int data) {
  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
}

int Stack::pop() {
  if (isEmpty()) {
    std::cout << "Stack Underflow!" << std::endl;
    return -1; // Or throw an exception
  }

  Node* temp = head;
  int data = temp->data;
  head = head->next;
  delete temp;
  return data;
}

int Stack::peek() {
  if (isEmpty()) {
    std::cout << "Stack is Empty!" << std::endl;
    return -1; // Or throw an exception
  }

  return head->data;
}
