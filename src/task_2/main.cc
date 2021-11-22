#include <iostream>
#include <cstring>
class Node {
public:
  int data;
  Node *next;
};

void display_list(Node *n) {
  while (n != NULL) {
    std::cout << n->data << ' ';
    n = n->next;
  }
}

int main() {
  // int n;
  // std::cout << "Input the lenght of the list: ";
  // std::cin >> n;

  // Node **list;
  // *list = new Node[n+1];
  // for (size_t i = 0; i <= n; i++) {
  //   // *list[i] = new Node;
  //   list[i] = NULL;
  // }
  // for (size_t i = 0; i < n; i++) {
  //   std::cout << "Input data for the element " << i + 1 << ": ";
  //   std::cin >> list[i]->data;
  //   list[i]->next = list[i + 1]; // seg-fault (why?)
  // }
  // display_list(list[0]);

  Node *n1 = NULL;
  Node *n2 = NULL;
  Node *n3 = NULL;
  Node *n4 = NULL;

  n1 = new Node;
  n2 = new Node;
  n3 = new Node;
  n4 = new Node;

  n1->data = 1;
  n1->next = n2;

  n2->data = 2;
  n2->next = n3;

  n3->data = 3;
  n3->next = n4;

  n4->data = 4;
  n4->next = NULL;
  display_list(n1);
  return 0;
}