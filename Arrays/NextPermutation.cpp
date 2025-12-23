/*
Problem: 31. Next Permutation
Platform: Leetcode
Difficulty: Medium

Approach:
1. The approach is to start from the end of the array and find the first decreasing element.
    - Store the index of this element in a variable called idx.
2. If no such element exists, the array is in descending order, so we reverse it to get the smallest permutation.
3. Otherwise, find the smallest element to the right of idx that is greater than nums[idx], swap them.
4. Reverse the subarray starting from idx+1 to the end.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    void nextPermutation(vector<int> &arr){
        int n = arr.size();
        int idx = -1;

        for(int i= n-2;i>=0;i--){
            if(arr[i] < arr[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
        }

        for(int i = n-1;i>=0;i--){
            if(arr[i] > arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }

        reverse(arr.begin()+idx+1,arr.end());
    }
};
int main() {
    return 0;
}
