int mod = 1e9 + 7;

class Solution {
public:
    int solve(long long sum, int ind, int n, int x, vector<vector<int>>& dp) {
        if (sum > n)
            return 0;

        if (sum == n)
            return 1;

        if (ind > n)
            return 0;

        if (dp[sum][ind] != -1)
            return dp[sum][ind];

        long long temp = pow(ind, x);

        if (temp > n)
            return dp[sum][ind] = 0;

        int take = (solve(sum + temp, ind + 1, n, x, dp)) % mod;
        int skip = (solve(sum, ind + 1, n, x, dp)) % mod;

        return dp[sum][ind] = (take + skip) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        return solve(0, 1, n, x, dp);
    }
};