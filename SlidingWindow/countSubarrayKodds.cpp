/*
Problem: Count subarray with exactly k odds.
Platform: GeeksforGeeks
Difficulty: Medium

Approach: 01 (Brute Force - TLE)
1. Take a count ans varible to store the number of subarray with exactly k odds.
2. Iterate Through array where i starts from 0 and j starts from i and take a variable named odd to count the number of odds.
    - If arr[j] is odd increase the odd variable.
    - if odd is equal to k, increase the ans variable.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        int ans =0;
        for(int i=0;i<n;i++){
            int odd = 0;
            
            for(int j = i;j<n;j++){
                if(arr[j]%2!=0) odd++;
                
                if(odd==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};

