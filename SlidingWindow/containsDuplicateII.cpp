/*
Problem: 219. Contains Duplicate II
Platform: LeetCode
Difficulty: Easy

Approach 1:
1. Use a hash map to store the last index of each element.
2. Iterate through the array and check if the current element has been seen before.
3. If yes, compare the difference in indices with k.
4. If the difference is less than or equal to k, return true.
5. If the index is not found or the difference is greater than k, update the index in the map.
6. If no such pair is found, return false.

Time Complexity: O(n)
Space Complexity: O(n)

Approach 2:
1. Use a sliding window.
2. Maintain a set to store elements in the current window.
3. For each element, check if it already exists in the set.
4. If yes, return true.
5. If no, add the element to the set and remove the leftmost element if the window size exceeds k.
6. If no such pair is found, return false.

Time Complexity: O(n)
Space Complexity: O(k)

Time Complexity:
Space Complexity:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1
    bool containsNearbyDuplicate1(vector<int>& nums,int k){
        unordered_map<int,int> lastIdx;

        for(int i =0;i<nums.size();i++){

            if(lastIdx.count(nums[i]) && i - lastIdx[nums[i]] <= k){
                return true;
            }
            lastIdx[nums[i]] = i;
        }
        return false;
    }

    // Approach 2
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> st;

        for(int i = 0;i<nums.size();i++){
            if(st.count(nums[i])){
                return true;
            }
            st.insert(nums[i]);

            if(st.size() > k){
                st.erase(nums[i-k]);
            }
        }

        return false;
    }
};

