class Solution {
public:
    void lca(string& x, string& y, int n, int m, vector<vector<int>>& dp) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string shortestCommonSupersequence(string x, string y) {
        int n = x.size();
        int m = y.size();
        if (n == 0)
            return y;
        if (m == 0)
            return x;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        lca(x, y, n, m, dp);
        string s = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (x[i - 1] == y[j - 1]) {
                s += x[i - 1];
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        reverse(s.begin(), s.end());
        int num = s.size();
        string ans = "";
        i = 0, j = 0;
        int k = 0;
        while (k < num) {
            while (x[i] != s[k]) {
                ans += x[i];
                i++;
            }
            while (y[j] != s[k]) {
                ans += y[j];
                j++;
            }
            while (k < num && x[i] == s[k] && y[j] == s[k]) {
                ans += s[k];
                i++;
                j++;
                k++;
            }
        }
        while (i < n) {
            ans += x[i];
            i++;
        }
        while (j < m) {
            ans += y[j];
            j++;
        }
        return ans;
    }
};