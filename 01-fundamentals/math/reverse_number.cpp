/*
 * File: reverse_number.cpp
 * Description: This program reverses the digits of a number and prints the result.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(log n)
int reverse() {
    int num = 125;
    int revnum = 0;
    while (num > 0) { 
        if(num > INT_MAX/10 || num < INT_MIN/10){
            return 0;
        }
        int rem = num % 10;
        revnum = revnum * 10 + rem;
        num /= 10;
    }
    return revnum;
}

int main() {
    cout << reverse();
    return 0;
}
