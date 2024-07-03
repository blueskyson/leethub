/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *traverse(TreeNode *node, TreeNode *p, TreeNode *q) {
        if (node == nullptr)
            return nullptr;
        if (node->val > p->val && node->val > q->val) {
            TreeNode *left = traverse(node->left, p, q);
            if (left != nullptr) {
                return left;
            }
        }
        if (node->val < p->val && node->val < q->val) {
            TreeNode *right = traverse(node->right, p, q);
            if (right != nullptr) {
                return right;
            }
        }
        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root, p, q);
    }
};