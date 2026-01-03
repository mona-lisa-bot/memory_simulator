#include "memory_manager.h"
#include <iostream>
#include <iomanip>
using namespace std;

MemoryManager::MemoryManager() {
    head = nullptr;
    total_memory = 0;
    next_id=1;
    strategy=FIRST_FIT;
    alloc_attempts=0;
    alloc_success=0;
    internal_frag=0;
}

MemoryManager::~MemoryManager() {
    Block* curr = head;
    while (curr) {
        Block* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void MemoryManager::init_memory(size_t size) {
    total_memory = size;
    // if old memory exists, then first delete it
    if(head){
        delete head;
    }

    head = new Block(0, size);
}

int MemoryManager::malloc_block(size_t size) {
    alloc_attempts++;

    Block* curr = head;
    Block* chosen=nullptr;

    while(curr){
        if(curr->is_free && curr->size>=size){
            if(!chosen)chosen=curr;
            else if(strategy==BEST_FIT && curr->size<chosen->size) chosen=curr;
            else if(strategy==WORST_FIT && curr->size>chosen->size) chosen=curr;
            
        }
        curr=curr->next;
    }

    if(!chosen){
        cout<<"Allocation failed\n";
        return -1;
    }

    alloc_success++;


    if(chosen->size >size ){
        Block* newBlock=new Block(chosen->start+size, chosen->size-size);
        newBlock->is_free=true;
        newBlock->next=chosen->next;
        chosen->next=newBlock;
    }

    chosen->size=size;
    chosen->requested=size;
    internal_frag+=(chosen->size-chosen->requested);
    chosen->is_free=false;
    chosen->id=next_id++;

    cout<<"Allocated Block id="<<chosen->id
        <<" at address=0x"<<hex<<chosen->start<<dec<<"\n";
    
        return chosen->id;
    
}

void MemoryManager::free_block(int id){
    Block* curr=head;
    Block*prev=nullptr;

    while(curr){
        if(!curr->is_free && curr->id==id){
            
            internal_frag -= (curr->size - curr->requested);
            curr->requested = 0;

            curr->is_free=true;
            curr->id=-1;


            cout<<"Block "<<id<<" freed";
            
            if(curr->next && curr->next->is_free){
                Block* nextBlock = curr->next;
                curr->size += nextBlock->size;
                curr->next = nextBlock->next;
                delete nextBlock;
                cout << " and merged";
            }
            if (prev && prev->is_free) {
                prev->size += curr->size;
                prev->next = curr->next;
                delete curr;
                curr=prev;
                cout << " and merged";
            }

            cout << "\n";
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    cout<<"invalid block id\n";
}

void MemoryManager::dump_memory() const {

    Block* curr = head;

    cout << "\n--- Memory Dump ---\n";

    while (curr) {
        cout << "[0x"
                  << setw(4) << setfill('0') << hex << curr->start
                  << " - 0x"
                  << setw(4) << hex << (curr->start + curr->size - 1)
                  << "] ";

        if (curr->is_free) {
            cout << "FREE";
        } else {
            cout << "USED (id=" << curr->id << ")";
        }

        cout << dec << "\n";
        curr = curr->next;
    }
}

void MemoryManager::set_allocator(AllocStrategy s) {
    strategy = s;
}


void MemoryManager::print_stats() const {
    size_t used_mem = 0;
    size_t free_mem = 0;
    size_t largest_free = 0;

    Block* curr = head;

    while (curr) {
        if (curr->is_free) {
            free_mem += curr->size;
            if (curr->size > largest_free) {
                largest_free = curr->size;
            }
        } else{
                used_mem+=curr->size;
            }
        curr = curr->next;
    }

    double utilization = (double)used_mem / total_memory * 100.0;

    
    double success_rate = alloc_attempts ?
        (double)alloc_success / alloc_attempts * 100.0 : 0;

    double external_frag = 0.0;
    if (free_mem> 0 && free_mem!=largest_free) {
        external_frag =(1.0 - (double)largest_free / free_mem) * 100.0;
    }


   cout << "\n--- Memory Stats ---\n";
   cout << "Total memory: " << total_memory << "\n";
   cout << "Used memory: " << used_mem << "\n";
   cout << "Free memory: " << free_mem << "\n";
   cout << "Memory utilization: " << utilization << "%\n";
   cout << "External fragmentation: " << external_frag << "%\n";
   cout<<"Internal fragmentation:"<<internal_frag<<"\n";
   cout<<"allocation success rate:"<<success_rate<<"%\n";
}

