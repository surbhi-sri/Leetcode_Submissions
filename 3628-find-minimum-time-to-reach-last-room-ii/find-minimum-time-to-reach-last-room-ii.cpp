class Solution {
public:
    typedef pair<int, pair<int, int>> ppi;

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

        res[0][0] = 0;
        pq.push({0, {0, 0}});

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};


        while (!pq.empty()) {
            int time = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if (r == n - 1 && c == m - 1)
                return time;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newtime = max(0, (moveTime[nr][nc] - time)) + time;
                    if ((nr + nc) % 2 == 0)
                        newtime += 2;
                    else
                        newtime += 1;

                    if (newtime < res[nr][nc]) {
                        res[nr][nc] = newtime;
                        pq.push({newtime, {nr, nc}});
                    }
                }
            }
        }

        return res[n - 1][m - 1];
    }
};