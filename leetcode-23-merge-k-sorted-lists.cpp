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
// time: O(num of items * log(num of lists)) or O(nlogk)
// space: O(num of items)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // val, listNode
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        
        for(auto& listNode : lists) {
            if(listNode != nullptr) 
                minHeap.push(make_pair(listNode->val, listNode));
        }
        
        ListNode* mergedList, *curr;
        if(!minHeap.empty()) {
            mergedList = new ListNode();
            curr = mergedList;
        }
        int count = 0;
        while(!minHeap.empty()) {
            if(count != 0) {
                ListNode* tmp = new ListNode();
                curr->next = tmp;
                curr = curr->next;
            }
                
            auto p = minHeap.top();
            minHeap.pop();
            curr->val = p.first;
            if(p.second->next != nullptr) {
                p = make_pair(p.second->next->val, p.second->next);
                minHeap.push(p);
            }
            count++;
        }
        
        return mergedList;
    }
};