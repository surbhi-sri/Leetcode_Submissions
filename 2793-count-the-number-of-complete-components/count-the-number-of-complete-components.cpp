class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, int &v, int &e) {
        vis[node] = 1;
        v++;
       
        for (auto it : adj[node]) {
            e++;
            if (!vis[it]) {
                dfs(it, adj, vis, v, e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edges : edges) {

            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }

        vector<bool> vis(n, 0);
        int res = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int v = 0;
                int e = 0;
                dfs(i, adj, vis, v, e);
                if (v * (v - 1) == e)
                    res++;
            }
        }

        return res;
    }
};