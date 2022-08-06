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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
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