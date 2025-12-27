/*
Problem: Kth Smallest Element in a Sorted Matrix
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. We can use binary search on the value range of the matrix elements.
2. Declare low and high pointers to the smallest and largest elements in the matrix.
3. While low is less than or equal to high, calculate the mid value and count how many elements are less than or equal to mid using a helper function.
4. If the count is less than k, this means the kth smallest element is larger than mid, so we move the low pointer up. Otherwise, we move the high pointer down and update the answer.

Helper Function:
- The helper function `countSmallerEqual` counts how many elements in the matrix are less than or equal to a given target value.
- It uses a two-pointer technique starting from the top-right corner of the matrix and traverses downwards or leftwards based on the comparison with the target.


Time Complexity: O(n log(max - min)), where n is the number of rows (or columns) in the matrix, and max and min are the maximum and minimum elements in the matrix.
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int countSmallerEqual(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int count = 0;
        int row = 0;
        int col = n-1;
        
        while(row < n && col >=0){
            if(mat[row][col] <= target){
                count += col +1;
                row++;
            }
            else{
                col--;
            }
        }
        
        return count;
    }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            
            int count = countSmallerEqual(mat,mid);
            
            if(count < k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid -1;
            }
        }
        
        return ans;
    }
};

