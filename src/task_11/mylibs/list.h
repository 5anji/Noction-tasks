#pragma once

// #include "../container.h"
#include "colors.h"

template <typename T>
struct Node_List {
    T data;
    Node_List* next;
};

template <typename T>
class list : virtual public container<T> {
private:
    Node_List<T>* head;
    Node_List<T>* end;
    size_t count = 0;

public:
    list()
            : head(nullptr)
            , end(nullptr) {}
    list(T data)
            : head(nullptr)
            , end(nullptr) {
        Add_Node_End(data);
    }
    list(list<T> const& list)
            : head(nullptr)
            , end(nullptr) {
        Node_List<T>* current = list.head;

        while (current != nullptr) {
            Add_Node_End(current->data);
            current = current->next;
        }
    }
    ~list() {
        Del_List();
    }

    void operator=(const list<T>& copy) {
        Del_List();
        Node_List<T>* current = copy.head;

        while (current != nullptr) {
            Add_Node_End(current->data);
            current = current->next;
        }
    }
    void operator+=(const T data) { Add_Node_End(data); }
    list<T> operator+(const T data) {
        Add_Node_End(data);
        return *this;
    }
    friend list<T> operator+(const T data, list<T> list) {
        list.Add_Node_Start(data);
        return list;
    }
    friend std::ostream& operator<<(std::ostream& os, const list<T> list) {
        Node_List<T>* current = list.head;
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

    std::stringstream Return_List_Raw() {
        std::stringstream ss;
        Node_List<T>* current = head;
        bool checker = true;

        while (current != nullptr) {
            ss << current->data << std::endl;
            current = current->next;
            checker = false;
        }

        if (checker) ss << "The list is empty" << std::endl;

        return ss;
    }

    size_t size() { return count; }

    void print_alt() {
        Node_List<T>* current = head;
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
    void print() {
        Node_List<T>* current = head;
        bool checker = true;

        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
            checker = false;
        }

        if (checker) std::cout << "The list is empty" << std::endl;
    }
    void Add_Node_End(T data) {
        Node_List<T>* temp = new Node_List<T>;
        temp->data = data;
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        count++;
    }
    void Add_Node_Start(T data) {
        Node_List<T>* temp;
        temp = new Node_List<T>;

        temp->data = data;
        temp->next = head;

        head = temp;
        count++;
    }
    void Add_Node_Position(T data, size_t position) {
        Node_List<T>* previous = new Node_List<T>;
        Node_List<T>* current = new Node_List<T>;
        Node_List<T>* temp = new Node_List<T>;

        current = head;

        for (size_t i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }

        temp->data = data;
        previous->next = temp;
        temp->next = current;
        count++;
    }
    void Del_Node_End() {
        if (head->next == nullptr) {
            head = nullptr;
            delete head;
            return;
        } else {
            Node_List<T>* current = head;

            while (current->next->next != nullptr) current = current->next;

            delete current->next;

            current->next = nullptr;
        }
    }
    void Del_Node_Start() {
        Node_List<T>* next_node = nullptr;

        next_node = head->next;

        delete head;

        head = next_node;
    }
    void Del_Node_Position(size_t position) {
        Node_List<T>* current = head;
        Node_List<T>* temp_node = nullptr;

        if (position == 1) {
            list<T>::Del_Node_Start();
            return;
        }

        for (size_t i = 1; i < position - 1; i++) {
            if (current->next == nullptr) {
                list<T>::Del_Node_End();
                return;
            }
            current = current->next;
        }

        temp_node = current->next;
        current->next = temp_node->next;

        delete temp_node;
    }
    void Edit_Data(T data, size_t position) {
        Node_List<T>* current = head;

        for (size_t i = 1; i < position; i++) current = current->next;

        current->data = data;
    }
    void Del_List() {
        Node_List<T>* current = head;
        Node_List<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }
    void Copy_List(list<T>& copy) {
        Node_List<T>* current = head;

        while (current != nullptr) {
            copy.Add_Node_End(current->data);
            current = current->next;
        }
    }
};