/*
Problem: Best Time to Buy and Sell Stock
Platform: Leetcode
Difficulty: Easy

Approach:
1. Take two variables mini and maxi to store minimum price and maximum profit respectively.
2. Iterate through the prices array, updating mini with the minimum price encountered so far.
3. For each price, calculate the potential profit by subtracting mini from the current price and update maxi if this profit is greater than the current maxi.

Time Complexity: O(n) - We traverse the prices array once.
Space Complexity: O(1) - We use only a constant amount of extra space.
*/
#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi =0;

        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            maxi = max(maxi,prices[i]-mini);
        }

        return maxi;
    }

};
