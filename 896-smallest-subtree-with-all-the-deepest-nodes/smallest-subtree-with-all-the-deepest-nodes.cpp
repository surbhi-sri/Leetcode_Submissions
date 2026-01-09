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
    unordered_map<TreeNode*, int> mp;
    int maxd = 0;

    TreeNode* lca(TreeNode* root) {
        if (!root || mp[root] == maxd)
            return root;

        TreeNode* l = lca(root->left);
        TreeNode* r = lca(root->right);

        if (l && r)
            return root;
        else if (l)
            return l;
        else
            return r;
    }

    void depth(TreeNode* root, int level) {
        if (!root)
            return;

        mp[root] = level;
        maxd = max(maxd, level);

        depth(root->left, level + 1);
        depth(root->right, level + 1);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root, 0);

        return lca(root);
    }
};