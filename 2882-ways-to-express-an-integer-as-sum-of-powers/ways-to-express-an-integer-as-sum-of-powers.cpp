int mod = 1e9 + 7;

class Solution {
public:
    int numberOfWays(int n, int x) {

        vector<int> dp(n + 1, 0);

            dp[0] = 1;

        for (int ind = 1; ind <=n; ind++) {
            long long temp = pow(ind, x);

            for (int sum = n; sum >= 0; sum--) {
                int take = 0;

                if (sum >= temp)
                    dp[sum] = (dp[sum] + dp[sum - temp]) % mod;
            }
        }

        return dp[n];
    }
};