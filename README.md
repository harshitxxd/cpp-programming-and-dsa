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
- `lowest_common_ancestor_of_a_bst.cpp` finds the lowest common ancestor of two
  nodes in a binary search tree using its ordering property.
- `construct_binary_tree_from_preorder_and_inorder_traversal.cpp` reconstructs
  a binary tree from its preorder and inorder traversals.
- `binary_tree_paths.cpp` returns all root-to-leaf paths in a binary tree
  formatted as strings.
- `maximum_width_of_binary_tree.cpp` finds the maximum level width, including
  gaps between non-null nodes.
- `binary_tree_inorder_traversal.cpp` returns node values in inorder using
  iterative Morris traversal with O(1) auxiliary space.
- `flatten_binary_tree_to_linked_list.cpp` flattens a binary tree in place into
  a preorder linked list using reverse-preorder recursion.
- `convert_sorted_array_to_binary_search_tree.cpp` builds a height-balanced
  binary search tree from a sorted array.
- `validate_binary_search_tree.cpp` verifies that every node satisfies the
  strict ordering bounds of a binary search tree.
- `minimum_difference_between_bst_nodes.cpp` finds the minimum difference
  between any two node values in a binary search tree.
- `binary_search_tree_iterator.cpp` iterates through a BST in inorder using
  O(h) stack space and amortized O(1) time per `next()` call.
- `kth_smallest_element_in_a_bst.cpp` finds the kth smallest value using
  recursive inorder traversal.
- `construct_binary_search_tree_from_preorder_traversal.cpp` constructs a
  binary search tree from its preorder traversal using recursive bounds.
- `recover_binary_search_tree.cpp` restores two swapped BST node values using
  recursive inorder traversal.
- `populating_next_right_pointers_in_each_node.cpp` connects each node to its
  next right node in a perfect binary tree using constant auxiliary space.

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
