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
    TreeNode* traverse(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) {
            return nullptr;
        }
        
        TreeNode *node = new TreeNode(0);
        TreeNode *left1 = nullptr, *left2 = nullptr, *right1 = nullptr, *right2 = nullptr;
        if (node1) {
            node->val += node1->val;
            left1 = node1->left;
            right1 = node1->right;
        }
        if (node2) {
            node->val += node2->val;
            left2 = node2->left;
            right2 = node2->right;
        }

        node->left = traverse(left1, left2);
        node->right = traverse(right1, right2);
        return node;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return traverse(root1, root2);
    }
};