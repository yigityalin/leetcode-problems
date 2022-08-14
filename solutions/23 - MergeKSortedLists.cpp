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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minindex = -1, minval = INT_MAX; 
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] && lists[i]->val < minval) {
                minindex = i;
                minval = lists[i]->val;
            }
        }
        if (minindex == -1) {
            return nullptr;
        } else {
            ListNode *curr = lists[minindex];
            lists[minindex] = lists[minindex]->next;
            curr->next = mergeKLists(lists);
            return curr;
        }
    }
};