class Solution {
public:
    int findLength(vector<int>& x, vector<int>& y) {
        int n = x.size();
        int m = y.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                mx = max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};