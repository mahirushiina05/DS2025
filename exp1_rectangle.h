#pragma once
#include "Vector.h"
#include "Stack.h"
int largestRectangleArea(Vector<int>& heights) {
    Stack<int> s;
    int maxA = 0, i = 0, n = heights.size();
    while (i < n) {
        if (s.empty() || heights[i] >= heights[s.top()])
            s.push(i++);
        else {
            int h = heights[s.pop()];
            int w = s.empty() ? i : i - s.top() - 1;
            maxA = max(maxA, h * w);
        }
    }
    while (!s.empty()) {
        int h = heights[s.pop()];
        int w = s.empty() ? n : n - s.top() - 1;
        maxA = max(maxA, h * w);
    }
    return maxA;
}
