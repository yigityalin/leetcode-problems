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
    int maxAncestorDiff(TreeNode* root) {
        int maxdiff = 0;
        helper(root, root->val, root->val, maxdiff);
        return maxdiff;
    }
    
    void helper(TreeNode* root, int minvalue, int maxvalue, int &maxdiff) {
        if (root) {
            minvalue = min(minvalue, root->val);
            maxvalue = max(maxvalue, root->val);
            maxdiff = max(maxdiff, maxvalue - minvalue);
            helper(root->left, minvalue, maxvalue, maxdiff);
            helper(root->right, minvalue, maxvalue, maxdiff);
        }
    }
};