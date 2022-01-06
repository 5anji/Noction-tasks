#include "colors.h"
#include "list.h"
#include "other.h"

struct Menu {
    void run(Linked_List& list);
    void run(Linked_List list, void (Linked_List::*func)());
    void run(Linked_List& list, std::string s, void (Linked_List::*func)(std::string));
    void run(Linked_List& list, size_t pos, void (Linked_List::*func)(size_t));
    void run(Linked_List& list, std::string s, size_t pos, void (Linked_List::*func)(std::string, size_t));
};
