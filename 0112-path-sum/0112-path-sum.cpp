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
    bool traverse(TreeNode *node, int sum, const int& target) {
        int newSum = sum + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return newSum == target;
        }
        
        bool leftResult, rightResult;
        if (node->left) {
            leftResult = traverse(node->left, newSum, target);
        }
        if (node->right) {
            rightResult = traverse(node->right, newSum, target);
        }
        
        return (leftResult == true || rightResult == true);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        return traverse(root, 0, targetSum);
    }
};