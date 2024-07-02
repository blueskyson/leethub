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
    int getMaxIndex(const vector<int>& nums) {
        int max = INT32_MIN, maxIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    TreeNode* traverse(vector<int>& nums) {
        if (nums.empty())
            return nullptr;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        int maxIndex = getMaxIndex(nums);
        TreeNode *root = new TreeNode(nums[maxIndex]);
        vector<int> leftNums(nums.begin(), nums.begin() + maxIndex);
        vector<int> rightNums(nums.begin() + maxIndex + 1, nums.end());
        root->left = traverse(leftNums);
        root->right = traverse(rightNums);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traverse(nums);
    }
};