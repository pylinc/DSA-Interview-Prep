/*
Problem: Count Inversions in an Array
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. Use a modified merge sort algorithm to count inversions while sorting the array.
2. During the merge step, count how many elements from the right subarray are less than elements from the left subarray.
3. Sum these counts to get the total number of inversions in the array.


Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int merge(vector<int>& arr,int s,int mid, int e){
        int count =0;
        vector<int> temp;
        int left = s;
        int right = mid+1;
        
        while(left <=mid && right <=e){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                count += (mid - left + 1);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <=e){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(int i =s;i<=e;i++){
            arr[i] = temp[i-s];
        }
        return count;
        
    }
    int mergeSort(vector<int>&arr,int low , int high){
        int count =0;
        if(low>=high) return count;
        
        int mid = low + (high - low)/2;
        
        count+=mergeSort(arr,low,mid);
        count+=mergeSort(arr,mid+1,high);
        
        count += merge(arr,low,mid,high);
        
        return count;
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        int count =0;
        
        return (mergeSort(arr,0,arr.size()-1));
        
    }
};
