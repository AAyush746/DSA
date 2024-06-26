#include "Queue.h"
#include <iostream>

Queue::Queue() : LinkedList(), tail(nullptr) {}

void Queue::enqueue(int data) {
  Node* newNode = new Node(data);
  if (isEmpty()) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

int Queue::dequeue() {
  if (isEmpty()) {
    std::cout << "Queue Underflow!" << std::endl;
    return -1; // Or throw an exception
  }

  Node* temp = head;
  int data = temp->data;
  head = head->next;
  if (head == nullptr) {
    tail = nullptr; // Queue becomes empty
  }
  delete temp;
  return data;
}

int Queue::front() {
  if (isEmpty()) {
    std::cout << "Queue is Empty!" << std::endl;
    return -1; // Or throw an exception
  }

  return head->data;
}
