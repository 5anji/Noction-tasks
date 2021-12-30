#include "menu.h"

int main() {
    Linked_List list;
    signal(SIGINT, signalHandler);

    Menu m;
    m.run(list);

    return 0;
}
