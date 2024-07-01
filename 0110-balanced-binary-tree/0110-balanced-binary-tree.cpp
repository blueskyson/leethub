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

#define max(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int traverse(TreeNode *node, bool &result) {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int leftHeight = 0, rightHeight = 0;
        if (node->left) {
            leftHeight = traverse(node->left, result);
        }
        if (node->right) {
            rightHeight = traverse(node->right, result);
        }
        if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) {
            result = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool result = true;
        traverse(root, result);
        return result;
    }
};