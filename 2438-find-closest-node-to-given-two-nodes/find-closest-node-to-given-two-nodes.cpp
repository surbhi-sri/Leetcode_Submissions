class Solution {
public:
    void bfs(vector<int>& edges, int node, vector<int>& dis) {
        queue<int> q;
        q.push(node);
        dis[node] = 0;
        int n = edges.size();
        vector<bool> vis(n, 0);
        vis[node] = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            int it = edges[curr];

            if (it != -1 && !vis[it]) {
                vis[it] = 1;

                dis[it] = 1 + dis[curr];
                q.push(it);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);

        bfs(edges, node1, dis1);
        bfs(edges, node2, dis2);

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