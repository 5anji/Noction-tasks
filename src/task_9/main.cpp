#include "mylibs/stl.h"

int main() {
    pseudo_stl::map<int> tree1, tree2;
    pseudo_stl::list<int> list1, list2;
    
    pseudo_stl::vector<pseudo_stl::container<int>*> vec;
    pseudo_stl::container<int>* c[4];

    c[0] = &tree1;
    c[1] = &list2;
    c[2] = &list1;
    c[3] = &tree2;

    tree1.insert(1);
    list1.Add_Node_End(2);

    for (size_t i = 0; i < 4; i++) {
        vec.push_back(c[i]);
    }

    list2.Add_Node_End(3);
    tree2.insert(4);

    for (size_t i = 0; i < vec.size(); i++) {
        // std::cout << vec[i]->size() << ' ';
        vec[i]->print();
    }

    return 0;
}