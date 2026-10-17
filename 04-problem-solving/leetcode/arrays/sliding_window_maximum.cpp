#include <deque>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(k), excluding the returned result.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for (int i = k; i < static_cast<int>(nums.size()); i++) {
            res.push_back(nums[dq.front()]);

            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = solution.maxSlidingWindow(nums, 3);

    for (int value : result) {
        cout << value << ' ';
    }
    cout << '\n';

    vector<int> single = {1};
    result = solution.maxSlidingWindow(single, 1);
    cout << result.front() << '\n';
    return 0;
}
