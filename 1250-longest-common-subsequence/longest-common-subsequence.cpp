class Solution {
public:
    int lcs(string& x, string& y, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (x[n - 1] == y[m - 1])
            return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);
        else
            return dp[n][m] =
                       max(lcs(x, y, n - 1, m, dp), lcs(x, y, n, m - 1, dp));
    }

    int longestCommonSubsequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcs(str1, str2, n, m, dp);
    }
};