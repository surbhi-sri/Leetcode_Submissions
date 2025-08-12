int mod = 1e9 + 7;

class Solution {
public:
    int solve(long long n, int ind, int x, vector<vector<int>>& dp) {
        if (n == 0)
            return 1;

        if (n < 0)
            return 0;

        if (dp[n][ind] != -1)
            return dp[n][ind];

        long long temp = pow(ind, x);

        if (temp > n)
            return dp[n][ind] = 0;

        int take = (solve(n - temp, ind + 1, x, dp)) % mod;
        int skip = (solve(n, ind + 1, x, dp)) % mod;

        return dp[n][ind] = (take + skip) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        return solve(n, 1, x, dp);
    }
};