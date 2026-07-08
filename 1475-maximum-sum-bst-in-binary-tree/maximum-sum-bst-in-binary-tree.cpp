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

int ans=0;

      pair<pair<int, int>, int> mBST(TreeNode *root){
      if(root==NULL) return {{INT_MAX, INT_MIN} , 0};
      
       
        auto  left=mBST(root->left);
        auto  right= mBST(root->right);
       
       if(left.first.second >= root->val || right.first.first <=root-> val)
       return {{INT_MIN, INT_MAX},0};
       
       int sum=left.second+right.second+root->val; 
       ans=max(sum, ans);

      return {{min(left.first.first, root->val), max(right.first.second, root->val)}, sum};

}

    int maxSumBST(TreeNode* root) {

       mBST(root).second;
        return ans;
    }
};