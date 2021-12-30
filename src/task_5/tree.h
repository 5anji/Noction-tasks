#include "colors.h"

#include <iostream>
struct Node;

// typedef Node *NodePtr;

class RedBlackTree {
private:
    Node* root;
    Node* TNULL;

    void initializeNULLNode(Node* node, Node* parent);
    void preOrderHelper(Node* node);
    void inOrderHelper(Node* node);
    void postOrderHelper(Node* node);

    Node* searchTreeHelper(Node* node, int key);

    void deleteFix(Node* x);
    void rbTransplant(Node* u, Node* v);
    void deleteNodeHelper(Node* node, int key);
    void insertFix(Node* k);
    void printHelper(Node* root, std::string indent, bool last);

public:
    RedBlackTree();

    void preorder();
    void inorder();
    void postorder();

    Node* searchTree(int k);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    Node* successor(Node* x);
    Node* predecessor(Node* x);

    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insert(int key);

    Node* getRoot();

    void deleteNode(int data);
    void printTree();
};
