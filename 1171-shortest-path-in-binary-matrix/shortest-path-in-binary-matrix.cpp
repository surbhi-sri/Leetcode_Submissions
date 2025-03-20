class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> vis(n, vector<int>(n, -1));

        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int step = vis[r][c];

            if (r == n - 1 && c == n - 1)
                return step;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0)
                        continue;
                    int nr = r + i;
                    int nc = c + j;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        grid[nr][nc] == 0 && vis[nr][nc]==-1) {
                        vis[nr][nc] = step + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};