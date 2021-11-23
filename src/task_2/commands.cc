#include "main.hh"

// structure

struct Node {
  std::string data;
  Node *next;
};

// class functions

Linked_List::Linked_List() {
  head = NULL;
  end = NULL;
}

void Linked_List::Print_List() {
  Node *current = head;

  while (current != NULL) {
    std::cout << "* " << current->data << std::endl;
    current = current->next;
  }

  std::cout << std::endl;
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

void Linked_List::Add_Node_Start(std::string data) {
  Node *temp;
  temp = new Node;

  temp->data = data;
  temp->next = head;

  head = temp;
}

void Linked_List::Add_Node_Position(std::string data, int position) {
  Node *previous = new Node;
  Node *current = new Node;
  Node *temp = new Node;
  current = head;

  for (int i = 1; i < position; i++) {
    previous = current;
    current = current->next;
  }
  temp->data = data;
  previous->next = temp;
  temp->next = current;
}
// color functions

std::string Black(std::string str) { return "\033[30m" + str + "\033[0m"; }

std::string Red(std::string str) { return "\033[31m" + str + "\033[0m"; }

std::string Green(std::string str) { return "\033[32m" + str + "\033[0m"; }

std::string Orange(std::string str) { return "\033[33m" + str + "\033[0m"; }

std::string Blue(std::string str) { return "\033[34m" + str + "\033[0m"; }

std::string Purple(std::string str) { return "\033[35m" + str + "\033[0m"; }

std::string Cyan(std::string str) { return "\033[36m" + str + "\033[0m"; }

std::string Gray(std::string str) { return "\033[37m" + str + "\033[0m"; }

std::string Bold(std::string str) { return "\033[1m" + str + "\033[0m"; }

std::string Underline(std::string str) { return "\033[4m" + str + "\033[0m"; }

void signalHandler(int n) {
  if (n == 2) {
    std::cout << std::endl << Bold(Red(":( Use q option instead of Ctrl+C")) << std::endl;
    exit(n);
  }
}