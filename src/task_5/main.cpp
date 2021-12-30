// Implementing Red-Black Tree in C++

#include "tree.h"
// #include <random>

int main() {
  RedBlackTree bst;
  // std::random_device generator;
  // std::uniform_int_distribution<int> distribution(1, 100);

  for (size_t i = 0; i < 25; i++) {
    bst.insert(i+1);
  }
  

  bst.printTree();

  for (size_t i = 3; i < 6; i++)
  {
    bst.deleteNode(i+1);
  }
  
  // std::cout << std::endl
  //           << "After deleting" << std::endl;
  // bst.deleteNode(40);
  bst.printTree();
}