/*
Problem: Find Pivot index in which the sum on the left is equal to the sum on the right
Platform: Leetcode
Difficulty: Easy

Approach:
- Declare two variable the leftSum=0 and totalSum=0.LeftSum will store the sum till particular position and TotalSum will store the sum of the array elements.
- Start the loop from 0 n-1
    -- Decrease the TotalSum by arr[i]
    -- If the leftSum==TotalSum the return the index.
    -- if not then add the current index element to leftSum.
-- If no index found return -1.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& arr) {
        int n= arr.size();
        int totalSum =0;
        for(int i =0;i<n;i++){
            totalSum+=arr[i];
        }
        int leftSum = 0;
        for(int i =0;i<n;i++){
            totalSum-=arr[i];

            if(leftSum == totalSum){
                return i;
            }

            leftSum += arr[i];
        }

        return -1;
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1,7,3,6,5,6};
    cout<<pivotIndex(arr);
    return 0;
}
