

#pragma once
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

#define DEFAULT_CAPACITY 3

template <typename T>
class Vector {
protected:
    int _size, _capacity;
    T* _elem;

    void copyFrom(T const* A, int lo, int hi) {
        _elem = new T[_capacity = 2 * (hi - lo)];
        _size = 0;
        while (lo < hi) _elem[_size++] = A[lo++];
    }
    void expand() {
        if (_size < _capacity) return;
        if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
        T* old = _elem;
        _elem = new T[_capacity <<= 1];
        for (int i = 0; i < _size; ++i) _elem[i] = old[i];
        delete[] old;
    }

public:
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
        _elem = new T[_capacity = c];
        _size = 0;
        while (_size < s) _elem[_size++] = v;
    }
    Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }
    ~Vector() { delete[] _elem; }

    int size() const { return _size; }
    bool empty() const { return !_size; }
    T& operator[](int r) const { return _elem[r]; }

    int insert(int r, T const& e) {
        expand();
        for (int i = _size; i > r; --i) _elem[i] = _elem[i - 1];
        _elem[r] = e; ++_size;
        return r;
    }
    T remove(int r) {
        T e = _elem[r];
        for (int i = r; i < _size - 1; ++i) _elem[i] = _elem[i + 1];
        --_size;
        return e;
    }
    int find(T const& e, int lo, int hi) const {
        while ((lo < hi--) && e != _elem[hi]);
        return hi;
    }
    void unsort(int lo, int hi) {
        for (int i = hi - lo; i > 0; --i)
            swap(_elem[lo + i - 1], _elem[lo + rand() % i]);
    }
    int deduplicate() {
        int old = _size, i = 1;
        while (i < _size)
            find(_elem[i], 0, i) < 0 ? ++i : remove(i);
        return old - _size;
    }
    bool bubble(int lo, int hi) {
        bool sorted = true;
        while (++lo < hi)
            if (_elem[lo - 1] > _elem[lo]) {
                sorted = false;
                swap(_elem[lo - 1], _elem[lo]);
            }
        return sorted;
    }
    void bubbleSort(int lo, int hi) {
        while (!bubble(lo, hi--));
    }
    void merge(int lo, int mi, int hi) {
        int lb = mi - lo;
        T* B = new T[lb];
        for (int i = 0; i < lb; ++i) B[i] = _elem[lo + i];
        int i = 0, j = 0, k = lo;
        int lc = hi - mi;
        while (j < lb && k < hi)
            _elem[k++] = (B[j] < _elem[mi] ? B[j++] : _elem[mi++]);
        while (j < lb) _elem[k++] = B[j++];
        delete[] B;
    }
    void mergeSort(int lo, int hi) {
        if (hi - lo < 2) return;
        int mi = (lo + hi) >> 1;
        mergeSort(lo, mi); mergeSort(mi, hi); merge(lo, mi, hi);
    }
    void sort(int lo, int hi) { mergeSort(lo, hi); }

    Vector<T> findModInterval(double m1, double m2) const {
        Vector<T> res;
        for (int i = 0; i < _size; ++i) {
            double mod = _elem[i].mod();
            if (mod >= m1 && mod < m2) res.insert(res.size(), _elem[i]);
        }
        return res;
    }
};
