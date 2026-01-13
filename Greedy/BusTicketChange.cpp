/*
Problem: Bus Ticket Change
Platform: GeeksforGeeks
Difficulty: Easy

Approach:
1. Take two variable to count the no of five and no of ten coins.
2. Iterate through the array:
    - if the current value is 5 increase the count of 5coins.
    - if currnet element is 10 check if the count of 5coins is greater than 0
        - if yes then decrease the count of 5coins and increase the count of 10coins.
        - if no return false.
    - if current element is 10 check the count of 10coins and five coins
        - if the 10coins and 5 coints is greater than 0 then decrease the count of 10coins and 5coins.
        - if the count of 5coins is greater than or equal to 3 than decrease the count of 5coins by 3.
        - if no return false.
3.In the all the operations are performed successfull than return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int n = arr.size();
        int fiveCount =0;
        int tenCount =0;
        for(int i =0;i<n;i++){
            if(arr[i]==5) fiveCount++;
            else if(arr[i]==10){
                if(fiveCount >0){
                    fiveCount--;
                    tenCount++;
                }
                else{
                    return false;
                }
            }
            else if(arr[i]==20){
                if(tenCount >=1 && fiveCount >=1) {
                    tenCount--;
                    fiveCount--;
                }
                else if(fiveCount>=3){
                    fiveCount-=3;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
