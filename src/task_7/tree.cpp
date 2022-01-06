#include "tree.h"

std::string Black(std::string str) { return "\033[30m" + str + "\033[0m"; }

std::string Red(std::string str) { return "\033[31m" + str + "\033[0m"; }

std::string Green(std::string str) { return "\033[32m" + str + "\033[0m"; }

std::string Orange(std::string str) { return "\033[33m" + str + "\033[0m"; }

std::string Blue(std::string str) { return "\033[34m" + str + "\033[0m"; }

std::string Purple(std::string str) { return "\033[35m" + str + "\033[0m"; }

std::string Cyan(std::string str) { return "\033[36m" + str + "\033[0m"; }

std::string Gray(std::string str) { return "\033[37m" + str + "\033[0m"; }

std::string Bold(std::string str) { return "\033[1m" + str + "\033[0m"; }

std::string Underline(std::string str) { return "\033[4m" + str + "\033[0m"; }

template <typename Type>
void RedBlackTree<Type>::initializeNULLNode(Node<Type>* node, Node<Type>* parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

// Preorder
template <typename Type>
void RedBlackTree<Type>::preOrderHelper(Node<Type>* node) {
    if (node != TNULL) {
        std::cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

// Inorder
template <typename Type>
void RedBlackTree<Type>::inOrderHelper(Node<Type>* node) {
    if (node != TNULL) {
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

// Post order
template <typename Type>
void RedBlackTree<Type>::postOrderHelper(Node<Type>* node) {
    if (node != TNULL) {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->data << " ";
    }
}

template <typename Type>
Node<Type>* RedBlackTree<Type>::searchTreeHelper(Node<Type>* node, Type key) {
    if (node == TNULL || key == node->data) { return node; }

    if (key < node->data) { return searchTreeHelper(node->left, key); }
    return searchTreeHelper(node->right, key);
}

// For balancing the tree after deletion
template <typename Type>
void RedBlackTree<Type>::deleteFix(Node<Type>* x) {
    Node<Type>* s;
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

template <typename Type>
void RedBlackTree<Type>::rbTransplant(Node<Type>* u, Node<Type>* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template <typename Type>
void RedBlackTree<Type>::deleteNodeHelper(Node<Type>* node, Type key) {
    Node<Type>* z = TNULL;
    Node<Type>*x, *y;
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

// For balancing the tree after insertion
template <typename Type>
void RedBlackTree<Type>::insertFix(Node<Type>* k) {
    Node<Type>* u;
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

template <typename Type>
void RedBlackTree<Type>::printHelper(Node<Type>* root, std::string indent, bool last) {
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

template <typename Type>
RedBlackTree<Type>::RedBlackTree() {
    TNULL = new Node<Type>;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

template <typename Type>
void RedBlackTree<Type>::preorder() { preOrderHelper(this->root); }

template <typename Type>
void RedBlackTree<Type>::inorder() { inOrderHelper(this->root); }

template <typename Type>
void RedBlackTree<Type>::postorder() { postOrderHelper(this->root); }

template <typename Type>
Node<Type>* RedBlackTree<Type>::searchTree(int k) { return searchTreeHelper(this->root, k); }

template <typename Type>
Node<Type>* RedBlackTree<Type>::minimum(Node<Type>* node) {
    while (node->left != TNULL) { node = node->left; }
    return node;
}

template <typename Type>
Node<Type>* RedBlackTree<Type>::maximum(Node<Type>* node) {
    while (node->right != TNULL) { node = node->right; }
    return node;
}

template <typename Type>
Node<Type>* RedBlackTree<Type>::successor(Node<Type>* x) {
    if (x->right != TNULL) { return minimum(x->right); }

    Node<Type>* y = x->parent;
    while (y != TNULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename Type>
Node<Type>* RedBlackTree<Type>::predecessor(Node<Type>* x) {
    if (x->left != TNULL) { return maximum(x->left); }

    Node<Type>* y = x->parent;
    while (y != TNULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

template <typename Type>
void RedBlackTree<Type>::leftRotate(Node<Type>* x) {
    Node<Type>* y = x->right;
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

template <typename Type>
void RedBlackTree<Type>::rightRotate(Node<Type>* x) {
    Node<Type>* y = x->left;
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

// Inserting a node
template <typename Type>
void RedBlackTree<Type>::insert(Type key) {
    Node<Type>* node = new Node<Type>;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    Node<Type>* y = nullptr;
    Node<Type>* x = this->root;

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

template <typename Type>
Node<Type>* RedBlackTree<Type>::getRoot() { return this->root; }

template <typename Type>
void RedBlackTree<Type>::deleteNode(int data) { deleteNodeHelper(this->root, data); }

template <typename Type>
void RedBlackTree<Type>::printTree() {
    if (root) { printHelper(this->root, "", true); }
}
