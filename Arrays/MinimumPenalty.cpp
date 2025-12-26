/*
Problem: 2483. Minimum Penalty for a Shop
Platform: Leetcode
Difficulty: Medium

Approach:1
1. Iterate through each hour and calculate the penalty for closing at that hour.
    - For each hour, count the 'Y's before that hour and 'N's after that hour to compute the penalty.
    - Keep track of the minimum penalty and the corresponding hour.
2. Also consider the case of closing after the last hour by counting all 'N's in the string.
3. Return the hour that gives the minimum penalty.

Time Complexity: O(n^2) where n is the length of the customers string, due to the nested loops for penalty calculation.
Space Complexity: O(1) as we are using a constant amount of extra space.

#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
    int bestClosingTime(string customers){
        int n = customers.length();
        int minPenalty = INT_MAX;
        int minHour = INT_MAX;

        for(int i=0;i<n;i++){
            int penalty = 0;
            int j = i-1;
            while(j>=0){
                if(customers[j]=='Y'){
                    penalty++;
                }
                j--;
            }
            j = i;
            while(j<n){
                if(customers[j]=='N'){
                    penalty++;
                }
                j++;
            }
            if(penalty<minPenalty){
                minPenalty = penalty;
                minHour = i;
            }
        }

        int lastHourPentalty = count(begin(customers), end(customers), 'N');
        if(lastHourPentalty<minPenalty){
            minPenalty = lastHourPentalty;
            minHour = n;
        }

        return minHour;
    }
};
*/

/*
Approach: 2
1. Use prefix sums to keep track of the number of 'Y's up to each hour and suffix sum to keep track of the number of 'N's from each hour to the end.
2. Calculate the penalty if the shop closes at each hour using the prefix and suffix sums.
3. Return the hour that gives the minimum penalty.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> prefixN(n+1,0);
        prefixN[0] = 0;

        vector<int> suffixY(n+1,0);
        suffixY[n] = 0;

        for(int i =1;i<=n;i++){
            if(customers[i-1]=='N'){
                prefixN[i] = prefixN[i-1] + 1;
            }
            else{
                prefixN[i] = prefixN[i-1];
            }
        }

        for(int i = n-1;i>=0;i--){
            if(customers[i]=='Y'){
                suffixY[i] = suffixY[i+1] + 1;
            }
            else{
                suffixY[i] = suffixY[i+1];
            }
        }
        int minHour = INT_MAX;
        int minPenalty = INT_MAX;
        for(int i=0;i<=n;i++){
            int curr = prefixN[i] + suffixY[i];

            if(curr<minPenalty){
                minPenalty = curr;
                minHour = i;
            }
        }

        return minHour;
    }
};

Approach 3:
1. Initialize the penalty as the total number of 'Y's in the string (if we close at hour 0).
2. Iterate through each hour, updating the penalty:
   - If the current character is 'Y', decrement the penalty (since we are closing after this hour).
   - If the current character is 'N', increment the penalty (since we are closing before this hour).
   - Keep track of the minimum penalty and the corresponding hour.
3. Return the hour that gives the minimum penalty.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        int minHour = 0;

        int penalty = count(begin(customers),end(customers),'Y');

        int minPenalty = penalty;

        for(int i=0;i<n;i++){
            if(customers[i]=='Y'){
                penalty--;
            }
            else{
                penalty++;
            }

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHour = i+1;
            }
        }

        return minHour;
    }
};
*/

