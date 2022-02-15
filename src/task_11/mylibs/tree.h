#pragma once

// #include "../container.h"
#include "colors.h"

template <typename T>
struct Node_Tree {
    T data;
    Node_Tree<T>* parent;
    Node_Tree<T>* left;
    Node_Tree<T>* right;
    int color;
};

template <typename T>
class map : virtual public container<T> {
private:
    Node_Tree<T>* root;
    Node_Tree<T>* TNULL;
    size_t count = 0;
    Node_Tree<T>* searchTreeHelper(Node_Tree<T>* node, T key) {
        if (node == TNULL || key == node->data) { return node; }

        if (key < node->data) { return searchTreeHelper(node->left, key); }
        return searchTreeHelper(node->right, key);
    }

    void initializeNULLNode(Node_Tree<T>* node, Node_Tree<T>* parent) {
        node->data = 0;
        node->parent = parent;
        node->left = nullptr;
        node->right = nullptr;
        node->color = 0;
    }
    void preOrderHelper(Node_Tree<T>* node) {
        if (node != TNULL) {
            std::cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }
    void inOrderHelper(Node_Tree<T>* node) {
        if (node != TNULL) {
            inOrderHelper(node->left);
            std::cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }
    void postOrderHelper(Node_Tree<T>* node) {
        if (node != TNULL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            std::cout << node->data << " ";
        }
    }
    void deleteFix(Node_Tree<T>* x) {
        Node_Tree<T>* s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->right->color == 0) {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->left->color == 0) {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }
    void rbTransplant(Node_Tree<T>* u, Node_Tree<T>* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    void deleteNodeHelper(Node_Tree<T>* node, T key) {
        Node_Tree<T>* z = TNULL;
        Node_Tree<T>*x, *y;
        while (node != TNULL) {
            if (node->data == key) { z = node; }

            if (node->data <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (z == TNULL) {
            std::cout << "Key not found in the tree" << std::endl;
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == TNULL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == TNULL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) { deleteFix(x); }
    }
    void insertFix(Node_Tree<T>* k) {
        Node_Tree<T>* u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;

                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) { break; }
        }
        root->color = 0;
    }
    void printHelper(Node_Tree<T>* root, std::string indent, bool last) {
        if (root != TNULL) {
            std::cout << indent;
            if (last) {
                std::cout << Bold("R") << Orange("----");
                indent += "   ";
            } else {
                std::cout << Bold("L") << Orange("----");
                indent += Orange("|  ");
            }

            std::cout << (root->color ? "\033[1;31m" : "\033[1;34m") << root->data << "\033[0m" << std::endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }
    void printHelperRaw(Node_Tree<T>* root, bool last) {
        if (root != TNULL) {
            std::cout << root->data << std::endl;
            printHelperRaw(root->left, false);
            printHelperRaw(root->right, true);
        }
    }
    void returnHelperRaw(Node_Tree<T>* root, bool last, std::stringstream& ss) {
        if (root != TNULL) {
            ss << root->data << std::endl;
            printHelperRaw(root->left, false);
            printHelperRaw(root->right, true);
        }
    }

public:
    map() {
        TNULL = new Node_Tree<T>;
        TNULL->color = 0;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
        root = TNULL;
    }

    Node_Tree<T>* searchTree(int k) { return searchTreeHelper(this->root, k); }
    Node_Tree<T>* minimum(Node_Tree<T>* node) {
        while (node->left != TNULL) { node = node->left; }
        return node;
    }
    Node_Tree<T>* maximum(Node_Tree<T>* node) {
        while (node->right != TNULL) { node = node->right; }
        return node;
    }
    Node_Tree<T>* successor(Node_Tree<T>* x) {
        if (x->right != TNULL) { return minimum(x->right); }

        Node_Tree<T>* y = x->parent;
        while (y != TNULL && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }
    Node_Tree<T>* predecessor(Node_Tree<T>* x) {
        if (x->left != TNULL) { return maximum(x->left); }

        Node_Tree<T>* y = x->parent;
        while (y != TNULL && x == y->left) {
            x = y;
            y = y->parent;
        }

        return y;
    }
    Node_Tree<T>* getRoot() { return this->root; }

    std::stringstream Return_Tree_Raw() {
        std::stringstream ss;
        if (root) { returnHelperRaw(this->root, true, ss); }
        return ss;
    }

    void preorder() { preOrderHelper(this->root); }
    void inorder() { inOrderHelper(this->root); }
    void postorder() { postOrderHelper(this->root); }
    void leftRotate(Node_Tree<T>* x) {
        Node_Tree<T>* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) { y->left->parent = x; }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node_Tree<T>* x) {
        Node_Tree<T>* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) { y->right->parent = x; }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }
    void insert(T key) {
        Node_Tree<T>* node = new Node_Tree<T>;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = 1;

        Node_Tree<T>* y = nullptr;
        Node_Tree<T>* x = this->root;

        count++;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr) { return; }
        insertFix(node);
    }
    void deleteNode(int data) { deleteNodeHelper(this->root, data); }
    void print_alt() {
        if (root) { printHelper(this->root, "", true); }
    }
    void print() {
        if (root) { printHelperRaw(this->root, true); }
    }
    size_t size() { return count; }
};
