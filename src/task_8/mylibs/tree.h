#pragma once

#include <iostream>
#include <sstream>

template <typename T>
struct link {
    T data;
    link<T>* parent;
    link<T>* left;
    link<T>* right;
    int color;
};

template <typename T>
class RedBlackTree {
private:
    link<T>* root;
    link<T>* TNULL;

    void initializeNULLNode(link<T>* node, link<T>* parent);
    void preOrderHelper(link<T>* link);
    void inOrderHelper(link<T>* link);
    void postOrderHelper(link<T>* link);

    link<T>* searchTreeHelper(link<T>* link, T key);

    void deleteFix(link<T>* x);
    void rbTransplant(link<T>* u, link<T>* v);
    void deleteNodeHelper(link<T>* link, T key);
    void insertFix(link<T>* k);
    void printHelper(link<T>* root, std::string indent, bool last);
    void printHelperRaw(link<T>* root, bool last);
    void returnHelperRaw(link<T>* root, bool last, std::stringstream &ss);

public:
    RedBlackTree();

    void preorder();
    void inorder();
    void postorder();

    link<T>* searchTree(int k);
    link<T>* minimum(link<T>* link);
    link<T>* maximum(link<T>* link);
    link<T>* successor(link<T>* x);
    link<T>* predecessor(link<T>* x);

    void leftRotate(link<T>* x);
    void rightRotate(link<T>* x);
    void insert(T key);

    link<T>* getRoot();

    void deleteNode(int data);
    void Print_Tree();
    void Print_Tree_Raw();
    std::stringstream Return_Tree_Raw();
};

#include "tree.cpp"