/*
 * File: container_with_most_water.cpp
 * Description: This program calculates the maximum area of water a container can hold between two vertical lines.
 *
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater= 0;
        int lp = 0;
        int rp = height.size() -1;
        while (lp < rp){
            int w = rp -lp;
            int ht = min(height[lp],height[rp]);
            int curwater = w * ht;
            maxwater = max(maxwater,curwater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
     
        return maxwater;
    }
   
};
int main(){
    Solution sol;
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};
    
    cout << "Result 1: " << sol.maxArea(height1) << endl;
    cout << "Result 2: " << sol.maxArea(height2) << endl;
    return 0;
}