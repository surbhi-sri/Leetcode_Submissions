class Solution {
public:
    int lcs(int n, int m, string& x, string& y) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int nlcs = lcs(n, m, word1, word2);
        return (n + m - 2 * nlcs);
    }
};