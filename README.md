# Bankers Algorithm
# Description

This program is an implementation of Bankers algorithm. It determines whether a system is in safe state so that Deadlock can be avoided.
# Features
- Number of processes and resources can be input.
- Values of Allocation, Maximum and Available resources can be input.
- Need Matrix can be calculated.
- Determines if the system is in safe state.
- If safe, prints Safe Sequence.
# Algorithm
Steps followed in this program:
1. Need matrix can be calculated by:
Need = Maximum - Allocation
2. Check if enough resources are available for a process.
3. If resources are sufficient, allow the process to run and free up the allocated resources.
4. Repeat until all processes are complete or no more processes can be executed.
5. Print Safe Sequence or print Un-safe.
# Execution
## 1. Compilation:
```bash
gcc bankers.c -o bankers.exe
```
## 2. Execution:
```bash
.\bankers.exe
```
# Techinques
C Language
GCC Compiler
# Conclusion
With this project we can understand how Bankers algorithm works to determine safe states within a system to avoid deadlocks.