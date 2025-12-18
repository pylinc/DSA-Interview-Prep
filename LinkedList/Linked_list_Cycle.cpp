/*
Problem: Detect a cycle in LinkedList
Platform: Leetcode
Difficulty: Easy

Approach:
1. Initialize fast and slow pointer from head;
2. run a loop will the fast is null or fast->next is not null(why fast? because fast is going 2 steps in comparison to slow)
    -- Move slow pointer one step
    -- move fast pointer two step
    -- check condition if they are equal
    -- return true cycle detected
3.come out of the loop means there is no cycle return false.

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
    bool hasCycle(ListNode *head) {
        ListNode *temp = head;
        ListNode* slow = temp;
        ListNode* fast = temp;

        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }

        }

        return false;
    }
};


