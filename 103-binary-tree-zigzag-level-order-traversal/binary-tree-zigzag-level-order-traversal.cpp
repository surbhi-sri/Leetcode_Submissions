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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st1;
        st1.push(root);
        bool rev = 0;

        while (!st1.empty()) {
            vector<int> temp;
            int n = st1.size();
            stack<TreeNode*> st2;

            for (int i = 0; i < n; i++) {
                TreeNode* node = st1.top();
                st1.pop();
                temp.push_back(node->val);

                if (!rev) {
                    if (node->left)
                        st2.push(node->left);
                    if (node->right)
                        st2.push(node->right);
                } else {
                    if (node->right)
                        st2.push(node->right);
                    if (node->left)
                        st2.push(node->left);
                }
            }
           
            st1=st2;
            ans.push_back(temp);
            rev = !rev;
        }
        return ans;
    }
};