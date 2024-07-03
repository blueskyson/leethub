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
    TreeNode* traverse(TreeNode* node, int key) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->val > key) {
            node->left = traverse(node->left, key);
            return node;
        }
        if (node->val < key) {
            node->right = traverse(node->right, key);
            return node;
        }
        
        TreeNode *ret_node;
        if (node->left == nullptr && node->right == nullptr) {
            ret_node = nullptr;
        } else if (node->left != nullptr && node->right == nullptr) {
            ret_node = node->left;
        } else if (node->left == nullptr && node->right != nullptr) {
            ret_node = node->right;
        } else {
            TreeNode *cur = node->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            cur->left = node->left;
            ret_node = node->right;
        }
        delete node;
        return ret_node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traverse(root, key);
    }
};