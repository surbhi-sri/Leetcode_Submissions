class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<int>& dis,
             vector<bool>& vis) {
        vis[node] = 1;

        int it = edges[node];

        if (it != -1 && !vis[it]) {
            vis[it] = 1;
            dis[it] = 1 + dis[node];
            dfs(edges, it, dis, vis);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);

        vector<bool> vis1(n, 0);
        vector<bool> vis2(n, 0);

        dis1[node1] = 0;
        dis2[node2] = 0;

        dfs(edges, node1, dis1, vis1);
        dfs(edges, node2, dis2, vis2);

        int minDisNode = -1;
        int minDisTillNow = INT_MAX;

        for (int i = 0; i < n; i++) {

            int maxD = max(dis1[i], dis2[i]);

            if (minDisTillNow > maxD) {
                minDisTillNow = maxD;
                minDisNode = i;
            }
        }

        return minDisNode;
    }
};