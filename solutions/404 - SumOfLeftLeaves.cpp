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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false);
        return sum;
    }
    
    void helper(TreeNode* root, int &sum, bool left) {
        if (root) {
            if (left && !root->left && !root->right) {
                sum += root->val;
            }
            helper(root->left, sum, true);
            helper(root->right, sum, false);
        }
    }
};