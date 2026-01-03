#ifndef BLOCK_H
#define BLOCK_H

#include <cstddef>

struct Block{
    int id;
    size_t start;
    size_t size;
    size_t requested;
    bool is_free;
    Block* next;

    Block(size_t s,size_t sz)
        :id(-1),start(s),size(sz),requested(0),
        is_free(true),next(nullptr){}
};

#endif