#include "container.h"

int main() {
    Linked_List<int> list1, list2;

    list1.Add_Node_End(13);
    list1.Add_Node_End(14);
    list2.Add_Node_End(15);
    list2.Add_Node_End(16);
    // list.Print_List_Raw();

    RedBlackTree<std::string> tree1, tree2;

    tree1.insert("q");
    tree1.insert("qw");
    tree2.insert("qwe");
    tree2.insert("qwer");
    // tree.Print_Tree_Raw();

    MegaList<int, std::string> test;

    test.Add(tree1);
    test.Add(list1);
    test.Add(tree2);
    test.Add(list2);
    // test.PrintAll();

    for (size_t i = 0; i < test.size(); i++) {
        std::cout << test[i];
    }

    return 0;
}
