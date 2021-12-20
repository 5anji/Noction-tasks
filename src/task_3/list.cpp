#include "list.h"
#include "colors.h"
#include "other.h"

// structure

struct Node {
  std::string data;
  Node *next;
};


// class functions

void Print_List() {
  Node *current = head;
  int i = 1;
  bool checker = true;

  while (current != nullptr) {
    std::cout << i << ") " << current->data << std::endl;
    current = current->next;
    checker = false;
    i++;
  }

  if (checker)
    std::cout << "The list is empty" << std::endl;

  std::cout << std::endl;
}

void Add_Node_End(std::string data) {
  Node *temp = new Node;
  temp->data = data;
  temp->next = nullptr;

  if (head == nullptr) {
    head = temp;
    end = temp;
  } else {
    end->next = temp;
    end = temp;
  }
}

void Add_Node_Start(std::string data) {
  Node *temp;
  temp = new Node;

  temp->data = data;
  temp->next = head;

  head = temp;
}

void Add_Node_Position(std::string data, size_t position) {
  Node *previous = new Node;
  Node *current = new Node;
  Node *temp = new Node;

  current = head;

  for (size_t i = 1; i < position; i++) {
    previous = current;
    current = current->next;
  }

  temp->data = data;
  previous->next = temp;
  temp->next = current;
}

void Del_Node_End() {
  if (head->next == nullptr) {
    head = nullptr;
    delete head;
    return;
  } else {
    Node *current = head;

    while (current->next->next != nullptr)
      current = current->next;

    delete current->next;

    current->next = nullptr;
  }
}

void Del_Node_Start() {
  Node *next_node = nullptr;

  next_node = head->next;

  delete head;

  head = next_node;
}

void Del_Node_Position(size_t position) {
  Node *current = head;
  Node *temp_node = nullptr;

  if (position == 1) {
    Del_Node_Start();
    return;
  }

  for (size_t i = 1; i < position - 1; i++) {
    if (current->next == nullptr) {
      Del_Node_End();
      return;
    }
    current = current->next;
  }

  temp_node = current->next;
  current->next = temp_node->next;

  delete temp_node;
}

void Edit_Data(std::string data, size_t position) {
  Node *current = head;

  for (size_t i = 1; i < position; i++)
    current = current->next;

  current->data = data;
}

void Del_List() {
  Node *current = head;
  Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }

  head = nullptr;
}
