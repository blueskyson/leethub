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
    bool traverse(TreeNode* node, int& result) {
        if (node->left == nullptr && node->right == nullptr) {
            return true;
        }

        if (node->left) {
            bool is_leaf = traverse(node->left, result);
            if (is_leaf) {
                result += node->left->val;
            }
        }
        if (node->right) {
            traverse(node->right, result);
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int result = 0;
        traverse(root, result);
        return result;
    }
};