/*
 * File: butterfly_pattern.cpp
 * Description: This program prints a butterfly-shaped pattern using loops.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n^2)
int main() {
    int n = 4;

    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) cout << '*';
        for (int j = n; j > i; j--) cout << ' ';
        for (int j = n; j > i; j--) cout << ' ';
        for (int j = 0; j < i; j++) cout << '*';
        cout << '\n';
    }

    
    for (int i = 0; i <= n; i++) {
        for (int j = n; j > i; j--) cout << '*';
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = n; j > i; j--) cout << '*';
        cout << '\n';
    }

    return 0;
}
