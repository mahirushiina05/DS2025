#pragma once
#include <string>
#include <cctype>
#include <sstream>
#include "Stack.h"
using namespace std;

int isp(char op) {   
    switch (op) {
    case '#': return 0;
    case '(': return 1;
    case '*': case '/': return 5;
    case '+': case '-': return 3;
    case ')': return 0;
    default:  return -1;
    }
}
int icp(char op) {   
    switch (op) {
    case '#': return 0;
    case '(': return 8;
    case '*': case '/': return 6;
    case '+': case '-': return 4;
    case ')': return 0;
    default:  return -1;
    }
}

double apply(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw "Division by zero";
        return a / b;
    default: throw "Invalid operator";
    }
}
double evaluate(string expr) {
    expr += '#';                        
    Stack<char>  opSt;   opSt.push('#');
    Stack<double> numSt;

    for (size_t i = 0; i < expr.size(); ) {
        char c = expr[i];
        if (isspace(c)) { ++i; continue; }
        if (isdigit(c)) {                   
            double val = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                ++i;
            }
            numSt.push(val);
            continue;
        }
        
        char topOp = opSt.top();
        if (icp(c) > isp(topOp)) {          
            opSt.push(c); ++i;
        }
        else if (icp(c) < isp(topOp)) {    
            opSt.pop();
            double b = numSt.pop(), a = numSt.pop();
            numSt.push(apply(a, b, topOp));
        }
        else {                              
            if (c == ')' && topOp == '(') { opSt.pop(); ++i; }
            else if (c == '#' && topOp == '#') break;
            else throw "Mismatched parentheses";
        }
    }
    if (numSt.size() != 1) throw "Invalid expression";
    return numSt.top();
}
