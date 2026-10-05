/*
 * File: is_prime.cpp
 * Description: This program checks whether a given number is prime.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(sqrt n)
int prime(int n) {
    bool isPrime = true;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            isPrime = false;
        }
    }
    if (isPrime == true) {
        cout << " is prime \n";
    } else {
        cout << " is not prime\n";
    }
    return 0;
}

int main() {
    prime(11);
    return 0;
}
