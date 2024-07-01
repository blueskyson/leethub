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
    void traverse(TreeNode *node, int &count) {
        count++;
        if (node->left) {
            traverse(node->left, count);
        }
        if (node->right) {
            traverse(node->right, count);
        }
    }
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int count = 0;
        traverse(root, count);
        return count;
    }
};