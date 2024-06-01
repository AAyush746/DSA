#include "bst.h"
#include <iostream>

class BSTArray : public BST {
private:
  int arr[100]; // Change the size as needed
  int size;

public:
  BSTArray() : size(0) {}
  ~BSTArray() {}

  bool isEmpty() override {
    return size == 0;
  }

  int searchIndex(int key) {
    for (int i = 0; i < size; ++i) {
      if (arr[i] == key) {
        return i;
      }
    }
    return -1;
  }

  void addBST(int key) override {
    if (isEmpty()) {
      arr[size++] = key;
      return;
    }

    int index = 0;
    while (index < size) {
      if (key < arr[index]) {
        index = 2 * index + 1; // Move to left child position
      } else {
        index = 2 * index + 2; // Move to right child position
      }

      if (index >= size) {
        break;
      }
    }

    // Insert at the calculated position (considering leaves)
    for (int i = size; i > index; --i) {
      arr[i] = arr[i - 1];
    }
    arr[index] = key;
    size++;
  }

  bool searchBST(int targetkey) override {
    return searchIndex(targetkey) != -1;
  }

  void removeBST(int keytodelete) override {
    int index = searchIndex(keytodelete);
    if (index == -1) {
      return; // Key not found
    }

    // Copy the last element to the deleted position
    arr[index] = arr[size - 1];
    size--;

    // Maintain BST property during deletion (rebalancing)
    int parent = (index - 1) / 2;
    while (parent >= 0 && arr[index] < arr[parent]) {
      std::swap(arr[index], arr[parent]);
      index = parent;
      parent = (index - 1) / 2;
    }
  }
};
int main() {
  BSTArray b;

  // Add elements
  b.addBST(5);
  b.addBST(3);
  b.addBST(8);

  // Search for elements
  if (b.searchBST(3)) {
    std::cout << "Found 3" << std::endl;
  } else {
    std::cout << "3 not found" << std::endl;
  }

  if (b.searchBST(10)) {
    std::cout << "Found 10" << std::endl;
  } else {
    std::cout << "10 not found" << std::endl;
  }

  // Remove element
  b.removeBST(5);

  // Additional operations...

  return 0;
}