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
    int findSecondMinimumValue(TreeNode* root) {
        int minvalue = INT_MAX;
        bool updated = false;
        helper(root, minvalue, root->val, updated);
        if (updated) {
            return minvalue;
        } else {
            return -1;
        }
    }
    
    void helper(TreeNode *node, int &minvalue, const int &rootvalue, bool &updated) {
        if (node) {
            if (rootvalue < node->val) {
                updated = true;
                minvalue = min(minvalue, node->val);
            }
            helper(node->left, minvalue, rootvalue, updated);
            helper(node->right, minvalue, rootvalue, updated);
        }
    }
};