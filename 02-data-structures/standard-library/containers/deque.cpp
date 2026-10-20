/*
 * File: deque.cpp
 * Description: Demonstrates adding, removing, and accessing elements in a
 *              deque.
 */

#include<iostream>
#include<deque>
using namespace std;

// Time Complexity: O(n)
int main(){
    deque<int> d = {1,2,3};
    
    for (int val : d){
        cout << val << endl;
    }
}
