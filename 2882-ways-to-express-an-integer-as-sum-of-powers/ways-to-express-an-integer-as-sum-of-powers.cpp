int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int n, int x) {

        vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));

        for (int ind = 0; ind <= n + 1; ind++)
            dp[ind][0] = 1;

        for (int ind = n; ind >= 1; ind--) {
            long long temp = pow(ind, x);

            for (int sum = n; sum >= 0; sum--) {
                int take = 0;

                if (sum >= temp)
                    take = dp[ind + 1][sum - temp];
                int skip = dp[ind + 1][sum];

                dp[ind][sum] = (take + skip) % mod;
            }
        }

        return dp[1][n];
    }
};