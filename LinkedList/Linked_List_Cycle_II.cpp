/*
Problem: Find the cycle in the linked list if not cycle return null
Platform: Leetcode
Difficulty: Medium

Approach:
- Take fast and slow pointer and initialize to head;
- Start a loop till fast and fast->next is not null
    - Move slow pointer 1 step and fast pointer 2 steps
    - if they meet then find the entry point of the cycle by moving both by one position.
    - return slow
- if they do not meet and come out of the loop return NULL(i.e. there is no cycle)

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast ==slow){
                slow = head;
                while(fast!=slow){
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};


