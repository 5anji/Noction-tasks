#include "list.h"
#include "colors.h"
#include "other.h"

// structure

struct Node {
  std::string data;
  Node *next;
};

// class functions

Linked_List::Linked_List() {
  head = nullptr;
  end = nullptr;
}

void Linked_List::Print_List() {
  Node *current = head;
  int i = 1;

  while (current != nullptr) {
    std::cout << i << ") " << current->data << std::endl;
    current = current->next;
    i++;
  }

  std::cout << std::endl;
}

void Linked_List::Add_Node_End(std::string data) {
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
  if (head->next == nullptr)
    delete head;

  Node *current = head;

  while (current->next->next != nullptr)
    current = current->next;

  delete current->next;

  current->next = nullptr;
}

void Linked_List::Del_Node_Start() {
  Node *next_node = nullptr;

  next_node = head->next;
  std::string d = head->data;

  delete head;

  head = next_node;
}

void Linked_List::Del_Node_Position(int position) {
  Node *current = head;
  Node *temp_node = nullptr;

  if (position == 1) {
    Linked_List::Del_Node_Start();
    return;
  }

  for (size_t i = 1; i < position - 1; i++) {
    if (current->next == nullptr) {
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
  Node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    delete current;
    current = next;
  }

  head = nullptr;
}
