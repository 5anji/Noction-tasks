#include "menu.h"

int main() {
    Linked_List list;
    signal(SIGINT, signalHandler);

    Menu m;
    m.run(list);
    m.run(list, "qwerty",&Linked_List::Add_Node_End);
    
    return 0;
}
