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
    TreeNode* traverse(TreeNode* node, int low, int high) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left) {
            node->left = traverse(node->left, low, high);
        }
        if (node->right) {
            node->right = traverse(node->right, low, high);
        }

        if (node->val < low) {
            TreeNode *ret_node = node->right;
            return ret_node;
        } else if (node->val >= low && node->val <= high) {
            return node;
        } else {
            TreeNode *ret_node = node->left;
            return ret_node;
        }
        
        return nullptr;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traverse(root, low, high);
    }
};