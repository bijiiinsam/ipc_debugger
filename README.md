# IPC Debugger

This project is an Inter-Process Communication (IPC) Debugger built for an Operating Systems course. It simulates process communication, shared memory access, and message queue activity, then analyzes the generated logs to detect common synchronization issues such as deadlocks and bottlenecks.

---

## 🔧 Features

### ✔ Simulation of IPC Events
The simulator generates realistic process events:
- Resource locking and waiting (P1, P2)
- Message queue sends (P3)
- Shared memory read/write events (P4)

### ✔ Log-Based Analysis
The analyzer reads `trace.log` and checks for:
- **Deadlock**: P1 waiting on B *and* P2 waiting on A  
- **Queue Bottleneck**: More than 5 queued messages

### ✔ Menu-Driven UI
A simple terminal menu allows:
1. Running the simulation  
2. Analyzing the log  
3. Exiting the program  

---

## 📁 Project Structure

main.c – Program entry point and UI loader

ui.c – Menu interface logic

simulator.c – Generates IPC events

analyzer.c – Reads log file and detects issues

logger.c – Writes timestamped events to trace.log

*.h files – Header files used for modular design

CMakeLists.txt – Build configuration for CLion/CMake



---

## 🧪 How to Run

### 1. Clone the repository:

### 2. Open the project in CLion **or build with CMake**:

### 3. Run the program:

---

## 🔄 Git Workflow (For Assignment Requirements)

This project follows a proper Git workflow:

- Created feature branches:
  - `feature/simulator`
  - `feature/analyzer`
  - `feature/logger`
  - `feature/ui`

- Each branch contained meaningful changes  
- Each change was committed with clear messages  
- Pull Requests were opened and merged back into the `main` branch  
- Total commits: **8+**, exceeding the required 7 revisions  

This demonstrates professional version control practices.

---

## 📄 License
This project is licensed under the **MIT License**.

---





