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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<TreeNode*> queue1, queue2;
        queue1.push_back(p);
        queue2.push_back(q);
        while(!queue1.empty() && !queue2.empty() && queue1.size() == queue2.size()) {
            for (int i = 0; i < queue1.size(); i++) {
                TreeNode* node1 = queue1.front();
                TreeNode* node2 = queue2.front();
                bool isSame = true;
                if (node1 == nullptr) {
                    if (node2 != nullptr) {
                        return false;
                    }
                } else if (node2 == nullptr) {
                    if (node1 != nullptr) {
                        return false;
                    }
                } else if (node1->val != node2->val){
                    return false;
                }

                if (node1) {
                    queue1.push_back(node1->left);
                    queue1.push_back(node1->right);
                }
                if (node2) {
                    queue2.push_back(node2->left);
                    queue2.push_back(node2->right);
                }
                queue1.pop_front();
                queue2.pop_front();
            }
        }
        return queue1.size() == 0 && queue2.size() == 0 ? true : false;
    }
};
