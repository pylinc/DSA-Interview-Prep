/*
Problem: Maximum Happiness of Selected Children
Platform: Leetcode
Difficulty: Medium

Approach:
1. Sort the array in decending order.
2. Declare a count variable to store the no of times we can select a child and answer variable to store the maximum happiness.
3. Iterate through the sorted array k times and for each iteration:
    - If the current happiness value is greater than 0, then add happiness[i]- count to the answer and increment count.
    - Else add 0 to the answer and increment count.
4. Return the answer.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxHappiness(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        int count = 0;
        long long answer = 0;

        for(int i = 0;i<k;i++){
            if(happiness[i]-count > 0){
                answer += happiness[i]-count;
            }
            count++;
        }

        return answer;
    }
};

int main() {
    return 0;
}
