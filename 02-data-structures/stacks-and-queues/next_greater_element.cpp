/*
 * File: next_greater_element.cpp
 * Description: Finds the next greater value to the right for each array
 *              element using a monotonic stack.
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Time Complexity: O(n) - each element is pushed and popped at most once.
// Space Complexity: O(n) - monotonic stack and result vector.
int main(){
    vector<int>arr = {6, 8, 0, 1, 3};
    stack<int>s;
    vector<int>ans(arr.size(),0);
    for(int i = arr.size()-1; i >= 0 ; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
                ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for (int val : ans){
        cout << val << " ";
    }
    cout << endl;


    return 0;
} 