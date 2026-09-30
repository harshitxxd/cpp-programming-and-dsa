/*
 * File: basic_operators.cpp
 * Description: This program demonstrates common bitwise and arithmetic operations in C++.
 *
 */

#include <iostream>
using namespace std;

// Time Complexity: O(n)
int main() {
    int a = 6, b = 10;

    cout << "a | b = " << (a | b) << "\n";   
    cout << "a & b = " << (a & b) << "\n";   
    cout << "a ^ b = " << (a ^ b) << "\n";   
    cout << "a << 1 = " << (a << 1) << "\n"; 
    cout << "a >> 1 = " << (a >> 1) << "\n"; 

    return 0;
}
