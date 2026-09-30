/*
 * File: pointer_arithmetic.cpp
 * Description: This program demonstrates pointer arithmetic operations on an array.
 *
 */

#include<iostream>
using namespace std;
int main (){
    int a = 10;
    int *b = &a;

    cout << b << endl;
    b++;
    cout << b << endl;

    b-- ;
    cout << b << endl;

    b += 3;
    cout << b << endl;

    b -= 2;
    cout <<  b << endl;

    cout << "array" << endl;
    int arr[] = {1,2,3,4,5};

    cout << arr << endl;
    cout << (arr +1) << endl;
    cout << *arr << endl;
    cout << *(arr+2) << endl;

    int *ptr;
    int *ptr2;

    cout << ptr << endl;
    cout << ptr2 << endl;
    cout << (ptr == ptr2) << endl;
    cout << (ptr < ptr2) << endl;
    cout << (ptr > ptr2) << endl;
    cout << (ptr != ptr2) << endl;

    return 0;
}