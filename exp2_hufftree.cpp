#include "HuffTree.h"
#include <queue>

using namespace std;

map<char, string> HuffCode;

struct Compare {
    bool operator()(HuffNode* a, HuffNode* b) {
        return a->weight > b->weight;
    }
};

HuffNode* buildHuffTree(int freq[]) {
    priority_queue<HuffNode*, vector<HuffNode*>, Compare> pq;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push(new HuffNode('a' + i, freq[i]));
        }
    }

    while (pq.size() > 1) {
        HuffNode* x = pq.top(); pq.pop();
        HuffNode* y = pq.top(); pq.pop();

        HuffNode* parent = new HuffNode('\0', x->weight + y->weight);
        parent->left = x;
        parent->right = y;
        pq.push(parent);
    }
    return pq.top();
}

void generateCode(HuffNode* root, Bitmap& bm, int depth) {
    if (!root) return;

    if (root->ch != '\0') {
        char* s = bm.bits2string(depth);
        HuffCode[root->ch] = s;
        delete[] s;
        return;
    }

    bm.clear(depth);
    generateCode(root->left, bm, depth + 1);

    bm.set(depth);
    generateCode(root->right, bm, depth + 1);
}
