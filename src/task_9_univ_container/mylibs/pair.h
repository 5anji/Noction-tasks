#pragma once
template <typename T>
struct pair {
    T first, second;

    pair() {
        first = 0;
        second = 0;
    }
    pair(T x) {
        first = x;
        second = x;
    }
    pair(T x, T y) {
        first = x;
        second = y;
    }
    void swap() {
        T temp = first;
        first = second;
        second = temp;
    }
};
