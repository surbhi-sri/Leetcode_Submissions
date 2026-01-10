class Solution {
public:
    int solve(string& x, string& y, int n, int m, vector<vector<int>>& dp) {
        if (n < 0) {
            int sum = 0;
            for (int i = 0; i <= m; i++)
                sum += y[i];
            return sum;
        } else if (m < 0) {
            int sum = 0;
            for (int i = 0; i <= n; i++)
                sum += x[i];
            return sum;
        } else if (n < 0 && m < 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (x[n] != y[m])
            return dp[n][m] = min(x[n] + solve(x, y, n - 1, m, dp),
                                  y[m] + solve(x, y, n, m - 1, dp));
        else
            return dp[n][m] = solve(x, y, n - 1, m - 1, dp);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(s1, s2, n - 1, m - 1, dp);
    }
};