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
    void helper(TreeNode *&head, TreeNode *root) {
        if (root) {
            helper(head, root->left);
            root->left = nullptr;
            head->right = root;
            head = root;
            helper(head, root->right);
        }
    }
        
    TreeNode* increasingBST(TreeNode* root) {
        auto *dummy = new TreeNode(), *head = dummy;
        helper(head, root);
        return dummy->right;
    }
};