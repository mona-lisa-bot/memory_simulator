# 🧠 Memory Management Simulator

A **C++ based simulator** that models how an Operating System manages physical memory,  
dynamic allocation strategies, and a **multi-level CPU cache hierarchy**.

---

## 📂 Project Structure

```
memory_simulator/
│
├── include/
│   ├── block.h
│   ├── cache.h
│   └── memory_manager.h
│
├── src/
│   ├── main.cpp
│   ├── cache.cpp
│   └── allocator/
│       ├── block.cpp
│       └── memory_manager.cpp
│
├── tests/
│   ├── allocation_workload.txt
│   └── cache_access_log.txt
|   |__ cache_fifo_eviction.txt
|   |__ expected_Results.txt
|   |__ virtual_address_log.txt
|   |__ run_tests.ps1
│
|__
└── README.md
```

---

## ⚙ Build Instructions

### Run

```bash
make
./memsim
```

---

## 💻 Commands

| Command | Description |
|-------|-------------|
| `init memory <size>` | Memory Initialisation|
| `malloc <size>` | Allocate memory |
| `free <id>` | Free block |
| `dump memory` | Print memory |
| `stats` | Show statistics |
| `set allocator first_fit` | First Fit |
| `set allocator best_fit` | Best Fit |
| `set allocator worst_fit` | Worst Fit |
| `access <address>` | Cache access |
| `cache_stats` | Cache statistics |
| `help` | Help |
| `exit` | Exit |

---

## 📊 Sample Usage

```bash
set allocator best_fit
malloc 100
malloc 200
free 1
dump memory
stats
access 10
access 20
access 10
cache_stats
```

---

## 🧩 Features

- Physical memory simulation  
- First / Best / Worst Fit allocation  
- Block splitting & merging  
- Fragmentation tracking  
- L1 + L2 cache with FIFO eviction  
- Cache hit / miss statistics  
- CLI based interaction

