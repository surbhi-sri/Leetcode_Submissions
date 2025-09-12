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
    
    int solve(TreeNode* root, int &mx){
         if(!root) return 0;

         int l=solve(root->left, mx);
         int r=solve(root->right, mx);

         mx=max(mx, l+r+1);

         return max(l,r)+1;
    }
 
    int diameterOfBinaryTree(TreeNode* root) {
        int mx=1;
        solve(root, mx);

        return mx-1;
    }
};