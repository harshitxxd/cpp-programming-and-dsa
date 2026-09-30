/*
 * File: fibonacci_number.cpp
 * Topic: Recursion
 * Description: Computes the nth Fibonacci number recursively.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;

    cout << "Example 1 -> " << sol.fib(2) << '\n';
    cout << "Example 2 -> " << sol.fib(3) << '\n';
    cout << "Example 3 -> " << sol.fib(4) << '\n';

    return 0;
}