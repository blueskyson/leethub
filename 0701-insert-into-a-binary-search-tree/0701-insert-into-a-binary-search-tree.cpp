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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (!root) {
            return node;
        }

        TreeNode *cur = root, *prev = nullptr;
        while (cur) {
            prev = cur;
            if (cur->val > val) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        
        if (prev->val > val) {
            prev->left = node;
        } else {
            prev->right = node;
        }
        return root;
    }
};