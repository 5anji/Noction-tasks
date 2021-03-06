#include "tree.h"

void RedBlackTree::initializeNULLNode(Node* node, Node* parent) {
    node->data = 0;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
}

// Preorder
void RedBlackTree::preOrderHelper(Node* node) {
    if (node != TNULL) {
        std::cout << node->data << " ";
        preOrderHelper(node->left);
        preOrderHelper(node->right);
    }
}

// Inorder
void RedBlackTree::inOrderHelper(Node* node) {
    if (node != TNULL) {
        inOrderHelper(node->left);
        std::cout << node->data << " ";
        inOrderHelper(node->right);
    }
}

// Post order
void RedBlackTree::postOrderHelper(Node* node) {
    if (node != TNULL) {
        postOrderHelper(node->left);
        postOrderHelper(node->right);
        std::cout << node->data << " ";
    }
}

Node* RedBlackTree::searchTreeHelper(Node* node, int key) {
    if (node == TNULL || key == node->data) { return node; }

    if (key < node->data) { return searchTreeHelper(node->left, key); }
    return searchTreeHelper(node->right, key);
}

// For balancing the tree after deletion
void RedBlackTree::deleteFix(Node* x) {
    Node* s;
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

void RedBlackTree::rbTransplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::deleteNodeHelper(Node* node, int key) {
    Node* z = TNULL;
    Node *x, *y;
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
void RedBlackTree::insertFix(Node* k) {
    Node* u;
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

void RedBlackTree::printHelper(Node* root, std::string indent, bool last) {
    if (root != TNULL) {
        std::cout << indent;
        if (last) {
            std::cout << Bold("R") << Orange("----");
            indent += "   ";
        } else {
            std::cout << Bold("L") << Orange("----");
            indent += Orange("|  ");
        }

        std::cout << Bold(root->color ? Red(std::to_string(root->data)) : Blue(std::to_string(root->data))) << std::endl;
        printHelper(root->left, indent, false);
        printHelper(root->right, indent, true);
    }
}

RedBlackTree::RedBlackTree() {
    TNULL = new Node;
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    root = TNULL;
}

void RedBlackTree::preorder() { preOrderHelper(this->root); }

void RedBlackTree::inorder() { inOrderHelper(this->root); }

void RedBlackTree::postorder() { postOrderHelper(this->root); }

Node* RedBlackTree::searchTree(int k) { return searchTreeHelper(this->root, k); }

Node* RedBlackTree::minimum(Node* node) {
    while (node->left != TNULL) { node = node->left; }
    return node;
}

Node* RedBlackTree::maximum(Node* node) {
    while (node->right != TNULL) { node = node->right; }
    return node;
}

Node* RedBlackTree::successor(Node* x) {
    if (x->right != TNULL) { return minimum(x->right); }
    
    Node* y = x->parent;
    while (y != TNULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

Node* RedBlackTree::predecessor(Node* x) {
    if (x->left != TNULL) { return maximum(x->left); }

    Node* y = x->parent;
    while (y != TNULL && x == y->left) {
        x = y;
        y = y->parent;
    }

    return y;
}

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
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

void RedBlackTree::rightRotate(Node* x) {
    Node* y = x->left;
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
void RedBlackTree::insert(int key) {
    Node* node = new Node;
    node->parent = nullptr;
    node->data = key;
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    Node* y = nullptr;
    Node* x = this->root;

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

Node* RedBlackTree::getRoot() { return this->root; }

void RedBlackTree::deleteNode(int data) { deleteNodeHelper(this->root, data); }

void RedBlackTree::printTree() {
    if (root) { printHelper(this->root, "", true); }
}