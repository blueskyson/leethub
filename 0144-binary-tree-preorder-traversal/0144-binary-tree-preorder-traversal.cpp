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
    void traverse(TreeNode* node, vector<int>& result) {
        result.push_back(node->val);
        if (node->left) {
            traverse(node->left, result);
        }
        if (node->right) {
            traverse(node->right, result);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root) {
            traverse(root, result);
        }
        return result;
    }
};