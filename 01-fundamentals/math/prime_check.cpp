/*
 * File: prime_check.cpp
 * Description: This program checks whether a number is prime or not.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(sqrt n)
int main() {
    int n = 21;
    bool isPrime = true;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }

    if (isPrime == true) {
        cout << n << " is prime \n";
    } else {
        cout << n << " is not prime\n";
    }

    return 0;
}
