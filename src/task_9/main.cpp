#include "mylibs/stl.h"

int main() {
    pseudo_stl::map<int> tree1, tree2;
    pseudo_stl::list<int> list1, list2;
    pseudo_stl::vector<pseudo_stl::container<int>*> vec;
    pseudo_stl::container<int>*c1, *c2, *c3, *c4;

    c1 = &tree1;
    c2 = &list2;
    c3 = &list1;
    c4 = &tree2;

    tree1.insert(1);
    list1.Add_Node_End(2);

    vec.push_back(c1);
    vec.push_back(c2);
    vec.push_back(c3);
    vec.push_back(c4);

    list2.Add_Node_End(3);
    tree2.insert(4);

    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i]->size() << ' ';
        vec[i]->print();
    }

    return 0;
}