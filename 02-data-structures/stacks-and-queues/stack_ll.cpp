/*
 * File: stack_ll.cpp
 * Description: Implements a LIFO stack using a linked list.
 */

#include<iostream>
#include<list>
using namespace std;

// Time Complexity: O(1) for push, pop, top, empty
// Space Complexity: O(n) - stores n elements in a doubly linked list
class stack{
    list<int>ll;

    public :
    void push(int val){
        ll.push_front(val);
    }

    void pop(){
        ll.pop_front();
    }

    int top (){
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }
};

int main(){
    stack s;
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