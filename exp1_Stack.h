#pragma once
#include "Vector.h"
template <typename T>
class Stack {
    Vector<T> v;
public:
    void push(const T& e) { v.insert(v.size(), e); }
    T pop() { return v.remove(v.size() - 1); }
    T& top() { return v[v.size() - 1]; }
    bool empty() const { return v.empty(); }
    int size() const { return v.size(); }
};
