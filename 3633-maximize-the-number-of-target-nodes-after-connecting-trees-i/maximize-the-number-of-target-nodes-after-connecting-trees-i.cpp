class Solution {
public:
    int bfs(int curr, vector<vector<int>>& adj, int k, int n) {
        queue<pair<int, int>> q;
        q.push({curr, 0});
        vector<bool> vis(n);
        vis[curr] = 1;
        int cnt = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            if (d > k)
                continue;

            cnt++;

            for(auto &it:adj[node]){
                if(!vis[it]){
                 vis[it]=1;   
                q.push({it, d+1});
                }
            }
        }
        
        return cnt;
    }

    vector<int> findCount(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);

        for (int i = 0; i < n; i++)
            res[i] = bfs(i, adj, k, n);

        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        vector<int> res1 = findCount(edges1, k);
        vector<int> res2 = findCount(edges2, k - 1);

        int maxCnt = *max_element(begin(res2), end(res2));

        for (int i = 0; i < res1.size(); i++)
            res1[i] += maxCnt;

        return res1;
    }
};