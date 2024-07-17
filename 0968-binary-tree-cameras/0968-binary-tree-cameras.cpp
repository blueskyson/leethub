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
    const int UNCOVERED = 0, HAS_CAM = 1, COVERED = 2;

    int traverse(TreeNode *node, int& camCount) {
        if (!node) {
            return COVERED;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return UNCOVERED;
        }
        
        int leftSide = traverse(node->left, camCount);
        int rightSide = traverse(node->right, camCount);
        if (leftSide == COVERED && rightSide == COVERED) {
            return UNCOVERED;
        }
        
        if (leftSide == UNCOVERED || rightSide == UNCOVERED) {
            camCount++;
            return HAS_CAM;
        }
        
        if (leftSide == HAS_CAM || rightSide == HAS_CAM) {
            return COVERED;
        }

        return -1;    
    }

    int minCameraCover(TreeNode* root) {
        int camCount = 0;
        if (traverse(root, camCount) == UNCOVERED) { // root is not covered
            camCount++;
        }
        return camCount;
    }
};