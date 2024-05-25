#pragma once

#include "Node.h"

class LinkedList {
protected:
  Node* head;

public:
  LinkedList();
  ~LinkedList();
  virtual bool isEmpty() = 0; // Pure virtual function (implemented in subclasses)
  void printList();
};
