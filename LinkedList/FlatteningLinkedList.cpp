/*
Problem: Flattening Linked List
Platform: GeeksforGeeks
Difficulty: Medium

Approach:
1. Check if root is NULL or root->next is NULL, if so return root.
2. Recursively flatten the next linked list.
3. Merge the current linked list with the flattened next linked list using a merge function.


Time Complexity: O(N*M) where N is the number of linked lists and M is the average number of nodes in each linked list.
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
class Solution {
  public:
    Node* merge(Node* a, Node*b){
        if(!a) return b;
        if(!b) return a;
        Node *result;
        if(a->data < b->data){
            result = a;
            result->bottom = merge(a->bottom,b);
        }
        else{
            result = b;
            result->bottom = merge(a,b->bottom);
        }
        result->next = NULL;
        return result;
    }
    Node *flatten(Node *root) {
        // code here
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next);
        
        root = merge(root,root->next);
        
        return root;
    }
};


