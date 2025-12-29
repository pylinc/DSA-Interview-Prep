/*
Problem: Common Elements in 3 Sorted Arrays
Platform: GeeksforGeeks
Difficulty: Easy

Approach:
1. Take three pointers i, j, k initialized to 0 for the three arrays.
2. Iterate through the arrays while all pointers are within bounds.
   - If the elements at all three pointers are equal, add the element to the result and
     move all pointers forward, skipping duplicates.
    - If not equal, increment the pointer(s) pointing to the smallest element.
3. Return the result array, or [-1] if no common elements are found.

Time Complexity: O(n1 + n2 + n3) - We traverse each array at most once.
Space Complexity: O(1) - We use only a constant amount of extra space for pointers and result storage.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        // Code Here
        int a= arr1.size();
        int b = arr2.size();
        int c= arr3.size();
        
        int i =0,j=0,k=0;
        vector<int> ans;
        while(i<a && j<b && k<c){
            
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
                ans.push_back(arr1[i]);
                int value = arr1[i];
                while(i<a && arr1[i]==value) i++;
                while(j<b && arr2[j]==value) j++;
            }
            else {
                int mini= min({arr1[i],arr2[j],arr3[k]});
                if(arr1[i]==mini) i++;
                if(arr2[j]==mini) j++;
                if(arr3[k]==mini) k++;
            }
            
        }
        
        return ans.size()==0?vector<int>{-1}:ans;
    }
};
