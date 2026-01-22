/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int sum) {
        if (root->left == NULL && root->right == NULL) {
            return targetSum == (sum + root->val);
        }

        return ((root->left) ? solve(root->left, targetSum, sum + root->val)
                             : 0) |
               ((root->right) ? solve(root->right, targetSum, sum + root->val)
                              : 0);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        return solve(root, targetSum, 0);
    }
};