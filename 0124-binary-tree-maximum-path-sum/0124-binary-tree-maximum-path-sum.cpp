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
    int recurse(int &max_path, TreeNode* root) {
        if (!root) {
            return 0;
        }
        int left_opt = recurse(max_path, root->left);
        int right_opt = recurse(max_path, root->right);
        int opt_path = max({root->val,
                            root->val + left_opt,
                            root->val + right_opt});
        max_path = max({max_path, opt_path, root->val + left_opt + right_opt});
        return opt_path;
    }
    
    int maxPathSum(TreeNode* root) {

        
        int max_path = INT32_MIN;
        recurse(max_path, root);
        return max_path;
    }
};