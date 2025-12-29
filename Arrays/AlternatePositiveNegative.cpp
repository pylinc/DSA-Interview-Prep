/* 
Problem: Alternate Positive and Negative Numbers
Platform: GeeksforGeeks
Difficulty: Easy

Approach:
1. Take two separate vectors to store positive and negative numbers.
2. Take three pointers, one for traversing the original array and two for traversing the positive and negative arrays.
3. Fill the original array by alternating between positive and negative numbers until all elements are placed.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> positive;
        vector<int> negative;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                positive.push_back(arr[i]);
            }
            else{
                negative.push_back(arr[i]);
            }
        }
        int i =0,j=0,k=0;
        
        while(i<arr.size()){
            if(j<positive.size()){
                arr[i++] = positive[j++];
            }
            if(k<negative.size()){
                arr[i++] = negative[k++];
            }
        }
    }
};

