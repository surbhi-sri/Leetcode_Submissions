class Solution {
public:
    int change(int sum, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long int>> dp(n + 1,
                                         vector<long long int>(sum + 1, 0));
        for (long long int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (long long int i = 1; i <= n; i++) {
            for (long long int j = 0; j <= sum; j++) {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};