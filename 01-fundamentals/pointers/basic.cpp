/*
 * File: basic.cpp
 * Description: This program introduces basic pointer usage in C++.
 *
 * Time Complexity: O(1) - constant-time pointer address-of and dereference operations.
 * Space Complexity: O(1) - primitive variables and pointer storage.
 *
 */

#include<iostream>
using namespace std;
int main (){
    int a = 10 ;
    int* b = &a;
    int** c = &b;
    cout << &a<< endl;
    cout << b << endl;
    cout << c << endl;
    cout << *b << endl;
    cout << **c << endl;
    return 0;

}