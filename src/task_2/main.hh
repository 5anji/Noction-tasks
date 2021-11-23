#include <iostream>

struct Node {
  std::string data;
  Node *next;
};

class Linked_List {
private:
  Node *head;
  Node *end;

public:
  Linked_List();
  void Print_List();
  void Add_Node_End(std::string data);
};
