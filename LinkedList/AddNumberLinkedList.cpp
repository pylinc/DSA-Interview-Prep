/*
Problem: Add Two Lined Lists Representing Numbers
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. Take two pointer res and curr to store the result linked list and the current node respectively. Also maintain a carry variable to store the carry while adding two digits.
2. Trim leading zeros from both linked lists and reverse them to facilitate addition from least significant digit.
3. Traverse both linked list until both are NULL and carry is 0.
    - For each iteration, calculate the sum of corresponding digits from both linked lists and the carry.
    - Create a new node with the digit value of sum%10 and update carry as sum/10.
    - Append the new node to the result linked list.
    - If newNode is the first node, initialize res and curr with it. Otherwise, link it to curr->next and move curr to curr->next.
4. Finally, reverse the result linked list to restore the original order and return it.

Time Complexity: O(max(N, M)) where N and M are the lengths of the two linked lists.
Space Complexity: O(1) (excluding the space for the output linked list).
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* reverse(Node* head){
        Node*prev = NULL, *curr = head,*next;
        
        while(curr!=NULL){
            next= curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
        }
        
        return prev;
    }
    Node* trimLeadingZero(Node* head){
        while(head->next && head->data==0){
            head= head->next;
        }
        return head;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node* res = NULL, *curr = NULL;
        int carry =0;
        
        head1 = trimLeadingZero(head1);
        head2 = trimLeadingZero(head2);
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        while(head1 || head2 || carry!=0){
            int sum =carry;
            
            if(head1!=NULL){
                sum+=head1->data;
                head1= head1->next;
            }
            if(head2!=NULL){
                sum+=head2->data;
                head2=head2->next;
            }
            
            
            Node *newNode = new Node(sum%10);
            
            carry = sum/10;
            if(res == NULL){
                res = newNode;
                curr = newNode;
            }
            else{
                curr->next = newNode;
                curr = curr->next;
            }
            
        }
        
        return reverse(res);
    }
};
