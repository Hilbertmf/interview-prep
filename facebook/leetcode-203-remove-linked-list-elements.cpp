// solved (AC)
// https://leetcode.com/problems/remove-linked-list-elements/submissions/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    // edge cases
    while(head != nullptr && head->val == val) {
      head = head->next;
    }
    
    ListNode* prev = new ListNode();
    ListNode* curr = head;
    prev->next = curr;
    while(curr != nullptr) {
      if(curr->val == val) {
        prev->next = curr->next;
        curr = prev;
      }
      else {
        prev = prev->next;  
      }
      curr = curr->next;
    }
    
    return head;
  }
};
/*
val = 7
-7-7-7-null
 |
curr=7
prev=null
time: O(n), n = list.length
space: O(1)
*/