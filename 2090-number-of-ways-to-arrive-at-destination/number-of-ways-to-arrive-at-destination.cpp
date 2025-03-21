class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);

        for (auto &it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        // time, node;
        pq.push({0, 0});

         vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);
        time[0] = 0;
        ways[0] = 1;

        int mod=(int)(1e9+7);

        while (!pq.empty()) {
            long long times = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &it : adj[node]) {
                int adN = it.first;
                long long adT = it.second;

                if (times + adT < time[adN]) {
                    time[adN] = times + adT;
                    ways[adN] = ways[node];
                    pq.push({time[adN], adN});
                } else if (times + adT == time[adN]) {
                    ways[adN] =(ways[adN] + ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};