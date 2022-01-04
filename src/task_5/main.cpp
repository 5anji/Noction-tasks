#include "tree.h"
// #include <random>

int main() {
    RedBlackTree bst;
    // std::random_device generator;
    // std::uniform_int_distribution<int> distribution(1, 100);

    for (size_t i = 1; i < 10; i++) bst.insert(i);

    bst.printTree();

    // for (size_t i = 3; i < 6; i++) bst.deleteNode(i + 1);


    // bst.rightRotate(bst.searchTree(6));
    bst.leftRotate(bst.searchTree(8));
    std::cout << std::endl << "After deleting" << std::endl;
    // bst.deleteNode(40);       
    bst.printTree();
}