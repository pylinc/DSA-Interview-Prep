/*
Problem: Sort 0s 1s 2s without using sorting algorithm
Platform: GFG
Difficulty: Medium

Approach:
1. Sort the array
    -Disadvantage: Time complexity will we O(n log n)
2. Count the number of 0s 1s and 2s and place them in the array
    - Disadvantage: Time complexity will be O(2*n)
3. Use Dutch national flag alogrithm:
    - Take three pointers low, mid and high
    - If arr[mid] == 0, swap arr[low] and arr[mid], increment low and mid
    - If arr[mid] == 1, increment mid   
    - If arr[mid] == 2, swap arr[mid] and arr[high], decrement high

    - Advantage: It will Solve the answer in One Pass

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// approach 1
void sort012(vector<int>& arr){
    sort(arr.begin(),arr.end());
}
/*
TC --> O(n log n)
SC --> O(i)
*/

// Approach 2
void sort210(vector<int>& arr){
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;

    for(int i = 0;i<arr.size();i++){
        if(arr[i]==0){
            c0++;
        }
        else if(arr[i]==1){
            c1++;
        }
        else{
            c2++;
        }
    }

    int idx=0;

    for(int i=0;i<c0;i++){
        arr[idx++] = 0;
    }
    for(int i =0;i<c1;i++){
        arr[idx++] = 1;
    }
    for(int i=0;i<c2;i++){
        arr[idx++] = 2;
    }

}
/*
TC --> O(n)
SC --> O(1)
*/

// Approach 3  Dutch National Flag(One pass algorithm)

void sort012s(vector<int>&arr){
    int n = arr.size();

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<= high){
        if(arr[mid]==0){
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);
        }
    }
}
/*
TC --> O(n)
SC --> O(1)
*/
int main() {

    vector<int> arr = {0,1,2,0,1,2};

    sort012s(arr);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
