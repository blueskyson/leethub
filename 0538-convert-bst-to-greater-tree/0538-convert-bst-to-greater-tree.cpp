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
    int traverse(TreeNode *node, int lastSum) {
        if (node == nullptr) {
            return 0;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            node->val = node->val + lastSum;
            return node->val;
        }
        
        if (node->left != nullptr && node->right == nullptr) {
            node->val = node->val + lastSum;
            return traverse(node->left, node->val);
        }
        
        if (node->left == nullptr && node->right != nullptr) {
            int rightResult = traverse(node->right, lastSum);
            node->val += rightResult;
            return node->val;
        }
        
        int rightResult = traverse(node->right, lastSum);
        node->val += rightResult;
        return traverse(node->left, node->val);
    }
    TreeNode* convertBST(TreeNode* root) {
        traverse(root, 0);
        return root;
    }
};