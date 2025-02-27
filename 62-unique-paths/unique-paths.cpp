class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i + 1, j, m, n, dp);
        int bottom = solve(i, j + 1, m, n, dp);
        return dp[i][j] = (right + bottom);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int i = 0, j = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = 1;
                else {
                    int bottom = (i + 1 < m) ? dp[i + 1][j] : 0;
                    int right = (j + 1 < n) ? dp[i][j + 1] : 0;
                    dp[i][j] = bottom + right;
                }
            }
        }
        return dp[0][0];
    }
};