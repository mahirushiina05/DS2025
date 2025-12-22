#include <iostream>
#include <cctype>
#include "HuffTree.h"

using namespace std;

string encodeWord(const string& word) {
    string res;
    for (char c : word) {
        if (isalpha(c))
            res += HuffCode[tolower(c)];
    }
    return res;
}

int main() {
    string text =
        "I have a dream that one day this nation will rise up "
        "and live out the true meaning of its creed";

    int freq[26] = { 0 };
    for (char c : text) {
        if (isalpha(c))
            freq[tolower(c) - 'a']++;
    }

    HuffNode* root = buildHuffTree(freq);

    Bitmap bm(64);
    generateCode(root, bm, 0);

    cout << "Huffman 编码表：" << endl;
    for (auto& p : HuffCode) {
        cout << p.first << " : " << p.second << endl;
    }

    cout << endl;
    cout << "dream   -> " << encodeWord("dream") << endl;
    cout << "nation  -> " << encodeWord("nation") << endl;
    cout << "freedom -> " << encodeWord("freedom") << endl;

    return 0;
}
