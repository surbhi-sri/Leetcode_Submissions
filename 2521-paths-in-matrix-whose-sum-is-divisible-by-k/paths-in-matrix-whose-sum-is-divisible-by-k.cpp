class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(m+1, vector<int>(k, 0)));

        for (int rem = 0; rem < k; rem++)
            dp[n - 1][m - 1][rem] = (grid[n - 1][m - 1] + rem) % k == 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1)
                    continue;

                for (int rem = 0; rem < k; rem++) {

                    int r = (rem + grid[i][j]) % k;
                    dp[i][j][rem] = (dp[i + 1][j][r] + dp[i][j + 1][r]) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};