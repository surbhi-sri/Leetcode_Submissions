class Solution {

private:
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis,
             int tin[], int low[], vector<vector<int>>& bridge) {
        ////////////////////////////////////////////////////////////////////////////

        vis[node] = 1;
        low[node] = tin[node] = timer;

        timer++;

        for (auto it : adj[node]) {
            if (vis[it] == 0) {
                dfs(it, node, adj, vis, tin, low, bridge);
                if(it!=parent)
                low[node] = min(low[node], low[it]);
                if (tin[node] < low[it])
                bridge.push_back({node, it});

            } else {
                if(it!=parent)
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int tin[n];
        int low[n];

        vector<vector<int>> bridge;

        dfs(0, -1, adj, vis, tin, low, bridge);

        return bridge;
    }
};