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
    void PrintPath(vector<string>& ans,
                   unordered_map<TreeNode*, TreeNode*>& parent,
                   TreeNode* node) {
        stack<TreeNode*> st;
        string path;

        while (node) {
            st.push(node);
            node = parent[node];
        }

        path = to_string(st.top()->val);
        st.pop();

        while (!st.empty()) {
            path = path + "->" + to_string(st.top()->val);
            st.pop();
        }
        
        ans.push_back(path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        stack<TreeNode*> st;
        unordered_map<TreeNode*, TreeNode*> parent;
        parent[root] = NULL;

        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (!node->right && !node->left) {
                PrintPath(ans, parent, node);
            }

            if (node->right) {
                parent[node->right] = node;
                st.push(node->right);
            }

            if (node->left) {
                parent[node->left] = node;
                st.push(node->left);
            }
        }

        return ans;
    }
};