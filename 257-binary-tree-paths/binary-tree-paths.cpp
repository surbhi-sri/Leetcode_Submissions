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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        stack<pair<TreeNode*, string>> st;
        st.push({root, to_string(root->val)});

        while (!st.empty()) {
            TreeNode* node = st.top().first;
            string path = st.top().second;
            st.pop();

            if (!node->right && !node->left) {
                ans.push_back(path);
            }

            if (node->right) {
                string right_path = path + "->" + to_string(node->right->val);
                st.push({node->right, right_path});
            }

            if (node->left) {
                string left_path = path + "->" + to_string(node->left->val);
                st.push({node->left, left_path});
            }
        }

        return ans;
    }
};