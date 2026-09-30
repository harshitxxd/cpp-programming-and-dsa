/*
 * File: stock_buy_and_sell.cpp
 * Description: This program calculates the maximum profit from buying and selling a stock once per day.
 *
 */

#include<iostream>  
#include<vector>
using namespace std;
class solution{
    public :
        int maxProfit(vector<int>& prices){
            int maxprofit = 0;
            int bestbuy = prices[0];
            for (int i = 1; i < prices.size(); i++){
                if (prices[i] > bestbuy){
                   maxprofit = max(maxprofit, prices[i] - bestbuy);
                }
                bestbuy = min(bestbuy, prices[i]);
            }
            return maxprofit;
        }
};
int main(){
    solution sol;
    vector<int> prices1 = {7,1,5,3,6,4};
    vector<int> prices2 = {7,6,4,3,1};
    cout << "Result 1: " << sol.maxProfit(prices1) << endl;
    cout << "Result 2: " << sol.maxProfit(prices2) << endl;
    return 0;
}