📘 Memory Management Simulator – Design Document

1. Memory Layout & Assumptions

The simulator models physical memory as a single contiguous block of configurable size (default 1024 bytes).
Memory is divided dynamically using a linked list of blocks.

Each block contains:

Start address

Size

Allocation status

Block ID

Requested size (for fragmentation tracking)

Memory unit used: bytes

2. Allocation Strategy Implementations
First Fit

Selects the first free block large enough for the request.

Best Fit

Selects the smallest free block that satisfies the request.

Worst Fit

Selects the largest available free block.

Block Splitting

When a free block is larger than the requested size, it is split into:

Allocated block

Remaining free block

Coalescing

On deallocation, adjacent free blocks are merged to reduce fragmentation.

3. Buddy Allocation System (Not Implemented)

The buddy system was considered but not implemented in this version.

Design plan:

Memory size must be power of 2

Requests rounded to nearest power of 2

Free lists per block size

Buddy address via XOR

Recursive split & merge

4. Cache Hierarchy & Replacement Policy

A two-level cache hierarchy is implemented:

Level	Policy	Capacity
L1	FIFO	Small (default 3 lines)
L2	FIFO	Larger (default 5 lines)
FIFO Replacement

The oldest cache entry is evicted first.

Each cache tracks:

Hits

Misses

Hit Ratio

5. Virtual Memory Model (Not Implemented)

Virtual memory and paging were not implemented in this version.

Future plan:

Page tables per process

Page size & virtual address space

FIFO / LRU page replacement

Page fault handling

6. Address Translation Flow

Current simulator flow:

Logical Address → Cache → Physical Memory


Future extension with VM:

Virtual Address → Page Table → Physical Address → Cache → Memory

7. Metrics & Statistics

The simulator computes:

Internal Fragmentation
Allocated size − Requested size

External Fragmentation

1 − (Largest Free Block / Total Free Memory)


Allocation Success Rate

Memory Utilization

8. Limitations & Simplifications

No buddy allocator

No virtual memory or paging

Cache is logical, not cycle-accurate

No process abstraction