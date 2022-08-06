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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list;
        for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
            list.push_back(curr->val);
        }
        return helper(list, 0, list.size());
    }
    
    TreeNode* helper(vector<int>& nums, const int &left, const int &right) {
        if (left == right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid);
        node->right = helper(nums, mid + 1, right);
        return node;
    }
};