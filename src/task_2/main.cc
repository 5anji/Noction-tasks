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

int main() {
  char checker;
  Linked_List list;
  do {
    std::cout << "1 - Display the list" << std::endl;
    std::cout << "2 - Add node at the end" << std::endl;
    std::cout << "c - Clear Screen" << std::endl;
    std::cout << "q - Exit" << std::endl;

    std::cout << "Choose option >>> ";
    std::cin >> checker;

    checker = tolower(checker);

    switch (checker) {
    case '1':
      list.Print_List();
      break;
    case '2': {
      std::string temp;
      std::cout << "Input data: ";
      std::cin >> temp;
      list.Add_Node_End(temp);
      break;
    }
    case 'c':
      system("clear");
      break;

    default:
      std::cout << "ERROR (no such option). Input again." << std::endl;
      break;
    }
  } while (checker != 'q');

  return 0;
}

Linked_List::Linked_List() {
  head = NULL;
  end = NULL;
}

void Linked_List::Print_List() {
  Node *current = head;

  while (current != NULL) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
}

void Linked_List::Add_Node_End(std::string data) {
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;

  if (head == NULL) {
    head = temp;
    end = temp;
  } else {
    end->next = temp;
    end = temp;
  }
}