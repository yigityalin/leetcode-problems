class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *left = head, *right = head;
        while (right && right->next) {
            left = left->next;
            right = right->next->next;
        }
        return left;
    }
};