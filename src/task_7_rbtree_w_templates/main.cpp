#include "tree.h"

// struct Test {
//     int i;
//     char c;

//     Test() {
//         i = 0;
//         c = 0;
//     }

//     friend bool operator<(Test const& a, Test const& b) {
//         return a.i < b.i;
//     }

//     friend std::ostream& operator<<(std::ostream& os, Test const& test) {
//         os << test.i << '.' << test.c;
//         return os;
//     }
// };

int main() {
    RedBlackTree<int> rbt;
    // Test test[15];

    for (size_t i = 1; i <= 30; i++) {
        rbt.insert(i);
    }

    rbt.printTree();

    return 0;
}
