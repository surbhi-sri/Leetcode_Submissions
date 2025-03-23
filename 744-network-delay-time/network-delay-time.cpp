class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});
        vector<int> time(n + 1, INT_MAX);

        time[k] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            long long t = it.first;
            int node = it.second;

            if (t > time[node])
                continue;

            for (auto& it : adj[node]) {
                int adN = it.first;
                long long adt = it.second;

                if (adt + t < time[adN]) {
                    time[adN] = adt + t;
                    pq.push({time[adN], adN});
                }
            }
        }

        int maxTime = *max_element(time.begin() + 1, time.end());
        return (maxTime == INT_MAX) ? -1 : maxTime;
    }
};