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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1, total = 1;
        double sum = 0;
        while (!q.empty()) {
            TreeNode *curr = q.front(); q.pop(); level--;
            sum += curr->val;
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
            if (level == 0) {
                averages.push_back(sum / total);
                sum = 0;
                total = q.size();
                level = total;
            }
        }
        return averages;
    }
};