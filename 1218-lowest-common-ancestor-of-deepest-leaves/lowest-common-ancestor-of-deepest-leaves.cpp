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
    unordered_map<int, int> mp;
    int maxD = 0;

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || mp[root->val] == maxD)
            return root;

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if(l==NULL) return r;
        if(r==NULL) return l;
        
        return root;
    }

    void depth(TreeNode* root, int dis) {
        if (!root)
            return;

        maxD = max(maxD, dis);
        mp[root->val] = dis;
        depth(root->left, dis + 1);
        depth(root->right, dis + 1);
        return;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};