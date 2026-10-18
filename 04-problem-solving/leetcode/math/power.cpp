/*
 * File: power.cpp
 * Description: This program computes a number raised to a power using exponentiation logic.
 *
 * Time Complexity: O(log n) - binary exponentiation divides exponent by 2 in each iteration.
 * Space Complexity: O(1) - constant auxiliary space.
 *
 */

#include<iostream>
using namespace std;
 class Solution {
public:
    double mypow(double x,int  n){

        long binform = n;
        if (binform < 0){
            binform = -binform;
            x = 1/x;
        }
        double ans = 1;
        while (binform > 0){
            if (binform % 2 == 1){
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }
        return ans; 
    }
 };
int main(){
    Solution sol;
    double x1 = 2.00000;
    int n1 = 10;
    double x2 = 2.10000;
    int n2 = 3;
    double x3 = 2.00000;
    int n3 = -2;
    cout << "Result 1: " << sol.mypow(x1, n1) << endl;
    cout << "Result 2: " << sol.mypow(x2, n2) << endl;
    cout << "Result 3: " << sol.mypow(x3, n3) << endl;
    return 0;
}
