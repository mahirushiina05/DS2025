#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    double mod() const { return sqrt(real * real + imag * imag); }
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }
    bool operator<(const Complex& c) const {
        double m1 = mod(), m2 = c.mod();
        if (m1 != m2) return m1 < m2;
        return real < c.real;
    }
    bool operator>(const Complex& c) const {
        double m1 = mod(), m2 = c.mod();
        if (m1 != m2) return m1 > m2;
        return real > c.real;
    }
    bool operator!=(const Complex& c) const {
        return real != c.real || imag != c.imag;
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? '+' : '-') << abs(c.imag) << 'i';
        return os;
    }
};
