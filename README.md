# C++ Programming and DSA Practice

A collection of C++ solutions and practice programs covering data structures,
algorithms, problem-solving patterns, and object-oriented programming.

## Topics

- **Fundamentals** - Basics, binary number systems, bitwise operations, functions, OOP, patterns, pointers, and recursion
- **Data structures** - Arrays, graphs, linked lists, stacks and queues, standard library containers and algorithms, strings, trees, and vectors
- **Algorithms** - Dynamic programming, recursion, searching, and sorting
- **Problem solving** - Selected LeetCode solutions, organized by topic where applicable

## Repository structure

The repository groups related topics into broader categories. Add new solutions
to the relevant topic directory:

```text
fundamentals/
  basics/
  binary-number-system/
  bitwise/
  functions/
  oop/
  patterns/
  pointers/
  recursion/
data-structures/
  arrays/
  graphs/
  linked-list/
  stacks-and-queues/
  standard-library/
  strings/
  trees/
  vectors/
algorithms/
  dynamic-programming/
  recursion/
  searching/
  sorting-algorithms/
problem-solving/
  leetcode-solutions/
    arrays/
```

## Running a Program

Compile any source file with a C++17-compatible compiler:

```bash
g++ -std=c++17 path/to/program.cpp -o program
./program
```

On Windows with MinGW:

```powershell
g++ -std=c++17 path\to\program.cpp -o program.exe
.\program.exe
```

Compiled executables are excluded from version control through
[`.gitignore`](./.gitignore).
