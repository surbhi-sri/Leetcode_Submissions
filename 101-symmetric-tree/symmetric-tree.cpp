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
    bool isSymmetric(TreeNode* root) {
       stack<TreeNode*> st1, st2;

       st1.push(root->left);
       st2.push(root->right);

       while(!st1.empty() && !st2.empty()){
         TreeNode*  p=st1.top();
         TreeNode*  q=st2.top();
           
           st1.pop();
           st2.pop();

           if(!p && !q) continue;

           if(!p || !q || p->val!=q->val)  return 0;

           st1.push(p->left);
           st1.push(p->right);
          
           st2.push(q->right);
           st2.push(q->left);
       }
 
       return st1.empty() && st2.empty();

    }
};