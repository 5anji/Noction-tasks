// #include "mylibs/list.h"
// #include "mylibs/tree.h"

// int main() {
//     RedBlackTree<std::string> tree;
//     Linked_List<int> list;

//     for (size_t i = 1; i <= 30; i++) {
//         tree.insert(std::to_string(i));
//         list.Add_Node_End(i);
//     }

//     tree.Print_Tree();
//     list.Print_List();

//     std::cout << sizeof(tree) << '\t' << sizeof(list) << std::endl;
//     return 0;
// }
// C++ program to find modular inverse of a
// under modulo m using Fermat's little theorem.
// This program works only if m is prime.

#include <bits/stdc++.h>

// To compute x raised to power y under modulo m
int power(int x, unsigned int y, unsigned int m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m) {
    if (std::__gcd(a, m) != 1)
        std::cout << "Inverse doesn't exist";

    else {

        // If a and m are relatively prime, then
        // modulo inverse is a^(m-2) mode m
        std::cout << "Modular multiplicative inverse is "
                  << power(a, m - 2, m) << std::endl;
    }
}

// To compute x^y under modulo m
int power(int x, unsigned int y, unsigned int m) {
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}

// Driver Program
int main() {
    int a = 16, m = 63;
    while (1) {
        std::cin >> a >> m;
        modInverse(a, m);
    }

    return 0;
}
