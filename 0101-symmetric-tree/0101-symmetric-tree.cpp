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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int count = q.size();
            for (int i = 0, j = count - 1; i <= j; i++, j--) {
                if (q[i] == nullptr && q[j] == nullptr) {
                    continue;
                }
                if (q[i] != nullptr && q[j] != nullptr && q[i]->val == q[j]->val) {
                    continue;
                }
                return false;
            }
            for (int i = 0; i < count; i++) {
                TreeNode *node = q.front();
                if (node != nullptr) {
                    q.push_back(node->left);
                    q.push_back(node->right);
                }
                q.pop_front();
            }
        }
        return true;
    }
};