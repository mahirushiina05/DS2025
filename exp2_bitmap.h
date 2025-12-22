#pragma once
#ifndef BITMAP_H
#define BITMAP_H

#include <cstring>
typedef int Rank;

class Bitmap {
private:
    unsigned char* M;
    Rank N, _sz;

protected:
    void init(Rank n);

public:
    Bitmap(Rank n = 8);
    ~Bitmap();

    void expand(Rank k);
    void set(Rank k);
    void clear(Rank k);
    bool test(Rank k);
    char* bits2string(Rank n);
};

#endif

