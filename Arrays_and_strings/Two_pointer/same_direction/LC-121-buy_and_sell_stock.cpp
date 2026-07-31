// 121. Best Time to Buy and Sell Stock

// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 

// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

//code:
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0; //no profit can be made if there is only one price
        int minn=prices[0];
        int maxx=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>minn){ //if the current price is greater than the minimum price seen so far, we can make a profit
                maxx=max(prices[i]-minn,maxx);
            }
            minn=min(minn,prices[i]); //we update the minimum price seen so far
        }
        return maxx;
    }
};
int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    cout<<"the maximum profit is: "<<sol.maxProfit(prices)<<endl;
    return 0;
}