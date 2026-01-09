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
    pair<int, TreeNode*> lca(TreeNode* root) {
        if (!root)
            return {0, root};

        if (root->left == NULL && root->right == NULL)
            return {1, root};

        auto l = lca(root->left);
        auto r = lca(root->right);

        if (l.first == r.first)
            return {l.first + 1, root};

        else if (l.first > r.first)
            return {l.first + 1, l.second};

        else
            return {r.first + 1, r.second};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) { return lca(root).second; }
};