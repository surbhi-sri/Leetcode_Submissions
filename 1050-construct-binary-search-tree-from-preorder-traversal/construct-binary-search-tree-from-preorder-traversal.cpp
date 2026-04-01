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
    TreeNode* construct(vector<int>& pre, int& idx, int mn, int mx) {
        if (idx >= pre.size())
            return NULL;
        int key = pre[idx];

        if (key <= mn || key >= mx)
            return NULL;

        TreeNode* root = new TreeNode(key);
        idx++;

        root->left = construct(pre, idx, mn, key);
        root->right = construct(pre, idx, key, mx);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return construct(preorder, idx, 0, 1001);
    }
};