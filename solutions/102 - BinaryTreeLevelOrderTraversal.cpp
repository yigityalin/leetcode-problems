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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> levelOrder = {{}};
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            TreeNode *curr = q.front(); q.pop(); level--;
            levelOrder[levelOrder.size() - 1].push_back(curr->val);
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
            if (level == 0) {
                level = q.size();
                levelOrder.push_back(vector<int>());
            }
        }
        levelOrder.pop_back();
        return levelOrder;
    }
};