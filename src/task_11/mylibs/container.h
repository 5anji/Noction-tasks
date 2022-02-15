#pragma once
template <typename T>
struct container {
    virtual void print() = 0;
    virtual size_t size() = 0;
};