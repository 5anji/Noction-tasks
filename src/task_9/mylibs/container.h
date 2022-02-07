#pragma once
template <typename T>
struct container {
    virtual void print() {}
    virtual size_t size() { return 0; }
};