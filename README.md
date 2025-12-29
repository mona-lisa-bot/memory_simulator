🧠 Memory Management Simulator

A C++ based simulator that models how an Operating System manages physical memory, dynamic allocation strategies, and a multilevel CPU cache hierarchy.
The project demonstrates core OS concepts such as heap allocation, fragmentation handling, and cache replacement policies.

📂 Project Structure
memory_simulator/
│
├── include/
│   ├── block.h
│   ├── memory_manager.h
│   └── cache.h
│
├── src/
│   ├── main.cpp
│   ├── cache.cpp
│   └── allocator/
│       ├── block.cpp
│       └── memory_manager.cpp
│
├── tests/
│   ├── allocator_tests.txt
│   └── cache_tests.txt
│
└── README.md


⚙ Build Instructions
Requirements

g++ compiler (MinGW / Linux g++ / Mac clang++)

C++17 standard

Compile

From the project root:
'''g++ -std=c++17 -Wall -Iinclude src/main.cpp src/allocator/memory_manager.cpp src/allocator/block.cpp src/cache.cpp -o memsim'''

Run
'''./memsim      # Linux / Mac
memsim.exe    # Windows'''

💻 Supported Commands
Command	Description
malloc <size>	Allocate memory block
free <id>	Free allocated block
dump memory	Show memory layout
stats	Display memory statistics
`set allocator first_fit	best_fit
access <address>	Simulate cache access
cache_stats	Show cache hit/miss stats
exit	Exit simulator

📊 Sample Usage
'''set allocator best_fit
malloc 100
malloc 200
free 1
dump memory
stats
access 10
access 20
access 10
cache_stats
'''

🧩 Implemented Features

Physical memory simulation

First Fit, Best Fit, Worst Fit allocation

Block splitting & coalescing

Internal & external fragmentation metrics

Allocation success rate

L1 + L2 cache with FIFO replacement

Cache hit/miss tracking

CLI based interaction
