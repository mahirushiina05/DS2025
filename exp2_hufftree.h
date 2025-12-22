#pragma once
#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <map>
#include <string>
#include "HuffNode.h"
#include "Bitmap.h"

HuffNode* buildHuffTree(int freq[]);
void generateCode(HuffNode* root, Bitmap& bm, int depth);

extern std::map<char, std::string> HuffCode;

#endif
