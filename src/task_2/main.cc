#include <iostream>

class Node {
public:
  int data;
  Node *next;
};

void display_list(Node *n) {
  while (n != nullptr) {
    std::cout << n->data << ' ';
    n = n->next;
  }
}

int main() {
  int n;
  std::cout << "Input the lenght of the list: ";
  std::cin >> n;

  Node *list[n+1];
  for (size_t i = 0; i <= n; i++)
    list[i] = nullptr;

  for (size_t i = 0; i < n; i++) {
    std::cout << "Input data for the element " << i + 1 << ": ";
    std::cin >> list[i]->data;
    list[i]->next = list[i + 1]; // seg-fault (why?)
  }
  display_list(list[0]);
  return 0;
}