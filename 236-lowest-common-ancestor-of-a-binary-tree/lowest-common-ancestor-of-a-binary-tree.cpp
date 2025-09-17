/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode* root, TreeNode* node, vector<TreeNode*>& paths) {
        if (!root)
            return 0;

        paths.push_back(root);

        if (root == node || path(root->left, node, paths) ||
            path(root->right, node, paths))
            return 1;

        paths.pop_back();
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;
        path(root, p, path1);
        path(root, q, path2);

        int n = min(path1.size(), path2.size());

        TreeNode* lca = path1[n - 1];
        for (int i = 0; i < n; i++) {
            if (path1[i] != path2[i]) {
                lca = path1[i - 1];
                break;
            }
        }

        return lca;
    }
};