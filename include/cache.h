#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include <queue>
using namespace std;

class Cache{
    private:
        int capacity;
        vector<int> lines;
        queue<int> fifo;

        int hits;
        int misses;
    
    public:
        Cache(int cap=8);

        bool access(int address);
        void print_stats() const;
};

#endif