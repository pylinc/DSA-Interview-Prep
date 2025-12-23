/*
Problem: Overlapping Intervals
Platform: Leetcode/Gfg
Difficulty: Medium

Approach:
1. Sort the array with the start time
2. Declare an new array merged this will store the merged intervals if any present.
3. start a loop from start to end
    - we will only push the element in case of empty merged array or the end time of last interval is short that start of current
    - else(the intervals are overlapping) in this case find the max of last pushed inteval end time and current interval end time.
4. return the merged array

Time Complexity: O(nlogn)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<vector<int>> mergeOverlap(vector<vector<int>> arr){
        sort(arr.begin(),arr.end());

        vector<vector<int>> ans;

        for(auto &interval:arr){
            if(ans.empty() || ans.back()[1] < interval[0]){
                arr.push_back(interval);
            }
            else{
                ans.back()[1] = max(ans.back()[1],interval[1]);
            }
        }

        return ans;
    }
};


