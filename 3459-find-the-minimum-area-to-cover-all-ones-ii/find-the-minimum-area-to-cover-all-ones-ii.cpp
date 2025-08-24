class Solution {
public:
    int minimumArea(int r0, int r1, int c0, int c1, vector<vector<int>>& grid) {
        int mnr = INT_MAX, mnc = INT_MAX;
        int mxr = -1, mxc = -1;

        for (int i = r0; i < r1; i++) {
            for (int j = c0; j < c1; j++) {
                if (grid[i][j] == 1) {
                    mnr = min(i, mnr);
                    mnc = min(j, mnc);
                    mxr = max(i, mxr);
                    mxc = max(j, mxc);
                }
            }
        }

        return (mxr == -1 || mxc == -1) ? 0 : (mxr - mnr + 1) * (mxc - mnc + 1);
    }

    vector<vector<int>> traverse(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                t[j][i] = grid[i][j];
            }
        }
        return t;
    }

    int solve(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = n * m;

        for (int r = 1; r < n; r++) {
            for (int c = 1; c < m; c++) {
                res = min(res, minimumArea(0, r, 0, m, grid) +
                                   minimumArea(r, n, 0, c, grid) +
                                   minimumArea(r, n, c, m, grid));

                res = min(res, minimumArea(0, r, 0, c, grid) +
                                   minimumArea(0, r, c, m, grid) +
                                   minimumArea(r, n, 0, m, grid));
            }
        }

        for (int i = 1; i + 1 < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = min(res, minimumArea(0, i, 0, m, grid) +
                                   minimumArea(i, j, 0, m, grid) +
                                   minimumArea(j, n, 0, m, grid));
            }
        }

        return res;
    }

    int minimumSum(vector<vector<int>>& grid) {

        vector<vector<int>> rgrid = traverse(grid);

        return min(solve(grid), solve(rgrid));
    }
};