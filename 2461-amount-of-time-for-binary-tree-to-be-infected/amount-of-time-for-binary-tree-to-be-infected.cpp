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
    void makegraph(unordered_map<int, vector<int>>& adj, TreeNode* root,
                   int parent) {
        if (root == NULL)
            return;

        if (parent != -1)
            adj[root->val].push_back(parent);

        if (root->left)
            adj[root->val].push_back(root->left->val);
        if (root->right)
            adj[root->val].push_back(root->right->val);

        makegraph(adj, root->left, root->val);
        makegraph(adj, root->right, root->val);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        makegraph(adj, root, -1);

        if (adj[start].size() == 0)
            return 0;

        queue<int> q;
        unordered_set<int> vis;

        vis.insert(start);
        q.push(start);
        int time = 0;

        while (!q.empty()) {
            time++;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                int node = q.front();
                q.pop();

                for (int& it : adj[node]) {
                    if (vis.count(it) == 0) {
                        q.push(it);
                        vis.insert(it);
                    }
                }
            }
        }

        return time-1;
    }
};