#pragma once
#ifndef BINTREE_H
#define BINTREE_H

template <typename T>
struct BinNode {
    T data;
    BinNode* left;
    BinNode* right;

    BinNode(T d) : data(d), left(nullptr), right(nullptr) {}
};

#endif
