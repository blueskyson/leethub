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
    void traverse(TreeNode *node, vector<int>& vec) {
        if (node->left) {
            traverse(node->left, vec);
        }
        vec.push_back(node->val);
        if (node->right) {
            traverse(node->right, vec);
        }
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        if (v.size() == 1) {
            return true;
        }

        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= v[i - 1]) {
                return false;
            }
        }
        return true;
    }
};