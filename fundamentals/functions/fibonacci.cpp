/*
 * File: fibonacci.cpp
 * Description: This program generates Fibonacci numbers up to a given range.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
void fibonacci() {
    int n, a = 0, b = 1, next;
    cout << "enter the value of n ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    fibonacci();
    return 0;
}
