/*
Problem: Length of Longest Subarray With atmost K frequency
Platform: Leetcode  
Difficulty: Medium

Approach:
1. Take unordered map to store the frequency of elements in the current window.
2. Take Left and right pointer to maintain the window. Move right pointer to include new elements and update their frequency in the map.
3. If the size of the map exceeds K, move the left pointer to reduce the window size and update the frequency of elements accordingly.


Time Complexity: O(n), where n is the number of elements in the array. Each element is processed at most twice (once when added to the window and once when removed).
Space Complexity: O(k), where k is the number of unique elements in the current window. The unordered map stores the frequency of elements in the current window, which can be at most k.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int left = 0;
        int right = 0;
        while(left<=right && right < n){
            freq[nums[right]]++;

            if(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            right++;
        }

        return right - left;
    }
};
