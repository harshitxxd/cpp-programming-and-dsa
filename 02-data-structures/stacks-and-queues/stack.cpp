/*
 * File: stack.cpp
 * Description: Demonstrates basic stack operations using the C++ standard
 *              library.
 */

#include<iostream>
#include<stack>
using namespace std;

// Time Complexity: O(1) for push, pop, top, empty; O(n) to process all elements
// Space Complexity: O(n) - stack container holding n elements
int main(){
    stack<int>s ;
    s.push(10);
    s.push(20);
    s.push(30);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}