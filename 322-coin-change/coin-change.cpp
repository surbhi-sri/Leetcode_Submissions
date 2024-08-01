class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = INT_MAX - 1;
                else if (j < coins[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[n][sum] == INT_MAX - 1 ? -1 : dp[n][sum];
    }
};