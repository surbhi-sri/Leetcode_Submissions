class Solution {
public:
    int n, m;
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size();
        m = grid[0].size();
        int k = queries.size();

        vector<pair<int, int>> sorted_q;

        for (int i = 0; i < k; i++)
            sorted_q.push_back({queries[i], i});

        sort(begin(sorted_q), end(sorted_q));

        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        vector<int> ans(k, 0);

        int points = 0;

        for (int i = 0; i < k; i++) {
            int val = sorted_q[i].first;
            int idx = sorted_q[i].second;

            while (!pq.empty() && pq.top()[0] < val) {
                int i = pq.top()[1];
                int j = pq.top()[2];

                pq.pop();
                points++;

                for (int k = 0; k < 4; k++) {
                    int r = i + dr[k];
                    int c = j + dc[k];
                    if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c]) {

                        vis[r][c] = 1;
                        pq.push({grid[r][c], r, c});
                    }
                }
            }

            ans[idx]=points;
        }

        return ans;
    }
};