/*
Problem: Triplet Sum in Array
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. Sort the array to use the two-pointer technique.
2. Iterate through the array, take two variables as pointers (left and right) for the remaining part of the array.
    - If the sum of the triplet is equal to the target, return true.
    - If the sum is less than the target, move the left pointer to the right to increase the sum.
    - If the sum is greater than the target, move the right pointer to the left to decrease the sum.
3. If no such triplet is found, return false after checking all possibilities.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-2;i++){
            int l = i+1,r = n-1;
            while(l<r){
                
                int sum = arr[i] + arr[l] + arr[r];
                if(sum==target) return true;
                else if(sum < target) l++;
                else r--;
            }
        }
        
        return false;
    }
};
