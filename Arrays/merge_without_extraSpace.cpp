/*
Problem: Merge two arrays without using extra space
Platform: GFG
Difficulty: Medium

Approach:
1. Compare the elements from last index of array1 to first index of array 2
    - if(array1[last]<=array2[first]) then break;
    - otherwise swap two values
2. Sort the two arrays to get the result.

Time Complexity: O(nlogn + mlogm)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        int m = brr.size();
        int i = n-1;
        int j =0;

        while(i>=0 && j<m){
            if(arr[i]<=brr[j]){
                break;
            }
            else{
                int temp = arr[i];
                arr[i] = brr[j];
                brr[j] = temp;
            }
            i--;
            j++;
        }

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        
    }
};

int main() {
    vector<int> a = {2,4,7,10};
    vector<int>b = {2,3};

    Solution s;
    s.mergeArrays(a,b);

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<b.size();j++){
        cout<<b[j]<<" ";
    }
    return 0;
}
