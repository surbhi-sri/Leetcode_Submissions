class Solution {
public:
     const int mod = INT_MAX;

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<long>> dp(n, vector<long>(amount + 1, 0));

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {

                long  notTake = dp[i - 1][j];

                long  take = 0;

                if (j >= coins[i])
                    take = dp[i][j - coins[i]];

                dp[i][j] = (take + notTake) % mod;
            }
        }

        return dp[n - 1][amount];
    }
};