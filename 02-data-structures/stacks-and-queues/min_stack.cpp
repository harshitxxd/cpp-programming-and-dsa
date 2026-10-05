#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<long long> s;
    long long minval = 0;

public:
    MinStack() = default;

    // Time complexity: O(1).
    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minval = val;
        } else if (val < minval) {
            s.push(2LL * val - minval);
            minval = val;
        } else {
            s.push(val);
        }
    }

    // Time complexity: O(1).
    void pop() {
        if (s.top() < minval) {
            minval = 2 * minval - s.top();
        }
        s.pop();
    }

    // Time complexity: O(1).
    int top() {
        if (s.top() < minval) {
            return static_cast<int>(minval);
        }
        return static_cast<int>(s.top());
    }

    // Time complexity: O(1).
    int getMin() {
        return static_cast<int>(minval);
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "getMin: " << minStack.getMin() << '\n';
    minStack.pop();
    cout << "top: " << minStack.top() << '\n';
    cout << "getMin: " << minStack.getMin() << '\n';

    return 0;
}
