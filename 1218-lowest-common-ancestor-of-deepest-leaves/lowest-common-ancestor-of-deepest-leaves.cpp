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
    pair<int, TreeNode*> LCA(TreeNode* root) {
        if (root == NULL)
            return {0, root};

        if (root->left == NULL && root->right == NULL)
            return {1, root};

        pair<int, TreeNode*> l = LCA(root->left);
        pair<int, TreeNode*> r = LCA(root->right);

        if (l.first > r.first)
            return {l.first + 1, l.second};

        else if (l.first < r.first)
            return {r.first + 1, r.second};

        return {l.first+1, root};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pair<int, TreeNode*> lca = LCA(root);

        return lca.second;
    }
};