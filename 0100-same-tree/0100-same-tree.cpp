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
    bool compare(TreeNode* tree1, TreeNode* tree2) {
        if (tree1 == NULL && tree2 != NULL) return false;
        else if (tree1 != NULL && tree2 == NULL) return false;
        else if (tree1 == NULL && tree2 == NULL) return true;
        else if (tree1->val != tree2->val) return false;

        bool compareLeft = compare(tree1->left, tree2->left);
        bool compareRight = compare(tree1->right, tree2->right);
        bool isSame = compareLeft && compareRight;
        return isSame;

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};