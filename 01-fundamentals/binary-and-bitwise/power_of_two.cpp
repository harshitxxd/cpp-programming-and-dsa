/*
 * File: power_of_two.cpp
 * Description: This program checks whether a number is a power of two using bitwise operations.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(1)
void powerof2() {
    int n;
    cout << "enter the number :";
    cin >> n;

    
    
    
    if (n > 0 && (n & (n - 1)) == 0) {
        cout << "is the power of two";
    } else {
        cout << "not the power of two";
    }
}

int main() {
    powerof2();
    return 0;
}
