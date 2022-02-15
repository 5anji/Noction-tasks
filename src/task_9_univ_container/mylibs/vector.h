#pragma once
#include "container.h"

#include <stddef.h>
template <typename T>
class vector : virtual public container<T> {
private:
    T* vec_T = nullptr;
    size_t cap;
    size_t elem_num;
    const int alloc = 20;

public:
    vector() {
        cap = alloc;
        vec_T = (T*)malloc(sizeof(T) * alloc);
        elem_num = 0;
    };

    void push_back(const T& data) {
        if (elem_num < cap) {
            *(vec_T + elem_num) = data;
            elem_num++;
        } else {
            vec_T = static_cast<T*>(realloc(vec_T, sizeof(T) * cap * 2));
            cap *= 2;

            if (vec_T) {
                *(vec_T + elem_num) = data;
                elem_num++;
            }
        }
    }
    void pop_back() {
        if (empty())
            return;
        elem_num--;
    }

    bool empty() {
        return elem_num == 0;
    }
    size_t size() {
        return elem_num;
    }
    size_t capacity() {
        return cap;
    }
    T& operator[](size_t pos) {
        if (pos >= 0 && pos <= elem_num)
            return *(this->vec_T + pos);
        throw std::out_of_range("Out of bounds element access");
    }
    void print() {
        for (size_t i = 0; i < this->size(); i++) {
            std::cout << (*this)[i] << std::endl;
        }
    }
    ~vector() {
        free(vec_T);
    }
};