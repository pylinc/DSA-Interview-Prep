/*
Problem: Maximum Average Subarray I
Platform: Leetcode
Difficulty: Easy

Approach:
1. Take a variable sum and maxsum, initialize maxSum with nums[0](in case of size==1)
2. take a loop till k and store the sum in sum
3. initialize the maxSum to sum;
4. Take a loop from k to nums size():
    - add the current sum and remove the first sum(Sliding window)
    - check if the current sum is greater than maxSum if yes then update maxSum.
5. return maxSum/k as double.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

double maxAvg(vector<int>& nums,int k){
    int n = nums.size();
    int sum =0;
    int maxSum = nums[0];

    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    maxSum = sum;

    for(int i =k;i<n;i++){
        sum+=nums[i] - nums[i-k];
        maxSum = max(sum,maxSum);
    }

    return (double) maxSum/k;
}

