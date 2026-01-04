#include "memory_manager.h"
#include "cache.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define GREEN "\033[32m"
#define RED   "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


int main(){
    MemoryManager mem;
    mem.init_memory(1024);
    Cache l1(4);
    Cache l2(8);
    
    cout<<"Memory Simulator\n";
    cout<<"Commands:\n";
    cout<<"init memory <size>\n";
    cout<<"malloc <size>\n";
    cout<<"free <id>\n";
    cout<<"dump memory\n";
    cout<<"stats\n";
    cout<<"set allocator first_fit|best_fit|worst_fit\n";
    cout<<"access <address>\n";
    cout<<"cache_stats\n";
    cout<<"help\n";
    cout<<"exit\n";

    string line;
    
    while(true){
        cout<< YELLOW <<"memsim> " << RESET;
        getline(cin,line);

        stringstream ss(line);
        string cmd;
        ss>>cmd;

        if(cmd=="init"){
            string what;
            size_t size;
            ss>>what>>size;

            if(what=="memory"){
                mem.init_memory(size);
                cout<<"Memory initialized with size "<<size<<"\n";
            }else{
                cout<< "Invalid init command. Use: init memory <size>\n";
            }
            continue;
        }
        if(cmd=="malloc"){
            size_t size;
            ss>>size;
            int id= mem.malloc_block(size);
            if(id!=1)
                cout<<GREEN;
            cout<<RESET;
        }
        else if(cmd=="free"){
            int id;
            ss>>id;
            mem.free_block(id);
        }
        else if(cmd=="dump"){
            string what;
            ss>>what;

            if(what=="memory" || what==""){
                mem.dump_memory();
            }else{
                cout<<"unknown dump target\n";
            }
        }
        else if(cmd=="stats"){
            mem.print_stats();
        }
        else if(cmd=="exit"){
            break;
        }
        else if(cmd=="access"){
            int addr;
            ss>>addr;

            if(!l1.access(addr)){
                cout<<"accessing L2\n";
                l2.access(addr);
            }
        }
        else if(cmd=="cache_stats"){
            cout<<"\nL1";
            l1.print_stats();
            cout<<"\nL2";
            l2.print_stats();
        }
        else if(cmd=="set"){
            string what, val;
            ss>>what>>val;

            if(what=="allocator"){
                if(val=="first_fit") mem.set_allocator(FIRST_FIT);
                else if(val=="best_fit") mem.set_allocator(BEST_FIT);
                else if(val=="worst_fit") mem.set_allocator(WORST_FIT);
                else{
                    cout << RED << "Invalid allocator. Use: first_fit | best_fit | worst_fit\n" << RESET;
                    continue;
                }
                cout<<"Allocator set to "<<val<<"\n";
            }
        }
        else if(cmd=="help"){
            cout << YELLOW << "Commands:\n" << RESET;
            cout<<"init memory <size>\n";
            cout<<"malloc <size>\n";
            cout<<"free <id>\n";
            cout<<"dump memory\n";
            cout<<"stats\n";
            cout<<"set allocator first_fit|best_fit|worst_fit\n";
            cout<<"access <address>\n";
            cout<<"cache_stats\n";
            cout<<"exit\n";
        }
        else{
            cout<< RED <<"unknown command\n"<< RESET;
        }
    }

    return 0;
}