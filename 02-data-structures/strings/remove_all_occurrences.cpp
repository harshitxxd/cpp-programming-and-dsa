/*
 * File: remove_all_occurrences.cpp
 * Description: Removes all occurrences of a substring from a string.
 */

#include<iostream>
#include<string>
using namespace std;

// Time Complexity: O(n)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};

int main(){
    Solution sol ;
    string s = "daabcbaabcbc", part = "abc";
    cout << sol.removeOccurrences(s,part) << endl;
    return 0;
}