#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(log n)
class Solution {
public:
    int binary_search(const vector<int>& arr, int target, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                return binary_search(arr, target, mid + 1, end);
            } else {
                return binary_search(arr, target, st, mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, static_cast<int>(nums.size()) - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << "Example 1 -> " << sol.search(nums, 9) << '\n';
    cout << "Example 2 -> " << sol.search(nums, 2) << '\n';

    return 0;
}
