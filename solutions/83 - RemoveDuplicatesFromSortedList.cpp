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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *last = head, *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            while (curr && last->val == curr->val) {
                ListNode *tmp = curr;
                curr = curr->next;
                delete tmp;
            }
            last->next = curr;
            last = last->next;
        }
        return head;
    }
};