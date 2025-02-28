class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[j] = grid[i][j];
                else if (i == 0)
                    dp[j] = dp[j - 1] + grid[i][j];
                else if (j == 0)
                    dp[j] += grid[i][j];
                else
                   dp[j]=min(dp[j], dp[j-1])+grid[i][j];
            }
        }

        return dp[m - 1];
    }
};