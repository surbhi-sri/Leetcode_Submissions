class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, int pos, int parent,
            vector<int>& col) {
        int cnt = (pos % 2 == 0);
        col[node] = pos % 2;

        for (auto& it : adj[node]) {
            if (it != parent)
                cnt += dfs(it, adj, pos + 1, node, col);
        }

        return cnt;
    }

    vector<int> findCnt(vector<vector<int>>& edges, vector<int>& col) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int res = dfs(0, adj, 0, -1, col);

        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<int> col1(n);
        vector<int> col2(m);

        vector<int> cnt1 = findCnt(edges1, col1); // {o cnt, 1 cnt}
        vector<int> cnt2 = findCnt(edges2, col2);
        vector<int> res(n);

        for (int i = 0; i < n; i++)
            res[i] = cnt1[col1[i]] + max(cnt2[0], cnt2[1]);

        return res;
    }
};