/*
 * File: first_unique_character_in_a_string.cpp
 * Description: Returns the index of the first non-repeating character in a
 *              string.
 */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n) average
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;

            while (!q.empty() && m[s[q.front()]] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};

int main() {
    Solution solution;
    cout << solution.firstUniqChar("leetcode") << '\n';
    cout << solution.firstUniqChar("loveleetcode") << '\n';
    cout << solution.firstUniqChar("aabb") << '\n';
    return 0;
}
