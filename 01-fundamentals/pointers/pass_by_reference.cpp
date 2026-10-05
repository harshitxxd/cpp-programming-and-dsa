/*
 * File: pass_by_reference.cpp
 * Description: This program demonstrates passing variables by reference so changes inside a function affect the original values.
 *
 */

#include<iostream>
using namespace std;

// Time Complexity: O(n)
void changea(int value){ 
    value = 10;
}

void change(int* pointer ){ 
    *pointer = 15;
}

void changeA(int &reference){ 
    reference = 20;
}

int main(){
    int value = 5;
    int pointer = 10;
    int reference = 15;

    cout << value << endl;
    cout << pointer << endl;
    cout << reference << endl;

    changea(value);
    change(&pointer);
    changeA(reference);

    cout << value << endl;
    cout << pointer << endl;
    cout << reference << endl;

    return 0;
}