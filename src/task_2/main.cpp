#include "menu.h"

int main() {
  Linked_List list;
  signal(SIGINT, signalHandler);

  Menu m;
  // m.run(list);
  m.run(list, "qwerty", &Linked_List::Add_Node_End);
  m.run(list, &Linked_List::Print_List);

  return 0;
}
