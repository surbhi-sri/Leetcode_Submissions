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
    int mod = 1e9 + 7;

    int summation(TreeNode* root) {
        if (!root)
            return 0;

        int left = summation(root->left);
        int right = summation(root->right);

        return left + right + root->val;
    }

    int solve(TreeNode* root, int total, long long& ans) {
        if (!root)
            return 0;

        long long val = 0;
        long long left = solve(root->left, total, ans);
        val = left * (total - left);
        ans = max(val, ans);

        long long right = solve(root->right, total, ans);
        val = right * (total - right);
        ans = max(val, ans);

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        //   unordered_map<TreeNode*, int> mp;
        int total_sum = summation(root);
        long long ans = 0;

        solve(root, total_sum, ans);

        return ans % mod;
    }
};