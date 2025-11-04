class Solution {
public:
    int row, col;

    void dfs(vector<vector<int>>& grid, int r, int c, int dir) {
        if (r < 0 || c < 0 || r >= row || c >= col || grid[r][c] == -1 ||
            grid[r][c] == 1)
            return;

      if(grid[r][c]==0)  grid[r][c] = 2;

        if (dir == 1)
            dfs(grid, r - 1, c, 1);
        else if (dir == 2)
            dfs(grid, r, c + 1, 2);
        else if (dir == 3)
            dfs(grid, r + 1, c, 3);
        else if (dir == 4)
            dfs(grid, r, c - 1, 4);
        else
            return;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        row = m;
        col = n;

        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (vector<int>& g : guards) {
            grid[g[0]][g[1]] = 1;
        }

        for (vector<int>& w : walls) {
            grid[w[0]][w[1]] = -1;
        }

        for (vector<int>& g : guards) {
            int i = g[0];
            int j = g[1];
            if (grid[i][j] == 1) {
                dfs(grid, i-1, j, 1);
                dfs(grid, i, j+1, 2);
                dfs(grid, i+1, j, 3);
                dfs(grid, i, j-1, 4);
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    cnt++;
            }
        }

        return cnt;
    }
};