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
    int *traverse(TreeNode *node) {
        // 0: don't stole, 1: do stole
        int *result = new int[2];
        result[0] = 0;
        result[1] = 0;
        if (node == nullptr) {
            return result;
        }
        
        int *left = traverse(node->left);
        int *right = traverse(node->right);
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        result[1] = node->val + left[0] + right[0];
        delete[] left;
        delete[] right;
        return result;
    }
    int rob(TreeNode* root) {
        int *result = traverse(root);
        int ans = max(result[0], result[1]);
        delete[] result;
        return ans;
    }
};