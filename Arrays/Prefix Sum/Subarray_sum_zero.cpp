/*
Problem:Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 
Platform: Gfg
Difficulty: Medium

Approach:
1. Take a unordered_set/map to keep an track of previous prefixSum
2. take a vairable prefix sum to store the sum.
3. run to loop till the end of the array
    - add the current value to prefix sum
    - if prefix sum is 0 or we have previously seen the sum then return true.
    - insert the prefix sum to set/map
4. if come out of loop return false(no subarray found)

Note: In this question we cannot use sliding window becuase sliding window works only on non-negative integers value.

Time Complexity: O(n)
Space Complexity: O(n) because of set
*/

#include <bits/stdc++.h>
using namespace std;

bool subArrayExistn(vector<int>& ans){
    unordered_set<int> st;

    int prefixSum =0;

    for(int i=0;i<ans.size();i++){
        prefixSum+=ans[i];

        if(prefixSum==0 || st.count(prefixSum)) return true;
        st.insert(prefixSum);
    }

    return false;
}
int main() {

    vector<int> ans = {4,2,-3,1,6};
    cout<<subArrayExistn(ans);
    return 0;
}
