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
    void helper(int i, ListNode *head, vector<int> &pairSums, const int &n) {
        if (head) {
            if (i < n / 2) pairSums.push_back(head->val);
            else           pairSums[n - i - 1] += head->val;
            helper(i + 1, head->next, pairSums, n);
        }
    }
    
    int pairSum(ListNode* head) {
        ListNode *curr = head; int n = 0;
        while (curr) {n++; curr = curr->next;}
        vector<int> pairSums;
        helper(0, head, pairSums, n);
        return *max_element(pairSums.begin(), pairSums.end());
    }
};