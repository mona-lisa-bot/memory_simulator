#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "block.h"
#include <cstddef>

enum AllocStrategy {FIRST_FIT, BEST_FIT, WORST_FIT};

class MemoryManager {
private:
    size_t total_memory;
    Block* head;
    int next_id;

    AllocStrategy strategy;
    int alloc_attempts;
    int alloc_success;
    size_t internal_frag;


public:
    MemoryManager();
    ~MemoryManager();

    void init_memory(size_t size);
    int malloc_block(size_t size);
    void free_block(int id);
    void dump_memory() const;
    void print_stats() const;
    void set_allocator(AllocStrategy s);
};

#endif
