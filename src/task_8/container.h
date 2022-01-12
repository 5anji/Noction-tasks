#pragma once

#include "mylibs/list.h"
#include "mylibs/tree.h"

template <typename L, typename T>
class MegaList : public Linked_List<L>, public RedBlackTree<T>{
private:
    std::string log;
    int count;
    std::string elements[64];
public:
    MegaList() {
        log = "";
        count = 0;
    }

    void PrintAll() {
        // Linked_List<L>::Print_List();
        std::cout << log;
    }

    void Add(Linked_List<L> list) {
        elements[count] = list.Return_List_Raw().str();
        log += elements[count];
        count++;
    }

    void Add(RedBlackTree<T> tree) {
        elements[count] = tree.Return_Tree_Raw().str();
        log += elements[count];
        count++;
    }

    std::string& operator[](int pos) {
        return elements[pos];
    }
    
    int size() {
        return count;
    }

    ~MegaList() {
        log.clear();
    }
};
