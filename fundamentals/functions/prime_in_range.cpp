/*
 * File: prime_in_range.cpp
 * Description: This program lists all prime numbers within a given range.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n * sqrt n)
void prime() {
    int start, end;
    cout << "enter the start value";
    cin >> start;
    cout << "enter the end value";
    cin >> end;

    for (int i = start; i <= end; i++) {
        bool isprime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isprime = false;
            }
        }
        if (isprime == true) {
            cout << "is prime " << i << '\n';
        } else {
            cout << "not prime " << i << '\n';
        }
    }
}

int main() {
    prime();
    return 0;
}
