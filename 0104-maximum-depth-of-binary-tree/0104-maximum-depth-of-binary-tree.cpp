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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        deque<TreeNode*> q;
        q.push_back(root);
        int depth = 0;
        while(!q.empty()) {
            depth += 1;
            int count = q.size();
            for (int i = 0; i < count; i++) {
                TreeNode *node = q.front();
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
                q.pop_front();
            }
        }
        return depth;
    }
};