#pragma once

#include "LinkedList.h"

class Queue : public LinkedList {
private:
  Node* tail; // Additional pointer for queue

public:
  void enqueue(int data);
  int dequeue();
  int front();
};
