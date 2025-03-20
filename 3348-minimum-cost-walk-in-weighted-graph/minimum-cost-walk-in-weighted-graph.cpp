class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unions(int x, int y) { parent[y] = x; };

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {

        parent.resize(n);
        vector<int> cost(n, -1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                unions(parent_u, parent_v);
                cost[parent_u] &= cost[parent_v];
            }

            cost[parent_u] &= wt;
        }
        vector<int> res;

        for (auto& q : query) {
            int s = q[0];
            int r = q[1];

            int parent_s = find(s);
            int parent_r = find(r);

            if (s == r)
                res.push_back(0);
            else if (parent_s != parent_r)
                res.push_back(-1);
            else
                res.push_back(cost[parent_r]);
        }

        return res;
    }
};