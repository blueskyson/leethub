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
    void traverse(TreeNode *node, int& previousVal) {
        if (node == nullptr) {
            return;
        }
        
        traverse(node->right, previousVal);
        node->val += previousVal;
        previousVal = node->val;
        traverse(node->left, previousVal);
    }
    TreeNode* convertBST(TreeNode* root) {
        int previousVal = 0;
        traverse(root, previousVal);
        return root;
    }
};