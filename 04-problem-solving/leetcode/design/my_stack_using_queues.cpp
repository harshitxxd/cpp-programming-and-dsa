#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() = default;

    // Time Complexity: O(n)
    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Time Complexity: O(1)
    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    // Time Complexity: O(1)
    int top() {
        return q1.front();
    }

    // Time Complexity: O(1)
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);

    cout << myStack.top() << '\n';
    cout << myStack.pop() << '\n';
    cout << (myStack.empty() ? "true" : "false") << '\n';
    return 0;
}
