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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(head->next == nullptr) return head;
    ListNode *curr = head;
    ListNode *beforeLeft, *leftNode, *rightNode, *afterRight, *prev, *next;
    int i = 1;
    while(i < left - 1) {
      curr = curr->next;
      i++;
    }
    
    if(left > 1) { // if reversed list is not at the start
      beforeLeft = curr;
      curr = curr->next;
    }
    else {
      beforeLeft = nullptr;
    }
    
    leftNode = curr;
    prev = curr;
    curr = curr->next;
    
    for(i = 0; i < (right - left); i++) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    
    rightNode = prev;
    afterRight = curr;
    if(left > 1 && beforeLeft != nullptr) {
      beforeLeft->next = rightNode;
    }
    else {
      head = rightNode;
    }
    leftNode->next = afterRight;
    
    return head;
  }
};