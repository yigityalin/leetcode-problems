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
    bool helper(ListNode *&left, ListNode *right) {
        if (right == nullptr) {
            return true;
        } else {
            bool next = helper(left, right->next);
            bool equal = left->val == right->val;
            left = left->next;
            return next && equal;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        return helper(head, head);
    }
};