/*
Problem: Kth element of two sorted arrays
Platform: GeeksforGeeks
Difficulty: Medium

Approach: 1
1. Take a array to store the merged elements of both arrays.
2. take three pointers i,j and index to keep track of elements in each array.
3. Iterate through both the arrays and compare the elements at i and j.
    - is arr1[i] < arr2[j], push arr1[i] to merged[index] array and increment i and index.
    - else push arr2[j] to merged[index] array and increment j and index.
4. After the loop, if there are any remaining elements in arr1 or arr2, add them to merged array.
5. Finally return merged[k-1] as the kth element.

Time Complexity: O(m + n) where m and n are the sizes of the two arrays.
Space Complexity: O(m + n) for the merged array.
*/

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int kthElement(vector<int>&a, vector<int>&b, int k){
        int n= a.size();
        int m = b.size();
        int size = n+m;
        vector<int> ans(size,-1);
        int idx=0;
        
        int i =0,j =0;
        while(i<n && j<m){
            if(a[i] < b[j]){
                ans[idx++] = a[i++];
            }
            else{
                ans[idx++] = b[j++];
            }
            
        }
        
        while(i<n){
            ans[idx++] = a[i++];
        }
        while(j<m){
            ans[idx++] = b[j++];
        }
        
        return ans[k-1];
    }
};

/* 
Approach: 2
Insted of merging both arrays, we can use two pointers to find the kth element directly.
1. Take two pointers i and j initialized to 0.
2. Iterate both arrays until we reach the kth element.
    - If a[i] < b[j], check if k == 1, if so return a[i], else increment i and decrement k.
    - Else check if k == 1, if so return b[j], else increment j and decrement k.
3. After the loop, if we have exhausted one array, return the kth element from the other array.

Time Complexity: O(n+m)
Space Complexity: O(1)
*/
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n= a.size();
        int m = b.size();
        
        int i =0,j=0;
        
        while(i<n && j<m){
            if(a[i] < b[j]){
                if(k==1){
                    return a[i];
                }
                i++;
                k--;
            }
            else{
                if(k==1){
                    return b[j];
                }
                j++;
                k--;
            }
        
        }
        while(i<n){
            if(k==1){
                return a[i];
            }
            i++;
            k--;
        }
        while(j<m){
            if(k==1){
                return b[j];
            }
            j++;
            k--;
        }
        
    }
};
