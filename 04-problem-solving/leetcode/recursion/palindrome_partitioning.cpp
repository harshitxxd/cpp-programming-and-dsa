/*
 * File: palindrome_partitioning.cpp
 * Description: Returns all partitions of a string in which every substring is
 *              a palindrome.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool ispalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getallparts(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }
        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            string part = s.substr(0, i + 1);

            if (ispalin(part)) {
                partitions.push_back(part);
                getallparts(s.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    // Time complexity: O(n * 2^n) in the worst case, including constructing
    // and copying all palindrome partitions into the result.
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getallparts(s, partitions, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    for (const string input : {"aab", "a"}) {
        vector<vector<string>> partitions = sol.partition(input);
        cout << "Input: " << input << " -> ";
        for (const vector<string>& parts : partitions) {
            cout << "[";
            for (size_t i = 0; i < parts.size(); i++) {
                if (i > 0) {
                    cout << ", ";
                }
                cout << '"' << parts[i] << '"';
            }
            cout << "] ";
        }
        cout << '\n';
    }

    return 0;
}
