/*
Problem: Maximum Subarray Sum
Platform: LeetCode
Difficulty: Medium

Approach:
- Maintain running sum
- Reset when sum < 0
- Track maximum sum

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int curr = 0, ans = INT_MIN;
    for(int x : nums) {
        curr += x;
        ans = max(ans, curr);
        if(curr < 0) curr = 0;
    }
    return ans;
}
