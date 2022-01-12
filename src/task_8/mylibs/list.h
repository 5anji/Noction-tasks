#pragma once

#include <iostream>
#include <sstream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class Linked_List {
public:
    Node<T>* head;
    Node<T>* end;

public:
    Linked_List();
    Linked_List(T data);
    Linked_List(Linked_List<T>& list);
    ~Linked_List();

    void operator=(const Linked_List<T>& copy);
    Linked_List<T> operator+(const T data);
    // friend Linked_List<T> operator+(T data, Linked_List<T> list);
    void operator+=(const T data);
    // friend std::ostream& operator<<(std::ostream& os, const Linked_List<T> list);

    void Print_List();
    void Print_List_Raw();
    std::stringstream Return_List_Raw();
    void Add_Node_End(T data);
    void Add_Node_Start(T data);
    void Add_Node_Position(T data, size_t position);
    void Del_Node_End();
    void Del_Node_Start();
    void Del_Node_Position(size_t position);
    void Edit_Data(T data, size_t position);
    void Del_List();
    void Copy_List(Linked_List<T>& copy);
};

#include "list.cpp"