/*
Problem: 2 Sum
Platform: Leetcode
Difficulty: Easy

Approach:
1. Sort the array and take two pointer left and right at start and end respectively.(Here sorting in neccessary to use two pointers approach becuase if we increase left means sum is increasing and if we decrease right means sum is decreasing)
2. If sum is 0, add the pair to the result and move both pointers.
    - also skip the duplicates from left and right while moving pointers.
3. If sum is less than 0, move left pointer to increase sum.
4. If sum is greater than 0, move right pointer to decrease sum.

Time Complexity: O(n log n) for sorting + O(n) for two pointers = O(n log n)
Space Complexity: O(1) if we don't consider the output array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int left = 0;
        int right = arr.size()-1;
        
        while(left<right){
            int sum = arr[left] + arr[right];
            
            if(sum==0){
                ans.push_back({arr[left], arr[right]});
                
                while(left<right && arr[left]==arr[left+1]){
                    left++;
                }
                while(left < right && arr[right]== arr[right-1]){
                    right--;
                }
                left++;
                right--;
            }
            else if(sum <0){
                left++;
            }
            else{
                right--;
            }
            
        }
        return ans;
        
    }
};

