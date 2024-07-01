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
    vector<string> traverse(TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            return { to_string(node->val) };
        }

        vector<string> paths;
        if (node->left) {
            vector<string> v = traverse(node->left);
            paths.insert(paths.end(), v.begin(), v.end());
        }
        if (node->right) {
            vector<string> v = traverse(node->right);
            paths.insert(paths.end(), v.begin(), v.end());
        }
        
        string valStr = to_string(node->val);
        for (int i = 0; i < paths.size(); i++) {
            paths[i] = valStr + "->" + paths[i];
        }
        return paths;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return {};
        }
        return traverse(root);
    }
};
