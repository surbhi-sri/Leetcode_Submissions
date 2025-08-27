class Solution {
public:
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int n, m;

    int solve(int i, int j, int d, bool canTurn, int val,
              vector<vector<int>>& grid) {

        int i_ = i + dir[d][0];
        int j_ = j + dir[d][1];

        if (i_ < 0 || j_ < 0 || i_ >= n || j_ >= m || grid[i_][j_] != val)
            return 0;

        int keepMoving = 1 + solve(i_, j_, d, canTurn, val == 2 ? 0 : 2, grid);

        if (canTurn)
            keepMoving = max(keepMoving, 1 + solve(i_, j_, (d + 1) % 4, 0,
                                                   val == 2 ? 0 : 2, grid));

        return keepMoving;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++)
                        res = max(res, 1 + solve(i, j, d, 1, 2, grid));
                }
            }
        }

        return res;
    }
};