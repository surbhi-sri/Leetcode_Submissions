class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);

        for (auto &road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});
        vector<long long> time(n+1, LLONG_MAX);
        vector<int> ways(n+1, 0);

        time[0] = 0;
        ways[0]=1;

        int mod = (int)(1e9+7);

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long times = it.first;
            int node = it.second;

            for (auto &it : adj[node]) {
                int adN = it.first;
                long long adt = it.second;

                if (adt + times < time[adN]) {
                    ways[adN] = ways[node];
                    time[adN] = adt + times;
                    pq.push({time[adN], adN});
                } else if (adt + times == time[adN]) {
                    ways[adN] = (ways[adN] + ways[node])%mod;
                }
            }
        }

        return ways[n - 1];
    }
};