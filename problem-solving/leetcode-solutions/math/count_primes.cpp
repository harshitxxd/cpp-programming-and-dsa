#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1,true) ;
        int count = 0 ;
        for(int i = 2 ; i < n ; i++){
            if(isprime[i]){
                count ++;
                for( int j = i*i ; j < n ; j= j+i){
                isprime[j] = false;
                }
            }    
        }
        return count ;
    }
};

int main(){
    Solution sol;
    int n = 10;
    cout << sol.countPrimes(n);
    return 0;
}