#include "list.h"

#include "colors.h"

// class functions

template <typename T>
Linked_List<T>::Linked_List()
        : head(nullptr)
        , end(nullptr) {}

template <typename T>
Linked_List<T>::Linked_List(T data)
        : head(nullptr)
        , end(nullptr) {
    Add_Node_End(data);
}

template <typename T>
Linked_List<T>::Linked_List(Linked_List<T>& list)
        : head(nullptr)
        , end(nullptr) {
    Node<T>* current = list.head;

    while (current != nullptr) {
        Add_Node_End(current->data);
        current = current->next;
    }
}

template <typename T>
void Linked_List<T>::operator=(const Linked_List<T>& copy) {
    Del_List();
    Node<T>* current = copy.head;

    while (current != nullptr) {
        Add_Node_End(current->data);
        current = current->next;
    }
}

template <typename T>
Linked_List<T> Linked_List<T>::operator+(const T data) {
    Add_Node_End(data);
    return *this;
}

template <typename T>
Linked_List<T> operator+(const T data, Linked_List<T> list) {
    list.Add_Node_Start(data);
    return list;
}

template <typename T>
void Linked_List<T>::operator+=(const T data) { Add_Node_End(data); }

template <typename T>
std::ostream& operator<<(std::ostream& os, const Linked_List<T> list) {
    Node<T>* current = list.head;
    int i = 1;
    bool checker = true;

    while (current != nullptr) {
        os << i << ") " << current->data << std::endl;
        current = current->next;
        checker = false;
        i++;
    }

    if (checker) os << "The list is empty" << std::endl;

    os << std::endl;

    return os;
}

template <typename T>
Linked_List<T>::~Linked_List<T>() {
    Del_List();
}

template <typename T>
void Linked_List<T>::Print_List() {
    Node<T>* current = head;
    int i = 1;
    bool checker = true;

    while (current != nullptr) {
        std::cout << i << ") " << current->data << std::endl;
        current = current->next;
        checker = false;
        i++;
    }

    if (checker) std::cout << "The list is empty" << std::endl;

    std::cout << std::endl;
}

template <typename T>
void Linked_List<T>::Print_List_Raw() {
    Node<T>* current = head;
    bool checker = true;

    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
        checker = false;
    }

    if (checker) std::cout << "The list is empty" << std::endl;
}

template <typename T>
std::stringstream Linked_List<T>::Return_List_Raw() {
    std::stringstream ss;
    Node<T>* current = head;
    bool checker = true;

    while (current != nullptr) {
        ss << current->data << std::endl;
        current = current->next;
        checker = false;
    }

    if (checker) ss << "The list is empty" << std::endl;

    return ss;
}

template <typename T>
void Linked_List<T>::Add_Node_End(T data) {
    Node<T>* temp = new Node<T>;
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

template <typename T>
void Linked_List<T>::Add_Node_Start(T data) {
    Node<T>* temp;
    temp = new Node<T>;

    temp->data = data;
    temp->next = head;

    head = temp;
}

template <typename T>
void Linked_List<T>::Add_Node_Position(T data, size_t position) {
    Node<T>* previous = new Node<T>;
    Node<T>* current = new Node<T>;
    Node<T>* temp = new Node<T>;

    current = head;

    for (size_t i = 1; i < position; i++) {
        previous = current;
        current = current->next;
    }

    temp->data = data;
    previous->next = temp;
    temp->next = current;
}

template <typename T>
void Linked_List<T>::Del_Node_End() {
    if (head->next == nullptr) {
        head = nullptr;
        delete head;
        return;
    } else {
        Node<T>* current = head;

        while (current->next->next != nullptr) current = current->next;

        delete current->next;

        current->next = nullptr;
    }
}

template <typename T>
void Linked_List<T>::Del_Node_Start() {
    Node<T>* next_node = nullptr;

    next_node = head->next;

    delete head;

    head = next_node;
}

template <typename T>
void Linked_List<T>::Del_Node_Position(size_t position) {
    Node<T>* current = head;
    Node<T>* temp_node = nullptr;

    if (position == 1) {
        Linked_List<T>::Del_Node_Start();
        return;
    }

    for (size_t i = 1; i < position - 1; i++) {
        if (current->next == nullptr) {
            Linked_List<T>::Del_Node_End();
            return;
        }
        current = current->next;
    }

    temp_node = current->next;
    current->next = temp_node->next;

    delete temp_node;
}

template <typename T>
void Linked_List<T>::Edit_Data(T data, size_t position) {
    Node<T>* current = head;

    for (size_t i = 1; i < position; i++) current = current->next;

    current->data = data;
}

template <typename T>
void Linked_List<T>::Del_List() {
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
}

template <typename T>
void Linked_List<T>::Copy_List(Linked_List<T>& copy) {
    Node<T>* current = head;

    while (current != nullptr) {
        copy.Add_Node_End(current->data);
        current = current->next;
    }
}