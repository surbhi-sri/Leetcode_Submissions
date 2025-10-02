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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        queue<pair<TreeNode*, pair<int, int>>> q;
        int mid = (s + e) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        q.push({root, {s, e}});

        while (!q.empty()) {
            TreeNode *curr=q.front().first;
            int s=q.front().second.first;
            int e=q.front().second.second;
            q.pop();
            
            int ind = (s + e) / 2;

            if(s<ind){
              mid= (s + ind-1) / 2;
              TreeNode *left = new TreeNode(nums[mid]);
              curr->left=left;
              q.push({left, {s, ind-1}});
            }

            if(ind<e){
              mid= (e + ind+1) / 2;
              TreeNode *right = new TreeNode(nums[mid]);
              curr->right=right;
              q.push({right, {ind+1, e}});
            }

        }

        return root;
    }
};