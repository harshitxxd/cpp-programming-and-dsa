/*
 * File: factorial_and_ncr.cpp
 * Description: This program computes factorial values and combinations using the NCR formula.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int nCr(int n, int r) {
    int factn = factorial(n);
    int factr = factorial(r);
    int factnmr = factorial(n - r);
    return factn / (factr * factnmr);
}

int main() {
    int n = 6, r = 3;
    cout << nCr(n, r) << '\n';
    return 0;
}

 