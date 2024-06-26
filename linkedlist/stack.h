#pragma once

#include "LinkedList.h"

class Stack : public LinkedList {
public:
  void push(int data);
  int pop();
  int peek();
};
