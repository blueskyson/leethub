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
    class cmp {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        }
    };

    void traverse(TreeNode* node, unordered_map<int, int>& map) {
        if (!node) {
            return;
        }
        
        map[node->val]++;
        if (node->left) {
            traverse(node->left, map);
        }
        if (node->right) {
            traverse(node->right, map);
        }
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        traverse(root, map);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        vector<int> result;
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            q.push(*it);
        }

        int mode_count = q.top().second;
        while (!q.empty()) {
            if (q.top().second < mode_count) {
                break;
            }
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
    }
};
