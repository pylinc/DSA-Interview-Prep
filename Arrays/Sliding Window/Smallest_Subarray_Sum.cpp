/*
Problem:Smallest Subarray with sum greater than x
Platform: GFG
Difficulty: Easy

Approach:
1. Declare four variable sum=0(Stores the sum),ans=INT_MAX(stores the length),i=0,j=0
2. start the loop till j reaches end:
    - add the values of array till the sum > x
    - check the condition if j has reached end and sum is still less than x than break the loop(means that no subarray > x is present in the array)
    - start another loop till i<j and arr[i]-sum > x:
        - remove arr[i] from the sum.
        - increase the value of i.
    - Take ans from the min of ans and j-i.
    - decrement the arr[i] from the sum.
    - increase the index.
3. check if the answer is still INT_Max if yes than return 0(means no subarray is present) else return ans.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int SmallestSubWithSum(vector<int>&arr,int x){
    int ans = INT_MAX;
    int sum =0,i=0,j=0;

    while(j<arr.size()){

        while(j<arr.size() && sum<=x){
            sum+=arr[j++];
        }
        if(j==arr.size() && sum <=x) break;

        while(i<j && sum-arr[i] > x){
            sum-=arr[i];
            i++;
        }
        ans = min(ans,j-i);

        sum-=arr[i];
        i++;
    }

    return ans==INT_MAX?0:ans;
}


int main() {

    // vector<int> arr  = {1,4,45,6,0,19};
    vector<int> arr  = {1,10,5,2,7};

    cout<<SmallestSubWithSum(arr,51);
    return 0;
}
