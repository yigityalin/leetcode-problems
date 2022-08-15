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
    int helper(bool &balanced, TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            int left = helper(balanced, root->left);
            int right = helper(balanced, root->right);
            if (abs(left - right) > 1) {
                balanced = false;
            }
            return 1 + max(left, right);
        }
    }
    
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        helper(balanced, root);
        return balanced;
    }
};