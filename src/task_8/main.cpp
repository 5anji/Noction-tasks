// #include "mylibs/list.h"
// #include "mylibs/tree.h"

// #include <vector>

// int main() {
//     std::vector<Container<int>*> vec;
//     RedBlackTree<int> tree1, tree2;
//     Linked_List<int> list1, list2;

//     tree1.insert(1);
//     list1.Add_Node_End(2);

//     vec.push_back(&tree1);
//     vec.push_back(&list1);
//     vec.push_back(&list2);
//     vec.push_back(&tree2);

//     list2.Add_Node_End(3);
//     tree2.insert(4);

//     for (size_t i = 0; i < vec.size(); i++) {
//         vec[i]->Print_Raw();
//     }

//     return 0;
// }

#include <iostream>
#include <vector>

struct Animals {
    virtual void say() {
        std::cout << "Hello World" << std::endl;
    }
};

struct Cat : virtual private Animals {
    virtual void say() {
        std::cout << "Miau" << std::endl;
    }
};

struct Dog : virtual public Animals {
    virtual void say() {
        std::cout << "Gaf" << std::endl;
    }
};

struct Mammals : public Cat, public Dog {
    void say() {
        std::cout << "Mu" << std::endl;
    }
};


int main() {
    std::vector<Animals*> vec;
    Dog d;
    Cat c;
    Mammals m;
    Animals* a1, *a2, *a3;

    a1 = &d;
    a2 = reinterpret_cast<Animals*>(&c);
    a3 = &m;

    vec.push_back(a1);
    vec.push_back(a2);
    vec.push_back(a3);
    
    for (size_t i = 0; i < vec.size(); i++) {
        vec[i]->say();
    }


    return 0;
}