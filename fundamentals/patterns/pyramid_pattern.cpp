/*
 * File: pyramid_pattern.cpp
 * Description: This program prints a pyramid pattern using nested loops.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n^2)
int main() {
    int n = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << " ";
        }
        for (int j = 1; j <= i + 1; j++) {
            cout << j;
        }
        for (int j = i; j > 0; j--) {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}
