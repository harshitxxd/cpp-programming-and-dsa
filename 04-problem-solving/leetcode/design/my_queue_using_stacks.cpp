/*
 * File: my_queue_using_stacks.cpp
 * Description: Implements a FIFO queue using two stacks.
 */

 #include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() = default;

    // Time Complexity: O(n)
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Time Complexity: O(1)
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    // Time Complexity: O(1)
    int peek() {
        return s1.top();
    }

    // Time Complexity: O(1)
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);

    cout << myQueue.peek() << '\n';
    cout << myQueue.pop() << '\n';
    cout << (myQueue.empty() ? "true" : "false") << '\n';
    return 0;
}
