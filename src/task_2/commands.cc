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
  int i = 1;

  while (current != NULL) {
    std::cout << i << ") " << current->data << std::endl;
    current = current->next;
    i++;
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

void Linked_List::Del_Node_End() {
  if (head->next == NULL)
    delete head;

  Node *current = head;

  while (current->next->next != NULL)
    current = current->next;

  delete current->next;

  current->next = NULL;
}

void Linked_List::Del_Node_Start() {
  Node *next_node = NULL;

  next_node = head->next;
  std::string d = head->data;

  delete head;

  head = next_node;
}

void Linked_List::Del_Node_Position(int position) {
  Node *current = head;
  Node *temp_node = NULL;

  if (position == 1) {
    Linked_List::Del_Node_Start();
    return;
  }

  for (size_t i = 1; i < position - 1; i++) {
    if (current->next == NULL) {
      Linked_List::Del_Node_End();
      return;
    }
    current = current->next;
  }

  temp_node = current->next;
  current->next = temp_node->next;

  delete temp_node;
}

void Linked_List::Edit_Data(std::string data, int position) {
  Node *current = head;

  for (size_t i = 1; i < position; i++)
    current = current->next;

  current->data = data;
}

void Linked_List::Del_List() {
  Node *current = head;
  Node *next = NULL;

  while (current != NULL) {
    next = current->next;
    delete current;
    current = next;
  }

  head = NULL;
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

void signalHandler(int position) {
  if (position == 2) {
    std::cout << std::endl
              << Bold(Red(":( Use q option instead of Ctrl+C")) << std::endl;
    exit(position);
  }
}