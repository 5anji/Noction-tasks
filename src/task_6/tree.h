#pragma once

#include "colors.h"

#include <iostream>

template <typename Type>
class Node {
public:
    Type data;
    Node<Type>* parent;
    Node<Type>* left;
    Node<Type>* right;
    int color;
};

template <typename Type>
class RedBlackTree {
private:
    Node<Type>* root;
    Node<Type>* TNULL;

    void initializeNULLNode(Node<Type>* node, Node<Type>* parent);
    void preOrderHelper(Node<Type>* node);
    void inOrderHelper(Node<Type>* node);
    void postOrderHelper(Node<Type>* node);

    Node<Type>* searchTreeHelper(Node<Type>* node, Type key);

    void deleteFix(Node<Type>* x);
    void rbTransplant(Node<Type>* u, Node<Type>* v);
    void deleteNodeHelper(Node<Type>* node, Type key);
    void insertFix(Node<Type>* k);
    void printHelper(Node<Type>* root, std::string indent, bool last);

public:
    RedBlackTree();

    void preorder();
    void inorder();
    void postorder();

    Node<Type>* searchTree(int k);
    Node<Type>* minimum(Node<Type>* node);
    Node<Type>* maximum(Node<Type>* node);
    Node<Type>* successor(Node<Type>* x);
    Node<Type>* predecessor(Node<Type>* x);

    void leftRotate(Node<Type>* x);
    void rightRotate(Node<Type>* x);
    void insert(Type key);

    Node<Type>* getRoot();

    void deleteNode(int data);
    void printTree();
};

#include "tree.cpp"