/*
 * File: sum_of_digits.cpp
 * Description: This program adds the digits of a number and prints the result.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
int sumofdigit(int num) {
    int digitsum = 0;
    while (num > 0) {
        int lastdigit = num % 10;
        num /= 10;
        digitsum += lastdigit;
    }
    return digitsum;
}

int main() {
    cout << sumofdigit(2365);
    return 0;
}
