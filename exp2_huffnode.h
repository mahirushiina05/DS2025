#pragma once
#ifndef HUFFNODE_H
#define HUFFNODE_H

struct HuffNode {
    char ch;
    int weight;
    HuffNode* left;
    HuffNode* right;

    HuffNode(char c, int w)
        : ch(c), weight(w), left(nullptr), right(nullptr) {
    }
};

#endif
