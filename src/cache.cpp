#include "cache.h"
#include <iostream>
#include <algorithm>

using namespace std;

Cache::Cache(int cap) : capacity(cap), hits(0), misses(0) {}

bool Cache::access(int address){
    auto it=find(lines.begin(),lines.end(),address);
    if(it!=lines.end()){
        hits++;
        cout<<"cache HIT for address "<<address<<"\n";
        return true;
    }


    misses++;
    cout<<"cache MISS for address "<<address<<"\n";

    if((int)lines.size()<capacity){
        lines.push_back(address);
        fifo.push(address);
    }else{
        int victim=fifo.front();
        fifo.pop();

        auto vit=find(lines.begin(),lines.end(),victim);
        if(vit!=lines.end()) lines.erase(vit);

        lines.push_back(address);
        fifo.push(address);
    }
    return false;
}

void Cache::print_stats() const {
    int total = hits + misses;
    double hit_ratio = total ? (double)hits / total * 100.0 : 0;

    cout << "\n--- Cache Stats (L1 FIFO) ---\n";
    cout << "Hits: " << hits << "\n";
    cout << "Misses: " << misses << "\n";
    cout << "Hit Ratio: " << hit_ratio << "%\n";
}