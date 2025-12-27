/*
Problem: Find the Duplicate Number
Platform: Leetcode
Difficulty: Medium

Approach:
- Observe the constraints
    - The array has size n + 1 and contains numbers from 1 to n.
    - Only one number is duplicated, and the array cannot be modified.
    - Extra space should be constant.
    - These constraints rule out sorting and hashing.

- Treat the array as a linked list
    - Consider each index as a node.
    - The value at an index represents the next node to jump to.
    - So from index i, you go to index nums[i].
    - Because all values lie between 1 and n, every jump stays within the array.

- Understand why a cycle must exist
    - There are n + 1 indices but only n possible values to jump to.
    - By the pigeonhole principle, at least two indices will point to the same value.
    - This creates a cycle in the “linked list” representation.
    - The entry point of this cycle is the duplicate number.

Phase 1: Detect the cycle
Use two pointers:
    - Slow pointer moves one step at a time.
    - Fast pointer moves two steps at a time.
    - Advance them until they meet.
    - If they meet, a cycle is confirmed.

Phase 2: Find the entry of the cycle
    - Reset the slow pointer to the starting position.
    - Now move both slow and fast pointers one step at a time.
    - The point where they meet again is the start of the cycle.
    - That value is the duplicate number.

Return the result
Return the value at the meeting point.
This value is the duplicate.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        slow = nums[0];

        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
}
int main() {

    vector<int> ans = {4,1,4,2,3};

    cout<<findDuplicate(ans);
    return 0;
}
