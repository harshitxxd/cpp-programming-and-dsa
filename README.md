# C++ Programming and DSA Practice

A collection of C++ examples and problem solutions organized as a learning path: fundamentals, data structures, algorithms, and problem-solving practice.

## Repository structure

```text
01-fundamentals/
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
  trees/
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
    design/
    math/
    recursion/
    strings/
    trees/
```

Use the numbered top-level directories to follow the learning path. Keep general
practice examples in the fundamentals, data-structures, or algorithms sections;
keep platform-specific challenge solutions under `04-problem-solving/leetcode/`
and organize them by topic.

All solution files follow `snake_case.cpp` naming and include header comments
documenting time and space complexity alongside self-contained test cases.

## LeetCode tree solutions

The tree-problem solutions are in `04-problem-solving/leetcode/trees/`:

- `same_tree.cpp` checks whether two binary trees have identical structure and
  node values.
- `subtree_of_another_tree.cpp` checks whether one binary tree is a subtree of
  another.
- `diameter_of_binary_tree.cpp` calculates the diameter (longest path between
  any two nodes) of a binary tree.
- `lowest_common_ancestor_of_a_binary_tree.cpp` finds the lowest common ancestor
  (LCA) of two given nodes in a binary tree.
- `construct_binary_tree_from_preorder_and_inorder_traversal.cpp` reconstructs
  a binary tree from its preorder and inorder traversals.
- `binary_tree_paths.cpp` returns all root-to-leaf paths in a binary tree
  formatted as strings.

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
