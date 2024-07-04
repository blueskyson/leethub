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
    TreeNode* traverse(vector<int>& nums, int left, int right) {
        if (right - left <= 0) {
            return nullptr;
        }
        
        int middle = (right + left) / 2;
        TreeNode *node = new TreeNode(nums[middle]);
        node->left = traverse(nums, left, middle);
        node->right = traverse(nums, middle + 1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse(nums, 0, nums.size());
    }
};