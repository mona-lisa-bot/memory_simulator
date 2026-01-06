# 🧠 Memory Management Simulator

A **C++ based simulator** that models how an Operating System manages **physical memory**, **dynamic allocation strategies**, and a **multi-level CPU cache hierarchy**.

---

## 📂 Project Structure

```
MEMORY_SIMULATOR/
│
├── .vscode/
│
├── docs/
│   ├── screenshots/
│   └── Memory Simulator Design.pdf
│
├── include/
│   ├── block.h
│   ├── cache.h
│   └── memory_manager.h
│
├── src/
│   ├── allocator/
│   │   ├── block.cpp
│   │   └── memory_manager.cpp
│   │
│   ├── cache.cpp
│   └── main.cpp
│
├── tests/
│   ├── allocation_workload.txt
│   ├── cache_access_log.txt
│   ├── cache_fifo_eviction.txt
│   ├── expected_results.txt
│   ├── virtual_address_log.txt
│   └── run_tests.ps1
│
├── demo.mp4
├── Makefile
├── memsim.exe
├── README.md
└── .gitattributes
```

---

## ⚙ Build Instructions

### Step 1 — Clone or Download the Repository

```bash
git clone https://github.com/mona-lisa-bot/memory_simulator.git
cd memory_simulator
```

Or download the ZIP and extract it.

---

### Step 2 — Build using Makefile

```bash
make
```

### Step 3 — Run the Simulator

```bash
./memsim        # Linux / Mac
.\memsim        # Windows
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

