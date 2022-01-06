#include "tree.h"

struct Test {
    int i;
    char c;

    Test() {
        i = 0;
        c = 0;
    }

    friend bool operator<(Test const& a, Test const& b) {
        return a.i < b.i;
    }

    friend std::ostream& operator<<(std::ostream& os, Test const& test) {
        os << test.i << '.' << test.c;
        return os;
    }
};

int main() {
    RedBlackTree<Test> rbt;
    Test test[15];

    for (size_t i = 0; i < 15; i++) {
        test[i].i = i + 1;
        test[i].c = 'a' + i;
        rbt.insert(test[i]);
    }

    rbt.printTree();

    return 0;
}
