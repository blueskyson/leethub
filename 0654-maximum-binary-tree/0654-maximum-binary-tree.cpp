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
    int getMaxIndex(const vector<int>& nums, int left, int right) {
        int max = INT32_MIN, maxIndex = -1;
        for (int i = left; i < right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    TreeNode* traverse(vector<int>& nums, int left, int right) {
        if (right - left == 0)
            return nullptr;
        if (right - left == 1)
            return new TreeNode(nums[left]);

        int maxIndex = getMaxIndex(nums, left, right);
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = traverse(nums, left, maxIndex);
        root->right = traverse(nums, maxIndex + 1, right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums, 0, nums.size());
    }
};