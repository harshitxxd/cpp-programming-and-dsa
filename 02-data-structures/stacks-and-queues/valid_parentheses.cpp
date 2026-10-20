/*
 * File: valid_parentheses.cpp
 * Description: Checks whether a string of brackets has valid matching and
 *              nesting.
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    // Time complexity: O(n), where n is the length of the input string.
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < static_cast<int>(str.size()); i++) {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    const string examples[] = {"()", "()[]{}", "(]", "([])", "([)]"};

    for (size_t i = 0; i < sizeof(examples) / sizeof(examples[0]); i++) {
        cout << "Example " << i + 1 << " -> "
             << (sol.isValid(examples[i]) ? "true" : "false") << '\n';
    }

    return 0;
}
