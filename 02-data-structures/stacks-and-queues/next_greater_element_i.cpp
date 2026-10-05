#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // Time complexity: O(nums1.size() + nums2.size()).
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = static_cast<int>(nums2.size()) - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < static_cast<int>(nums1.size()); i++) {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1a = {4, 1, 2};
    vector<int> nums2a = {1, 3, 4, 2};
    vector<int> answer1 = sol.nextGreaterElement(nums1a, nums2a);

    vector<int> nums1b = {2, 4};
    vector<int> nums2b = {1, 2, 3, 4};
    vector<int> answer2 = sol.nextGreaterElement(nums1b, nums2b);

    cout << "Example 1 -> ";
    for (int value : answer1) {
        cout << value << ' ';
    }
    cout << '\n';

    cout << "Example 2 -> ";
    for (int value : answer2) {
        cout << value << ' ';
    }
    cout << '\n';

    return 0;
}
