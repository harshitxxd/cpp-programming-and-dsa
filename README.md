# C++ Programming and DSA Practice

A collection of C++ examples and problem solutions organized as a learning path: fundamentals, data structures, algorithms, and problem-solving practice.

## Repository structure

```text
01-fundamentals/
  basics/
  binary-and-bitwise/
  functions/
  math/
  oop/
  patterns/
  pointers/
  recursion/
02-data-structures/
  arrays-and-vectors/
  linked-lists/
  stacks-and-queues/
  standard-library/
    algorithms/
    containers/
  strings/
03-algorithms/
  recursion-and-backtracking/
  searching/
  sorting/
04-problem-solving/
  leetcode/
    arrays/
    math/
    recursion/
```

Use the numbered top-level directories to follow the learning path. Keep general
practice examples in the fundamentals, data-structures, or algorithms sections;
keep platform-specific challenge solutions under `04-problem-solving/leetcode/`
and organize them by topic.

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
