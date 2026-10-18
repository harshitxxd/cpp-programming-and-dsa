/*
 * File: array_pointers.cpp
 * Description: This program demonstrates how pointer arithmetic works with arrays.
 *
 * Time Complexity: O(1) - constant-time pointer dereference and print operations.
 * Space Complexity: O(1) - fixed-size array in local stack frame.
 *
 */

#include<iostream>
using namespace std;
int main (){
    int arr[]= {1,2,3,4,5};
    cout << arr << endl;
    cout << *arr << endl;
    return 0;
}