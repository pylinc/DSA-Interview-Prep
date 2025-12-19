/*
Problem: prefix sum problem
Platform: LeetCode
Difficulty: Easy

Approach:
- Create a prefix sum array of size n + 1 (where n is the number of elements in the nums)
- initialize the first element with 0 because there will be no element in the left.
- compute the prefixSum of ith element since the size of prefixSum is +1 so take nums from[n-1]
- for calculating the sum of the range:
    - take the right sum from +1 index and left sum from left index only
    - return the sum


Time Complexity: O(n)
Space Complexity: O(n+1)
*/


#include<bits/stdc++.h>

using namespace std;

class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n+1);
        prefixSum[0] = 0;
        for(int i =1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
       return prefixSum[right+1] - prefixSum[left];
    }
};

